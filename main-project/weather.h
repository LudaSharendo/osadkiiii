#ifndef WEATHER_H
#define WEATHER_H

#include "constants.h"
//типы данных
struct date
{
    int day;
    int month;
};

struct weather
{
    date weather_date;
    float weather_volume;
    char weather_type[MAX_STRING_SIZE];
    
};
#endif
