#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

// Структура для хранения информации о запчастях
struct Magazin 
{
    string name;     
    string marka;    
    string model;    
    string stoimost; 
};

Magazin zap[100]; // Массив для хранения информации о запчастях всего 100 элементов
int count = 0;    // Счётчик 

// Функция для вывода заголовка таблицы
void printTableHeader() 
{
    // Форматированный вывод заголовков колонок с выравниванием по левому краю
    cout << left << setw(5) << "№"
         << setw(33) << "Наименование"
         << setw(20) << "Марка"
         << setw(19) << "Модель"
         << setw(10) << "Стоимость" << endl;
    cout << string(65, '-') << endl; // Линия разделителя для отделения заголовка от данных
}

// Функция для вывода строки таблицы с информацией о запчасти
void printTableRow(int index, const Magazin& part) 
{
    // Форматированный вывод данных о запчасти с выравниванием по левому краю
    cout << left << setw(5) << index + 1
         << setw(20) << part.name
         << setw(15) << part.marka
         << setw(15) << part.model
         << setw(10) << part.stoimost << endl;
}

int main() 
{
    int choice; // Переменная для хранения выбора пользователя

    do 
    {
        // Вывод меню
        cout << "\n1. Список запчастей\n";
        cout << "2. Добавить запчасть\n";
        cout << "3. Удалить запчасть\n";
        cout << "4. Запчасти для Lada Vesta\n";
        cout << "5. Выход\n";
        cout << "Введите выбор: ";
        cin >> choice; 

        if (choice == 1) 
        {
            if (count > 0) // Проверка, есть ли хотя бы одна запчасть
            {
                cout << "Список запчастей:\n";
                printTableHeader(); // Вывод заголовка таблицы
                for (int i = 0; i < count; i++) // Цикл по всем запчастям
                {
                    printTableRow(i, zap[i]); // Вывод данных о запчасти в виде строки таблицы
                }
            } 
            else 
            {
                cout << "Список запчастей пуст.\n"; 
            }
        }
        else if (choice == 2)
        {
            if (count < 100) // проверка лимита массива 
            {
                // Ввод данных о запчасти
                cout << "Введите наименование запчасти: ";
                cin >> zap[count].name;
                cout << "Введите марку: ";
                cin >> zap[count].marka;
                cout << "Введите модель: ";
                cin >> zap[count].model;
                cout << "Введите стоимость: ";
                cin >> zap[count].stoimost;
                count++; 
            } 
            else 
            {
                cout << "Невозможно добавить больше запчастей.\n"; 
            }
        }
        else if (choice == 3) 
        {
            int index; // Переменная для хранения номера запчасти
            cout << "Введите номер запчасти для удаления: ";
            cin >> index;
            index--; // Уменьшение индекса на 1, так как массив начинается с 0

            if (index >= 0 && index < count) // Проверка корректности индекса
            {
                // Сдвиг элементов массива влево для удаления элемента
                for (int i = index; i < count - 1; i++) 
                {
                    zap[i] = zap[i + 1];
                }
                count--; // 
            } 
            else 
            {
                cout << "Неверный номер.\n"; 
            }
        }
        else if (choice == 4) 
        {
            cout << "Запчасти для Lada Vesta:\n";
            bool found = false; // Флаг для отслеживания наличия запчастей для Lada Vesta
            printTableHeader(); // Вывод заголовка таблицы
            for (int i = 0; i < count; i++) 
            {
                if (zap[i].marka == "Lada" && zap[i].model == "Vesta") 
                {
                    printTableRow(i, zap[i]); // Вывод данных о найденной запчасти
                    found = true; // Установка флага в true, если запчасть найдена
                }
            }
            if (!found) // Если не было найдено ни одной запчасти
            {
                cout << "Нет запчастей для Lada Vesta.\n"; // Сообщение об отсутствии запчастей
            }
        }
    } while (choice != 5); // Повторять цикл, пока не выбран пункт 5 (выход)

    return 0; // Завершение программы
}