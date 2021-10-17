#include "object_list.h"

bool object_list::trace_ray(const ray& r, float t_min, float t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    float closest_so_far = t_max;

    for (int i = 0; i < list_size; i++) {
        if (list[i]->hit_object(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
            rec.object_index = i;
        }
    }
    return hit_anything;
}
