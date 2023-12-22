#include <iostream>

using namespace std;

#include "weather.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #3. osadki\n";
    cout << "Author: Sharendo Liudmila\n";
    weather* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {

            cout << subscriptions[i]->weather_date.day << ' ';
            cout << subscriptions[i]->weather_date.month << ' ';
            cout << subscriptions[i]->weather_volume << ' ';
            cout << subscriptions[i]->weather_type << ' ';
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
