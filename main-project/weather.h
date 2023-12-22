#ifndef WEATHER_H
#define WEATHER_H

#include "constants.h"

struct date
{
    int day;
    int month;
};

struct wheather
{
    float volume;
    char wheather_type[MAX_STRING_SIZE];
    date data;
};
#endif
