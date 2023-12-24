#include "file_reader.h"
#include "constants.h"
#include <fstream>
#include <cstring>
#include <iostream>
date convert(char* str) //��������� ������������� ���� � ������
{
    date result; //���������� ����������
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context); // ��������� ������� ������ �� ������ `str` �� ����������� "."
    result.day = atoi(str_number); // �������������� ���������� ��������� � ����� ����� � ���������� � ���� "day"
    str_number = strtok_s(NULL, " ", &context); // ��������� ���������� ������ �� ������ `str` �� ����������� " "
    result.month = atoi(str_number);  // �������������� ���������� ��������� � ����� ����� � ���������� � ���� "month"
    return result;
}
void read(const char* file_name, weather* array[], int& size)
{    // ��������� ���� 
    std::ifstream file(file_name);
    if (file.is_open())
    { //������ �������
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        // ������ ������ �� ����� ���� �� ��������� ����� �����
        while (!file.eof())
        {  // �������� ������ ��� ����� ������
            weather* item = new weather;
            // ������ ���� � ��������� � �������
            file >> tmp_buffer;
            item->weather_date = convert(tmp_buffer);
            // ������ ����� ������� � ��������� � �������
            file >> item->weather_volume;
            file.read(tmp_buffer, 1); // ������ ������� ������� �������
            // ��������� ��� ������ � ��������� � �������
            file.getline(item->weather_type, MAX_STRING_SIZE);
            // ��������� ������ � ������ � ����������� ������
            array[size++] = item;
        }
           
        
        file.close();
    }
    else
    {
        throw "������ �������� �����";
    }
}

