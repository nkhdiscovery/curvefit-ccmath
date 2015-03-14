#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "pplsq.h"
#include "GraphUtils.h"


//#define TEST_SIZE 200
#define TIME_STAMP 2 //just for graphing
//#define POLY_DEGREE 4
#define cosd(x) (cos(fmod((x),360) * M_PI / 180))
double f(double x, double* coefficients, int degree)
{
    double y = 0; 
    for(int i = 0 ; i < degree ; i++)
    {
        y += coefficients[i] * pow(x,i);
    }
    return y;
}

int main()
{
    srand(time(NULL));
    int POLY_DEGREE = 0, TEST_SIZE = 100; 
    printf("Enter degree: ");
    scanf("%d",&POLY_DEGREE);
    printf("Enter TEST_SIZE: ");
    scanf("%d",&TEST_SIZE);
    double dataArray[TEST_SIZE] = {0}; //Real points we wanna fit into
    double time[TEST_SIZE] = {0};
    double fittedPoints[TEST_SIZE] = {0}; //Fitted points, just for graphing
    double coefficients[4] = {0}; //These will be the calculated coefficients
    for(int i=0 ; i < TEST_SIZE ; i++) //Some samples... 
    {
        dataArray[i] = cosd(i) + 0.3*( ((rand() % 10) / 100.0) -0.1);
        time[i] = i;
    }
    double sq = pplsq(time, dataArray, TEST_SIZE, coefficients, POLY_DEGREE); //fit and return squared residual
    for(int i=0 ; i < TEST_SIZE ; i++)
    {
        fittedPoints[i] = f(i, coefficients, POLY_DEGREE);
    }

    char graphLabel[128]; 
    sprintf(graphLabel, "Fit with degree %d, squared residual is %f", POLY_DEGREE, sq);
    IplImage *graphImg = drawFloatGraph(fittedPoints, TEST_SIZE, NULL,
                -2,2, (TIME_STAMP*TEST_SIZE), 680, graphLabel ); //main graph image
    drawFloatGraph(dataArray, TEST_SIZE , graphImg, -2,2, (TIME_STAMP*TEST_SIZE), 680);
    showImage(graphImg, 0, "Fitted Curve");

    return 0 ; 
}
