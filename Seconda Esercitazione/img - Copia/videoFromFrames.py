import cv2
import numpy as np
import glob
 
img_array = []
for i in range(360):
	img = cv2.imread(str(i) + ".bmp")
	height, width, layers = img.shape
	size = (width,height)
	img_array.append(img)


out = cv2.VideoWriter('project.avi',cv2.VideoWriter_fourcc(*'DIVX'), 8, size)
 
for i in range(len(img_array)):
    out.write(img_array[i])
out.release()