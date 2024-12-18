#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // Для управления кодировкой консоли


using namespace std;

class SparePart {
private:
    string name;    // Наименование запчасти
    string brand;   // Марка автомобиля
    string model;   // Модель автомобиля
    double cost;    // Стоимость запчасти (изменена на тип double для корректных вычислений)

public:
    // Конструктор по умолчанию
    SparePart() : name("Неизвестно"), brand("Неизвестно"), model("Неизвестно"), cost(0) {}

    // Конструктор с тремя параметрами
    SparePart(const string& n, const string& b, const string& m, double c = 0) 
        : name(n), brand(b), model(m), cost(c) {}

    // Конструктор копирования
    SparePart(const SparePart& other) 
        : name(other.name), brand(other.brand), model(other.model), cost(other.cost) {}

    // Геттеры для доступа к членам класса
    string getName() const { return name; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    double getCost() const { return cost; }

    // Сеттеры для изменения членов класса
    void setName(const string& n) { name = n; }
    void setBrand(const string& b) { brand = b; }
    void setModel(const string& m) { model = m; }
    void setCost(double c) { cost = c; }

    // Операция сложения стоимости двух запчастей
    SparePart operator+(const SparePart& other) {
        return SparePart(name, brand, model, cost + other.cost);
    }

    // Операция вычитания стоимости двух запчастей
    SparePart operator-(const SparePart& other) {
        return SparePart(name, brand, model, cost - other.cost);
    }

    // Операция инкремента (увеличение стоимости на 1)
    SparePart& operator++() {
        ++cost;
        return *this;
    }

    // Операция декремента (уменьшение стоимости на 1)
    SparePart& operator--() {
        --cost;
        return *this;
    }

    // Операция сравнения (сравнение стоимости)
    bool operator<(const SparePart& other) const {
        return cost < other.cost;
    }
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
            cout << "5. Операции с запчастями\n";
            cout << "6. Выход\n";
            cout << "Введите выбор: ";
            cin >> choice;

            switch (choice) {
                case 1: listParts(); break;            // Показать список запчастей
                case 2: addPart(); break;              // Добавить новую запчасть
                case 3: deletePart(); break;           // Удалить запчасть
                case 4: listPartsForLadaVesta(); break;// Показать запчасти для Lada Vesta
                case 5: performOperations(); break;    // Операции с запчастями
                case 6: cout << "Выход из программы.\n"; break; // Завершение программы
                default: cout << "Некорректный ввод.\n"; break;
            }
        } while (choice != 6);  // Повторять, пока не выбран выход
    }

private:
    // Метод для выполнения операций с запчастями
    void performOperations() {
        int choice;
        cout << "\nВыберите операцию:\n";
        cout << "1. Сложить стоимость двух запчастей\n";
        cout << "2. Вычесть стоимость двух запчастей\n";
        cout << "3. Инкремент стоимости запчасти\n";
        cout << "4. Декремент стоимости запчасти\n";
        cout << "5. Сравнить стоимость двух запчастей\n";
        cout << "Введите выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: addCost(); break;
            case 2: subtractCost(); break;
            case 3: incrementCost(); break;
            case 4: decrementCost(); break;
            case 5: compareCost(); break;
            default: cout << "Некорректный ввод.\n"; break;
        }
    }

    // Метод для сложения стоимости двух запчастей
    void addCost() {
        int index1, index2;
        cout << "Введите номер первой запчасти: ";
        cin >> index1;
        cout << "Введите номер второй запчасти: ";
        cin >> index2;

        if (index1 > 0 && index1 <= count && index2 > 0 && index2 <= count) {
            SparePart result = parts[index1 - 1] + parts[index2 - 1];
            cout << "Результат сложения стоимости: " << result.getCost() << endl;
        } else {
            cout << "Неверный номер запчасти.\n";
        }
    }

    // Метод для вычитания стоимости двух запчастей
    void subtractCost() {
        int index1, index2;
        cout << "Введите номер первой запчасти: ";
        cin >> index1;
        cout << "Введите номер второй запчасти: ";
        cin >> index2;

        if (index1 > 0 && index1 <= count && index2 > 0 && index2 <= count) {
            SparePart result = parts[index1 - 1] - parts[index2 - 1];
            cout << "Результат вычитания стоимости: " << result.getCost() << endl;
        } else {
            cout << "Неверный номер запчасти.\n";
        }
    }

    // Метод для инкремента стоимости запчасти
    void incrementCost() {
        int index;
        cout << "Введите номер запчасти для инкремента: ";
        cin >> index;

        if (index > 0 && index <= count) {
            ++parts[index - 1];  // Инкремент
            cout << "Новая стоимость: " << parts[index - 1].getCost() << endl;
        } else {
            cout << "Неверный номер запчасти.\n";
        }
    }

    // Метод для декремента стоимости запчасти
    void decrementCost() {
        int index;
        cout << "Введите номер запчасти для декремента: ";
        cin >> index;

        if (index > 0 && index <= count) {
            --parts[index - 1];  // Декремент
            cout << "Новая стоимость: " << parts[index - 1].getCost() << endl;
        } else {
            cout << "Неверный номер запчасти.\n";
        }
    }

    // Метод для сравнения стоимости двух запчастей
    void compareCost() {
        int index1, index2;
        cout << "Введите номер первой запчасти: ";
        cin >> index1;
        cout << "Введите номер второй запчасти: ";
        cin >> index2;

        if (index1 > 0 && index1 <= count && index2 > 0 && index2 <= count) {
            const SparePart& part1 = parts[index1 - 1];
            const SparePart& part2 = parts[index2 - 1];

            if (part1.getCost() < part2.getCost()) {
                cout << "Вторая запчасть дороже первой.\n";
            } else if (part1.getCost() > part2.getCost()) {
                cout << "Первая запчасть дороже второй.\n";
            } else {
                cout << "Запчасти равны по стоимости.\n";
            }
        } else {
            cout << "Неверный номер запчасти.\n";
        }
    }

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
            string name, brand, model;
            double cost;
            cout << "Введите наименование запчасти: ";
            cin >> name;
            cout << "Введите марку: ";
            cin >> brand;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите стоимость: ";
            cin >> cost;

            parts[count] = SparePart(name, brand, model, cost);
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
            for (int i = index; i < count - 1; i++) {
                parts[i] = parts[i + 1];
            }
            count--;
            cout << "Запчасть удалена.\n";
        } else {
            cout << "Неверный номер.\n";
        }
    }

    // Метод для отображения запчастей для Lada Vesta
    void listPartsForLadaVesta() {
        cout << "Запчасти для Lada Vesta:\n";
        bool found = false;
        printTableHeader();
        for (int i = 0; i < count; i++) {
            if (parts[i].getBrand() == "Lada" && parts[i].getModel() == "Vesta") {
                printTableRow(i, parts[i]);
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
    // Устанавливаем кодировку UTF-8 для ввода/вывода
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Store store;
    store.displayMenu();
    return 0;
}
