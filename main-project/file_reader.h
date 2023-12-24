#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "weather.h"

void read(const char* file_name, weather* array[], int& size);//чтение данных из файла и помещение их в массив, обновляется размер

#endif
