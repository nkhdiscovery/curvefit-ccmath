#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "pplsq.h"
#include "GraphUtils.h"


#define TEST_SIZE 700
#define TIME_STAMP 1
#define cosd(x) (cos(fmod((x),360) * M_PI / 180))

int main()
{
    srand(time(NULL));
    float *floatArray = new float[TEST_SIZE];
    float predictedPoints[TEST_SIZE+100] = {0};
    for(int i=0 ; i<TEST_SIZE ; i++) 
    {
        floatArray[i] = cosd(i) + 0.3*( ((rand() % 10)/10.0) -0.1);
    }
    for(int i=0 ; i<100 ; i++)
    {
        predictedPoints[TEST_SIZE+i] = cosd(TEST_SIZE+i);
    }

    IplImage *graphImg = drawFloatGraph(predictedPoints, TEST_SIZE+100, NULL,
                -2,2, TIME_STAMP*(TEST_SIZE+100) ,680, "X Angle" );

    drawFloatGraph(floatArray, TEST_SIZE , graphImg, -2,2, (TIME_STAMP*TEST_SIZE),680);
    showImage(graphImg, 0, "sample graph");

//    showFloatGraph("Rotation Angle", floatArray, TEST_SIZE, 0);
    return 0 ; 
}
