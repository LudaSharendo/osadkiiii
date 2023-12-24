#include <iostream>
#include <iomanip>
using namespace std;
#include "weather.h"
#include "file_reader.h"
#include "constants.h"
#include "Filter.h"
#include "processing.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #3. osadki\n";
    cout << "Author: Sharendo Liudmila\n";
    cout << "Group: 23_Ping\n";
    weather* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** Осадки *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод даты **********/
            cout << "Дата : ";
            // вывод числа
            cout << setw(2) << setfill('0') << subscriptions[i]->weather_date.day << '-';
            // вывод месяца
            cout << setw(2) << setfill('0') << subscriptions[i]->weather_date.month << " ";
            cout << "Объем : ";
            /********** вывод объема **********/
            cout << subscriptions[i]->weather_volume << " ";
            cout << "Вид осадков : ";
            /********** вывод вида осадков **********/
            cout << subscriptions[i]->weather_type << " ";
            cout << '\n';
        }

    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    bool rpts = true;
    int rpts_value = 0;
    while (rpts == true)
    {
        cout << "Что вы хотите сделать? " << endl << "1. Когда был дождь? " << endl << "2. Когда объем осадков был < 1.5 ";
        cout << endl << "3. Шейкерную сортировку " << endl << "4. Быструю сортировку " << endl << "5. Exit " << endl << "6. Количество осадков в месяц" << endl;

        cin >> rpts_value;
        switch (rpts_value)
        {
        case 1: only_rain(subscriptions, size);
            break;
        case 2:low_volume(subscriptions, size);
            break;
        case 3:
        {
            cout << "Что вы хотите отсортировать?" << endl << "1. объем осадков    2. даты";
            int sort_id;
            cin >> sort_id;
            ShakerSort(subscriptions, size, sort_id);
            break;
        }

        case 4:
        {
            cout << "Что вы хотите отсортировать?" << endl << "1. объем осадков    2. даты";
            int sort_id;
            cin >> sort_id;
            quickSort(subscriptions, 0, size - 1, sort_id, size);
            for (int i = 0; i < size; i++)
            {
                cout << subscriptions[i]->weather_date.day << "  ";
                cout << subscriptions[i]->weather_date.month << "  ";
                cout << subscriptions[i]->weather_volume << "  ";
                cout << subscriptions[i]->weather_type << "  ";
                cout << '\n';
            }
            break;
        }
        case 5:
        {
            rpts = false;
            break;
        }


        
             case 6:
             {
                 int month;
                 cout << " введите месяц, который вы хотите рассчитать " << endl;
                 cin >> month;
                 monthly_weather(subscriptions, size, month);

             }
    }
}
        for (int i = 0; i < size; i++)
        {

            delete subscriptions[i];
        }
    return 0;
}
