#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/processing.h"
#include "../main-project/weather.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(unittestproject)//проводит тест
{
public:
    TEST_METHOD(TestMethod1)

    {
        int testSize = 2;
        weather** testSubscriptions = new weather * [testSize];

        // Подготовка тестовых данных
        testSubscriptions[0] = new weather{ {10, 3}, 100.0, "Type1" };
   
        testSubscriptions[1] = new weather{ {3, 5}, 150.0, "Type2" };
      
        // Тестирование для определенного месяца
        int testMonth = 5;

        // Расчет ожидаемой суммы на основе тестовых данных
        float expectedSum = 150.0;

        // Вызов функции для получения результата
        float result = monthly_weather(testSubscriptions, testSize, testMonth);

        // Проверка результата с использованием утверждения
        Assert::AreEqual(expectedSum, result, L"Расчет ежемесячных осадков неверен.");

        // Очистка динамически выделенной памяти
        for (int i = 0; i < testSize; i++)
        {
            delete testSubscriptions[i];
        }
        delete[] testSubscriptions;
    }
};
       TEST_CLASS(unittestproject2)
       {
       public:
           TEST_METHOD(TestMethod2)//

           {
               int testSize = 4;
               weather** testSubscriptions = new weather * [testSize];

               // Подготовка тестовых данных
               testSubscriptions[0] = new weather{ {10, 8}, 125.0, "Type1" };

               testSubscriptions[1] = new weather{ {3, 8}, 33.0, "Type2" };
               testSubscriptions[2] = new weather{ {10, 6}, 62.0, "Type3" };

               testSubscriptions[3] = new weather{ {3, 4}, 88.0, "Type4" };

               // Тестирование для определенного месяца
               int testMonth = 8;

               // Расчет ожидаемой суммы на основе тестовых данных
               float expectedSum = 158.0;

               // Вызов функции для получения результата
               float result = monthly_weather(testSubscriptions, testSize, testMonth);

               // Проверка результата с использованием утверждения
               Assert::AreEqual(expectedSum, result, L"Расчет ежемесячных осадков неверен.");

               // Очистка динамически выделенной памяти
               for (int i = 0; i < testSize; i++)
               {
                   delete testSubscriptions[i];
               }
               delete[] testSubscriptions;
           }
       };
       TEST_CLASS(unittestproject3)
       {
       public:
           TEST_METHOD(TestMethod3)//

           {
               int testSize = 10;
               weather** testSubscriptions = new weather * [testSize];

               // Подготовка тестовых данных
               testSubscriptions[0] = new weather{ {10, 4}, 0.08, "Type1" };

               testSubscriptions[1] = new weather{ {9, 4}, 0.03, "Type2" };
               testSubscriptions[2] = new weather{ {10, 4}, 0.02, "Type3" };

               testSubscriptions[3] = new weather{ {2, 4}, 0.01, "Type4" };
               testSubscriptions[4] = new weather{ {10, 1}, 0.11, "Type5" };

               testSubscriptions[5] = new weather{ {3, 3}, 0.05, "Type6" };
               testSubscriptions[6] = new weather{ {10, 6}, 0.33, "Type7" };

               testSubscriptions[7] = new weather{ {3, 7}, 0.07, "Type8" };
               testSubscriptions[8] = new weather{ {16, 6}, 0.04, "Type9" };

               testSubscriptions[9] = new weather{ {3, 4}, 0.06, "Type10" };

               // Тестирование для определенного месяца
               int testMonth = 4;

               // Расчет ожидаемой суммы на основе тестовых данных
               float expectedSum = 0.2;

               // Вызов функции для получения результата
               float result = monthly_weather(testSubscriptions, testSize, testMonth);

               // Проверка результата с использованием утверждения
               Assert::AreEqual(expectedSum, result, L"Расчет ежемесячных осадков неверен.");

               // Очистка динамически выделенной памяти
               for (int i = 0; i < testSize; i++)
               {
                   delete testSubscriptions[i];
               }
               delete[] testSubscriptions;
           }
       };
       TEST_CLASS(unittestproject4)
       {
       public:
           TEST_METHOD(TestMethod4)//

           {
               int testSize = 3;
               weather** testSubscriptions = new weather * [testSize];

               // Подготовка тестовых данных
               testSubscriptions[0] = new weather{ {10, 6}, 2.0, "Type1" };

               testSubscriptions[1] = new weather{ {3, 8}, 3.0, "Type2" };
               testSubscriptions[2] = new weather{ {12, 6}, 4.0, "Type3" };

               // Тестирование для определенного месяца
               int testMonth = 6;

               // Расчет ожидаемой суммы на основе тестовых данных
               float expectedSum = 6.0;

               // Вызов функции для получения результата
               float result = monthly_weather(testSubscriptions, testSize, testMonth);

               // Проверка результата с использованием утверждения
               Assert::AreEqual(expectedSum, result, L"Расчет ежемесячных осадков неверен.");

               // Очистка динамически выделенной памяти
               for (int i = 0; i < testSize; i++)
               {
                   delete testSubscriptions[i];
               }
               delete[] testSubscriptions;
           }
       };