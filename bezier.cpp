#include "bezier.h"

float * bezier(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int resolution){

	float h;

	float * array = new float[resolution * 2];

	for(unsigned int i = 0; i < resolution - 1; i++){

		h = (float) i / (float) resolution;

		float x11 = h*(x2 - x1) + x1;
		float y11 = h*(y2 - y1) + y1;

		float x22 = h*(x3 - x2) + x2;
		float y22 = h*(y3 - y2) + y2;

		float x = h*(x22 - x11) + x11;
		float y = h*(y22 - y11) + y11;

		array[2*i] = x;
		array[2*i + 1] = y;
	}

	array[2*(resolution - 1)] = x3;
	array[2*(resolution - 1) + 1] = y3;

	return array;

}
