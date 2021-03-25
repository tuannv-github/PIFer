#ifndef _UTILS_H_
#define _UTILS_H_

#include <vector>
#include <string>

using namespace std;

typedef struct location
{
    float x;
    float y;
    float z;
}location_t;

typedef struct sphere
{
    float x;
    float y;
    float z;
    float r;
}sphere_t;

typedef struct trilateration_result{
    location_t PA;
    location_t PB;
}trilateration_result_t;

vector<string> split(string s, string delimiter);
void trilaterate(sphere_t sphere[3], trilateration_result_t *trilateration_result);

#endif