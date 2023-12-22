#include <iostream>
#include <iomanip>
using namespace std;

#include "weather.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #3. osadki\n";
    cout << "Author: Sharendo Liudmila\n";
    weather* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** Осадки *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод даты **********/
            cout << "Дата .....: ";
            // вывод числа
            cout << setw(2) << setfill('0') << subscriptions[i]->weather_date.day << '-';
            // вывод месяца
            cout << setw(2) << setfill('0') << subscriptions[i]->weather_date.month;
            cout << "Объем.....: ";
            /********** вывод объема **********/
            cout << subscriptions[i]->weather_volume << " ";
            cout << "Вид осадков.....: ";
            /********** вывод вида осадков **********/
            cout << subscriptions[i]->weather_type << " ";
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
