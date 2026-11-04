#include <iostream>
#include <cmath>

using namespace std;

// Декларації функцій для кожного завдання
void task_if1();   // Завдання 1: Якщо число додатне, відняти 8
void task_if21();  // Завдання 2: Координати точки на осях (0, 1, 2, 3)
void task_geom3(); // Завдання 3: Попадання точки у фігуру варіанту 3

int main() {
    int menu;
    
    do {
        cout << "========================================" << endl;
        cout << "Select a task to run:" << endl;
        cout << "1. Task If1" << endl;
        cout << "2. Task If21" << endl;
        cout << "3. Task Figure3" << endl;
        cout << "0. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter task number: ";
        cin >> menu;

        // Перевірка на коректність введення пункту меню
        if (!cin) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << endl << "--- Running Task ---" << endl;
        
        // Перемикання між завданнями
        switch (menu) {
        case 1:
            task_if1();
            break;
        case 2:
            task_if21();
            break;
        case 3:
            task_geom3();
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Wrong task number! Please try again." << endl;
        }
        
        cout << endl;
        
    } while (menu != 0);

    system("pause"); // Затримка консолі перед закриттям
    return 0;
}

// =========================================================================
// If1. Дано ціле число. Якщо воно є додатним, то відняти від нього 8; 
// інакше не змінювати його. Вивести отримане число.
// =========================================================================
void task_if1() {
    int num;
    cout << "Enter an integer number: ";
    cin >> num;

    // Перевірка коректності введення цілого числа
    if (cin) {
        // Якщо число додатне, то віднімаємо від нього 8
        if (num > 0) {
            num -= 8;
        }
        cout << "Result: " << num << endl;
    }
    else {
        cout << "Error! Invalid integer number." << endl;
        cin.clear();            // Скидання помилкового стану потоку
        cin.ignore(10000, '\n'); // Очищення буфера від некоректних символів
    }
}

// =========================================================================
// If21. Дано цілочисельні координати точки на площині. Якщо точка збігається з
// початком координат, то вивести 0. Якщо точка не збігається з початком координат,
// але лежить на осі OX або OY, то вивести відповідно 1 або 2. Якщо точка не лежить
// на координатних осях, то вивести 3.
// =========================================================================
void task_if21() {
    int x, y; // Цілочисельні координати точки
    cout << "Enter point coordinates (x, y): ";
    cin >> x >> y;

    // Перевірка, чи введено коректні цілі числа
    if (cin) {
        // Умова: точка збігається з початком координат
        if (x == 0 && y == 0) {
            cout << "Result: 0" << endl;
        }
        // Умова: точка лежить на осі OX
        else if (y == 0) {
            cout << "Result: 1" << endl;
        }
        // Умова: точка лежить на осі OY
        else if (x == 0) {
            cout << "Result: 2" << endl;
        }
        // Умова: точка не лежить на координатних осях
        else {
            cout << "Result: 3" << endl;
        }
    }
    // Інакше – якщо введено не числові дані
    else {
        cout << "Wrong integer coordinates!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// =========================================================================
// Figure3. Дано координати точки (x, y). Визначити, чи потрапляє точка в фігуру
// заданого кольору варіанту 3 (жовта фігура) і вивести відповідне повідомлення.
// =========================================================================
void task_geom3() {
    double a, r; // Параметри фігури: a - катет трикутника, r - радіус кола
    double x, y; // Координати точки

    cout << "Enter parameters a and r: ";
    cin >> a >> r;

    // Перевірка коректності геометричних параметрів
    // Радіус r має бути строго меншим за катет a, інакше фігури не існуватиме
    if (cin.fail() || a <= 0 || r <= 0 || r >= a) {
        cerr << "Invalid geometric parameters! (Must be: a > 0, r > 0 and r < a)" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Enter point coordinates (x, y): ";
    cin >> x >> y;

    // Перевірка, чи введені координати є числами
    if (!cin) {
        cerr << "Non-numeric coordinate data!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    // 1. Перевірка належності прямокутному трикутнику в I чверті (x >= 0, y >= 0, x + y <= a)
    bool inTriangle = (x >= 0 && y >= 0 && (x + y <= a));

    // 2. Перевірка перебування ПОЗА колом радіуса r (вирізана частина біля початку координат)
    bool outsideCircle = (x * x + y * y >= r * r);

    // Точка належить фігурі, якщо вона одночасно всередині трикутника і зовні кола
    if (inTriangle && outsideCircle) {
        cout << "The point belongs to area 3 (Yellow shape)." << endl;
    }
    // В усіх інших випадках — не належить
    else {
        cout << "The point DOES NOT belong to area 3." << endl;
    }
}
