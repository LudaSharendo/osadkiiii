#include "processing.h"

#include "weather.h"
#include <iostream>
using namespace std;

float monthly_weather(weather* subscriptions[], int size, int month)
{

	float sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (subscriptions[i]->weather_date.month == month)
		{
			sum += subscriptions[i]->weather_volume;
		}
	}
	cout << " общее количество осадков за  месяц: " << sum << endl;
	return sum;
}