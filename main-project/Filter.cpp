#include <iostream>

using namespace std;
#include "file_reader.h"
#include "constants.h"
#include "weather.h"
#include "Filter.h"

void print_data(weather* subscriptions[], int id)
//выводим данные о погоде из массива
{
    cout << subscriptions[id]->weather_date.day << "  ";
    cout << subscriptions[id]->weather_date.month << "  ";
    cout << subscriptions[id]->weather_volume << "  ";
    cout << subscriptions[id]->weather_type << "  ";
    cout << '\n';
}

void only_rain(weather* subscriptions[], int size)
//ищем строку содержащую rain 
{


    for (int i = 0; i < size; i++)
    {
        if (strstr(subscriptions[i]->weather_type, "rain") != NULL)
        {//вызывается функция для вывода
            print_data(subscriptions, i);
        }
    }
}

void low_volume(weather* subscriptions[], int size)
//ищем строку содержащую < 1.5
{
    for (int i = 0; i < size; i++)
    {
        if (subscriptions[i]->weather_volume < 1.5)
        {//вызывается функция для вывода
            print_data(subscriptions, i);
        }
    }
}
bool SortCase(int sort_id, weather* subscriptions[], int size, int id, int id2)
//определения критериев сортировки в зависимости от значения sort_id
{
    switch (sort_id)
    {
    case 1:
    {
        if (subscriptions[id]->weather_volume < subscriptions[id2]->weather_volume)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 2:
    {//функция преобразует даты в числовой формат и сравнивает их
        if ((subscriptions[id]->weather_date.day + subscriptions[id]->weather_date.month * 31) < (subscriptions[id2]->weather_date.day + subscriptions[id2]->weather_date.month * 31))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    }
}
//шейкерная сортировка
void ShakerSort(weather* subscriptions[], int size, int sort_id) {
    
    int i, j, k;
    int temp_size = size;
    for (i = 0; i < temp_size;) {
        for (j = i + 1; j < temp_size; j++) { //  от начала к концу
            if (SortCase(sort_id, subscriptions, size, j, j - 1))// Проверяем условие
                swap(subscriptions[j], subscriptions[j - 1]); // меняем местами элементы
        }
        temp_size--;
        for (k = temp_size - 1; k > i; k--) {
            if (SortCase(sort_id, subscriptions, size, k, k - 1))
                swap(subscriptions[k], subscriptions[k - 1]);
        }
        i++;
    }
    for (int d = 0; d < size; d++)
    {
        print_data(subscriptions, d); // Вызываем функцию для вывода информации о погоде
    }
}

int partition(weather* arr[], int low, int high, int sort_id, int size) {
    weather* pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (SortCase(sort_id, arr, size, j, high)) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

void quickSort(weather* arr[], int low, int high, int sort_id, int permament_size)
//быстрая сортировка
{
    if (low < high) {
        int p = partition(arr, low, high, sort_id, permament_size);
        quickSort(arr, low, p - 1, sort_id, permament_size);
        quickSort(arr, p + 1, high, sort_id, permament_size);
    }

}