#ifndef Filter_h
#define Filter_h
#include "weather.h"
void only_rain(weather* subscriptions[], int size); //������� ������������� ��� ���������� ������
void print_data(weather* subscriptions[], int id);//������� ��� ������ ������ � ������ � �������������� �������������� id
void low_volume(weather* subscriptions[], int size);
void ShakerSort(weather* subscriptions[], int size, int sort_id);
void quickSort(weather* subscriptions[], int start, int end, int sort_id, int size);

#endif