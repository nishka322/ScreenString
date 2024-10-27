#include "ScreenString.h"
#include <vector>

#ifdef _WIN32
#include <windows.h>
#endif

/**
 * @brief Функция для отображения меню и получения выбора пользователя.
 *
 * Эта функция выводит меню на экран и запрашивает у пользователя
 * ввод выбора. Доступные опции включают вывод строк,
 * получение длины строки, позиции, размера и перемещения строк.
 *
 * @return Код выбора пользователя (целое число от 1 до 8).
 */
int displayMenu() {
    std::cout << "\n--- Меню ---\n";
    std::cout << "1. Вывести все строки в консоль\n";
    std::cout << "2. Длина строки (в символах)\n"; // Изменено
    std::cout << "3. Позиция строки (координаты)\n";
    std::cout << "4. Размер строки (в байтах)\n";   // Изменено
    std::cout << "5. Печать строки по позиции в массиве\n";
    std::cout << "6. Перемещение строки\n";
    std::cout << "7. Печать строки по координатам\n"; // Новый пункт меню
    std::cout << "8. Выход\n";
    std::cout << "Выберите пункт меню (1-8): ";

    int choice;
    std::cin >> choice; // Получаем выбор пользователя
    return choice; // Возвращаем код выбора
}

/**
 * @brief Главная функция программы.
 *
 * Эта функция служит основным входом в программу. Она инициализирует
 * необходимые данные, выводит меню, обрабатывает ввод пользователя
 * и выполняет соответствующие действия на основе выбора.
 *
 * @return Код завершения программы (0 для успешного завершения).
 */
int main() {
    // Установка кодировки на UTF-8 для Windows
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Установка кодировки вывода на UTF-8
    SetConsoleCP(CP_UTF8);        // Установка кодировки ввода на UTF-8
#endif

    std::vector<ScreenString*> strings; // Вектор для хранения указателей на строки

    // Пример добавления строк в вектор
    strings.push_back(new ScreenString("Привет, мир!", 0, 0));
    strings.push_back(new ScreenString("Программирование на C++", 1, 1));
    strings.push_back(new ScreenString("Класс и объекты", 2, 2));
    strings.push_back(new ScreenString("Массивы и указатели", 3, 3));
    strings.push_back(new ScreenString("Наследование и полиморфизм", 4, 4));
    strings.push_back(new ScreenString("Шаблоны и STL", 5, 5));

    // Основной цикл программы
    while (true) {
        int choice = displayMenu(); // Выводим меню и получаем выбор
        int index; // Переменная для хранения индекса строки

        switch (choice) {
            case 1: // Вывод всех строк
                std::cout << "Все строки:\n";
                for (const auto& str : strings) {
                    int x, y;
                    str->getPosition(x, y); // Получаем координаты строки
                    std::cout << "Строка: \"" << str->getStr() << "\" находится на координатах (" << x << ", " << y << ")\n"; // Выводим строку и координаты
                }
                break;

            case 2: // Получение длины строки
                std::cout << "Введите индекс строки (0-" << strings.size() - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < strings.size()) {
                    std::cout << "Длина строки (в символах): " << strings[index]->getLength() << "\n";  // Получаем длину строки
                } else {
                    std::cout << "Некорректный индекс.\n"; // Ошибка при некорректном индексе
                }
                break;

            case 3: // Получение позиции строки
                std::cout << "Введите индекс строки (0-" << strings.size() - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < strings.size()) {
                    int x, y;
                    strings[index]->getPosition(x, y); // Получаем текущую позицию
                    std::cout << "Текущая позиция: (" << x << ", " << y << ")\n";  // Выводим текущую позицию
                } else {
                    std::cout << "Некорректный индекс.\n"; // Ошибка при некорректном индексе
                }
                break;

            case 4: // Получение размера строки в байтах
                std::cout << "Введите индекс строки (0-" << strings.size() - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < strings.size()) {
                    std::cout << "Размер строки (в байтах): " << strings[index]->getByteSize() << "\n"; // Получаем размер строки
                } else {
                    std::cout << "Некорректный индекс.\n"; // Ошибка при некорректном индексе
                }
                break;

            case 5: // Печать строки по позиции в массиве
                std::cout << "Введите индекс строки (0-" << strings.size() - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < strings.size()) {
                    int posX, posY;
                    strings[index]->getPosition(posX, posY); // Получаем координаты
                    strings[index]->printAt(posX, posY); // Печатаем строку на указанных координатах
                } else {
                    std::cout << "Некорректный индекс.\n"; // Ошибка при некорректном индексе
                }
                break;

            case 6: // Перемещение строки
                std::cout << "Введите индекс строки (0-" << strings.size() - 1 << "): ";
                std::cin >> index;
                if (index >= 0 && index < strings.size()) {
                    int newX, newY;
                    std::cout << "Введите новую позицию по оси X: ";
                    std::cin >> newX; // Получаем новую позицию по X
                    std::cout << "Введите новую позицию по оси Y: ";
                    std::cin >> newY; // Получаем новую позицию по Y

                    // Проверяем, можно ли переместить строку
                    if (strings[index]->canMoveTo(newX, newY, strings)) {
                        strings[index]->moveTo(newX, newY); // Перемещаем строку
                        std::cout << "Строка успешно перемещена на координаты (" << newX << ", " << newY << ").\n";
                    } else {
                        std::cout << "Ошибка: координаты (" << newX << ", " << newY << ") уже заняты другой строкой.\n"; // Ошибка при занятых координатах
                    }
                } else {
                    std::cout << "Некорректный индекс.\n"; // Ошибка при некорректном индексе
                }
                break;

            case 7: // Печать строки по координатам
            {
                int x, y;
                std::cout << "Введите координаты X и Y для печати строки: ";
                std::cin >> x >> y; // Получаем координаты для печати

                bool found = false; // Переменная для отслеживания найденной строки
                for (const auto& str : strings) {
                    int posX, posY;
                    str->getPosition(posX, posY); // Получаем текущие координаты строки

                    // Проверяем совпадают ли координаты
                    if (posX == x && posY == y) {
                        str->printAtCoordinates(x, y); // Печатаем строку, если координаты совпадают
                        found = true; // Строка найдена
                        break; // Выход из цикла, если строка найдена
                    }
                }

                if (!found) {
                    std::cout << "На координатах (" << x << ", " << y << ") нет строки." << std::endl; // Сообщение если строки нет на указанных координатах
                }
            }
                break;

            case 8: // Выход из программы
                std::cout << "Выход из программы.\n";
                for (auto str : strings) {
                    delete str; // Освобождение памяти для строк
                }
                return 0; // Завершение программы

            default: // Некорректный выбор
                std::cout << "Некорректный выбор. Пожалуйста, выберите снова.\n"; // Сообщение об ошибке выбора
        }
    }
}
