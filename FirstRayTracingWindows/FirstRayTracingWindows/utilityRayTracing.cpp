#include "utilityRayTracing.h"

using namespace std;
using namespace concurrency;

vec3 getColor(object_list* scene, ray& r, vec3& startColor, vec3& endColor, bool normalColor,float t_min, float t_max) {
    hit_record hit;
    if (scene->trace_ray(r, t_min, t_max, hit)) {
        if(normalColor) return 0.5f * (vec3(hit.normal.x, hit.normal.y, hit.normal.z) + vec3(1.0, 1.0, 1.0));
        return scene->list[hit.object_index]->color;
    }
    else {
        return colorLerpY(r, startColor, endColor);
    }
}

void updateRendererFromMatrix(int image_height, int image_width, SDL_Renderer*& renderer, vector<vec3>& matrix) {
    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            vec3 color = matrix[j * image_width + i];
            color = vec3(sqrt(color[0]), sqrt(color[1]), sqrt(color[2])); //GAMMA CORRECTION
            setColor(renderer, color.x, color.y, color.z);
            setPixel(renderer, i, j, image_height);
        }
    }
}

void renderFrameRandom(genericCamera& cam, int ns, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min, float t_max) {
    vector<vec3> matrix(image_width * image_height);
    parallel_for(int(0), image_height, [&](int j) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
            for (int s = 0; s < ns; s++) {
                ray r = cam.get_ray(float((i + randZeroToOne()) / image_width), float((j + randZeroToOne()) / image_height));
                color += getColor(scene, r, startBackgroundColor, endBackgroundColor, normalColor, t_min, t_max);
            }
            matrix[j * image_width + i] = color / float(ns);
        }
     });
    updateRendererFromMatrix(image_height, image_width, renderer, matrix);
}

void renderFrameJittered(genericCamera& cam, int numLayers, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min, float t_max) {
    vector<vec3> matrix(image_width * image_height);
    parallel_for(int(0), image_height, [&](int j) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
            for (int l1 = 0; l1 < numLayers; l1++) {
                for (int l2 = 0; l2 < numLayers; l2++) {
                    ray r = cam.get_ray(float((i + (randZeroToOne() + l1)/numLayers) / image_width), float((j + (randZeroToOne() + l2)/numLayers) / image_height));
                    color += getColor(scene, r, startBackgroundColor, endBackgroundColor, normalColor, t_min, t_max);
                }
            }
            matrix[j * image_width + i] = color / float(numLayers*numLayers);
        }
    });
    updateRendererFromMatrix(image_height, image_width, renderer, matrix);
}

void renderFrameNRooks(genericCamera& cam, int nRockSize, int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min, float t_max) {
    vector<int> rowIndices;
    vector<int> columnIndices;
    for( int k = 0; k < nRockSize; k++) {
        rowIndices.push_back(k);
        columnIndices.push_back(k);
    }
    vector<vec3> matrix(image_width * image_height);
    parallel_for(int(0), image_height, [&](int j) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
            std::random_device rd;
            std::default_random_engine rng(rd());
            std::shuffle(std::begin(rowIndices), std::end(rowIndices), rng);
            std::shuffle(std::begin(columnIndices), std::end(columnIndices), rng);
            for(int l = 0; l < nRockSize; l++) {
                float u = (float(i) + (randZeroToOne() + rowIndices[l]) / float(nRockSize)) / image_width;
                float v = (float(j) + (randZeroToOne() + columnIndices[l]) / float(nRockSize)) / image_height;
                ray r = cam.get_ray(u, v);
                color += getColor(scene, r, startBackgroundColor, endBackgroundColor, normalColor, t_min, t_max);
            }
            matrix[j * image_width + i] = color / float(nRockSize);
        }
    });
    updateRendererFromMatrix(image_height, image_width, renderer, matrix);
}

void renderFrameMultiJittered(genericCamera& cam, int nRockPerLayer ,int image_height, int image_width, SDL_Renderer*& renderer, object_list*& scene, vec3& startBackgroundColor, vec3& endBackgroundColor, bool normalColor, float t_min, float t_max) {
    std::vector<int> multiJitteredMatrix(nRockPerLayer* nRockPerLayer * 2);
    for(int i = 0; i < nRockPerLayer; i++) {
        int cont = 0;
        for(int j = 0; j < nRockPerLayer; j++) {
            if((i + j) < nRockPerLayer) {
                multiJitteredMatrix.at(nRockPerLayer * i + j) = i + j;
                multiJitteredMatrix.at(nRockPerLayer * i + j + nRockPerLayer * nRockPerLayer) = i + j;
            } else {
                multiJitteredMatrix.at(nRockPerLayer * i + j) = cont;
                multiJitteredMatrix.at(nRockPerLayer * i + j + nRockPerLayer * nRockPerLayer) = cont;
                cont++;
            }
        }
    }
    vector<int> rowIndices;
    vector<int> columnIndices;
    for( int k = 0; k < nRockPerLayer; k++) {
        rowIndices.push_back(k);
        columnIndices.push_back(k);
    }
    vector<vec3> matrix(image_width * image_height);
    parallel_for(int(0), image_height, [&](int j) {
        for (int i = 0; i < image_width; i++) {
            vec3 color(0.0, 0.0, 0.0);
            std::random_device rd;
            std::default_random_engine rng(rd());
            for(int k = 0; k < nRockPerLayer; k++) {
                std::shuffle(std::begin(rowIndices), std::end(rowIndices), rng);
                std::shuffle(std::begin(columnIndices), std::end(columnIndices), rng);
                for(int l = 0; l < nRockPerLayer; l++) {
                    multiJitteredMatrix.at(nRockPerLayer * k +  l) = rowIndices[l];
                    multiJitteredMatrix.at(nRockPerLayer * l + k + nRockPerLayer * nRockPerLayer) = columnIndices[l];
                }
            }             
            for(int k = 0; k < nRockPerLayer; k++) {
                for(int l = 0; l < nRockPerLayer; l++) {
                    float u = (i + l/float(nRockPerLayer) + (randZeroToOne() + multiJitteredMatrix.at(nRockPerLayer * k + l))/pow(nRockPerLayer, 2)) / image_width;
                    float v = (j + (nRockPerLayer - k)/float(nRockPerLayer) + (randZeroToOne() + multiJitteredMatrix.at(nRockPerLayer * k + l + nRockPerLayer * nRockPerLayer))/pow(nRockPerLayer, 2)) / image_height;
                    ray r = cam.get_ray(u, v);
                    color += getColor(scene, r, startBackgroundColor, endBackgroundColor, normalColor, t_min, t_max);
                }
            }
            matrix[j * image_width + i] = color / float(nRockPerLayer*nRockPerLayer);
        }
    });
    updateRendererFromMatrix(image_height, image_width, renderer, matrix);
}

bool saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer) {
    SDL_Surface* saveSurface = NULL;
    SDL_Surface* infoSurface = NULL;
    infoSurface = SDL_GetWindowSurface(SDLWindow);
    if (infoSurface == NULL) {
        cout << "Failed to create info surface from window in saveScreenshotBMP(string), SDL_GetError() - " << SDL_GetError() << "\n";
    }
    else {
        unsigned char* pixels = new (std::nothrow) unsigned char[infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel];
        if (pixels == 0) {
            cout << "Unable to allocate memory for screenshot pixel data buffer!\n";
            return false;
        }
        else {
            if (SDL_RenderReadPixels(SDLRenderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) != 0) {
               cout << "Failed to read pixel data from SDL_Renderer object. SDL_GetError() - " << SDL_GetError() << "\n";
                delete[] pixels;
                return false;
            }
            else {
                saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
                if (saveSurface == NULL) {
                    cout << "Couldn't create SDL_Surface from renderer pixel data. SDL_GetError() - " << SDL_GetError() << "\n";
                    delete[] pixels;
                    return false;
                }
                SDL_SaveBMP(saveSurface, filepath.c_str());
                SDL_FreeSurface(saveSurface);
                saveSurface = NULL;
            }
            delete[] pixels;
        }
        SDL_FreeSurface(infoSurface);
        infoSurface = NULL;
    }
    return true;
}
