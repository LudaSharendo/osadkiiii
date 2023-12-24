#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <cstring>
#include <iostream>
date convert(char* str) //строковое представление даты в объект
{
    date result; //объявление переменной
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context); // Выделение первого токена из строки `str` по разделителю "."
    result.day = atoi(str_number); // Преобразование выделенной подстроки в целое число и сохранение в поле "day"
    str_number = strtok_s(NULL, " ", &context); // Выделение следующего токена из строки `str` по разделителю " "
    result.month = atoi(str_number);  // Преобразование выделенной подстроки в целое число и сохранение в поле "month"
    return result;
}
void read(const char* file_name, weather* array[], int& size)
{    // Открываем файл 
    std::ifstream file(file_name);
    if (file.is_open())
    { //размер массива
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        // Читаем данные из файла пока не достигнем конца файла
        while (!file.eof())
        {  // Выделяем память под новый объект
            weather* item = new weather;
            // Читаем дату и сохраняем в объекте
            file >> tmp_buffer;
            item->weather_date = convert(tmp_buffer);
            // Читаем объем осадков и сохраняем в объекте
            file >> item->weather_volume;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            // Считываем вид погоды и сохраняем в объекте
            file.getline(item->weather_type, MAX_STRING_SIZE);
            // Добавляем объект в массив и увеличиваем размер
            array[size++] = item;
        }
           
        
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}

