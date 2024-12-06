#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class SparePart {
private:  // Члены класса теперь private
    string name;    // Наименование запчасти
    string brand;   // Марка автомобиля
    string model;   // Модель автомобиля
    string cost;    // Стоимость запчасти

public:
    // Конструктор по умолчанию
    SparePart() : name("Неизвестно"), brand("Неизвестно"), model("Неизвестно"), cost("0") {}

    // Конструктор с тремя параметрами
    SparePart(const string& n, const string& b, const string& m) 
        : name(n), brand(b), model(m), cost("0") {}

    // Конструктор копирования
    SparePart(const SparePart& other) 
        : name(other.name), brand(other.brand), model(other.model), cost(other.cost) {}

    // Геттеры для доступа к членам класса
    string getName() const { return name; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    string getCost() const { return cost; }

    // Сеттеры для изменения членов класса
    void setName(const string& n) { name = n; }
    void setBrand(const string& b) { brand = b; }
    void setModel(const string& m) { model = m; }
    void setCost(const string& c) { cost = c; }
};

class Store {
private:
    static const int MAX_PARTS = 100;  // Максимальное количество запчастей
    SparePart parts[MAX_PARTS];        // Массив для хранения запчастей
    int count = 0;                     // Счётчик запчастей

public:
    // Метод для отображения меню
    void displayMenu() {
        int choice;
        do {
            cout << "\n1. Список запчастей\n";
            cout << "2. Добавить запчасть\n";
            cout << "3. Удалить запчасть\n";
            cout << "4. Запчасти для Lada Vesta\n";
            cout << "5. Выход\n";
            cout << "Введите выбор: ";
            cin >> choice;

            switch (choice) {
                case 1: listParts(); break;            // Показать список запчастей
                case 2: addPart(); break;              // Добавить новую запчасть
                case 3: deletePart(); break;           // Удалить запчасть
                case 4: listPartsForLadaVesta(); break;// Показать запчасти для Lada Vesta
                case 5: cout << "Выход из программы.\n"; break; // Завершение программы
                default: cout << "Некорректный ввод.\n"; break;
            }
        } while (choice != 5);  // Повторять, пока не выбран выход
    }

private:
    // Метод для отображения всех запчастей
    void listParts() {
        if (count > 0) {
            cout << "Список запчастей:\n";
            printTableHeader(); // Печать заголовка таблицы
            for (int i = 0; i < count; i++) {
                printTableRow(i, parts[i]); // Печать каждой строки таблицы
            }
        } else {
            cout << "Список запчастей пуст.\n";
        }
    }

    // Метод для добавления новой запчасти
    void addPart() {
        if (count < MAX_PARTS) {
            string name, brand, model, cost;
            cout << "Введите наименование запчасти: ";
            cin >> name;
            cout << "Введите марку: ";
            cin >> brand;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите стоимость: ";
            cin >> cost;

            // Используем конструктор с тремя параметрами и устанавливаем стоимость отдельно
            parts[count] = SparePart(name, brand, model);
            parts[count].setCost(cost);  // Используем сеттер для установки стоимости
            count++; // Увеличиваем счётчик запчастей

        } else {
            cout << "Невозможно добавить больше запчастей.\n";
        }
    }

    // Метод для удаления запчасти
    void deletePart() {
        int index;
        cout << "Введите номер запчасти для удаления: ";
        cin >> index;
        index--;

        if (index >= 0 && index < count) {
            // Сдвигаем элементы массива влево для удаления выбранной запчасти
            for (int i = index; i < count - 1; i++) {
                parts[i] = parts[i + 1];
            }
            count--; // Уменьшаем счётчик запчастей
            cout << "Запчасть удалена.\n";
        } else {
            cout << "Неверный номер.\n";
        }
    }

    // Метод для отображения запчастей для Lada Vesta
    void listPartsForLadaVesta() {
        cout << "Запчасти для Lada Vesta:\n";
        bool found = false; // Флаг для отслеживания наличия запчастей для Lada Vesta
        printTableHeader();
        for (int i = 0; i < count; i++) {
            if (parts[i].getBrand() == "Lada" && parts[i].getModel() == "Vesta") {
                printTableRow(i, parts[i]); // Печать найденной запчасти
                found = true;
            }
        }
        if (!found) {
            cout << "Нет запчастей для Lada Vesta.\n";
        }
    }

    // Метод для печати заголовка таблицы
    void printTableHeader() {
        cout << left << setw(5) << "№"
             << setw(33) << "Наименование"
             << setw(20) << "Марка"
             << setw(19) << "Модель"
             << setw(10) << "Стоимость" << endl;
        cout << string(65, '-') << endl;
    }

    // Метод для печати строки таблицы
    void printTableRow(int index, const SparePart& part) {
        cout << left << setw(5) << index + 1
             << setw(20) << part.getName()
             << setw(15) << part.getBrand()
             << setw(15) << part.getModel()
             << setw(10) << part.getCost() << endl;
    }
};

int main() {
    Store store;     // Создание объекта класса Store
    store.displayMenu(); // Вызов метода для отображения меню
    return 0;
}
