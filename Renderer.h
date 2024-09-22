#include <iostream>


void initRenderer(int w, int h);

void releaseRenderer();

void renderFrame(uint8_t* frame, float t);

void drawPixel(uint8_t* result, float t);

void traceRay(float* origin, float* direction, float* color, int geneneration, int source);

void floorHit(float* origin, float* direction, float* color, int geneneration);

void sphereHit(float* origin, float* direction, float* color, int geneneration, float oppacity);