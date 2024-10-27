#include "ScreenString.h"
#include <cstring>

/**
 * @brief Конструктор класса ScreenString.
 *
 * Инициализирует строку и задает её начальные координаты.
 * При создании строки выводится сообщение в консоль.
 *
 * @param input Строка для инициализации.
 * @param x Позиция по оси X.
 * @param y Позиция по оси Y.
 */
ScreenString::ScreenString(const std::string& input, int x, int y)
        : str(input), positionX(x), positionY(y), length(getLength()) { // Обновлено для установки длины
    std::cout << "Создана строка: " << str << " длиной: " << length << " символов." << std::endl;
}

/**
 * @brief Деструктор.
 *
 * Освобождает ресурсы, используемые объектом класса.
 * При уничтожении строки выводится сообщение в консоль.
 */
ScreenString::~ScreenString() {
    std::cout << "Освобождаем строку: " << str << std::endl;
}

/**
 * @brief Получает содержимое строки.
 *
 * Возвращает указатель на строку, хранящуюся в объекте.
 *
 * @return Указатель на строку.
 */
const char* ScreenString::getStr() const {
    return str.c_str();
}

/**
 * @brief Получает длину строки.
 *
 * @return Длина строки в символах.
 */
size_t ScreenString::getLength() const {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    std::wstring wideStr = converter.from_bytes(str); // Преобразуем UTF-8 в wide string
    return wideStr.length(); // Возвращаем количество символов
}

/**
 * @brief Получает размер строки в байтах (UTF-8).
 *
 * @return Размер строки в байтах.
 */
size_t ScreenString::getByteSize() const {
    return str.length(); // Возвращаем длину строки в байтах
}

/**
 * @brief Печатает строку на экране в заданной позиции.
 *
 * @param x Позиция по оси X.
 * @param y Позиция по оси Y.
 */
void ScreenString::printAt(int x, int y) const {
    std::cout << "Строка \"" << str << "\" отображается на позиции (" << x << ", " << y << ")." << std::endl;
}

/**
 * @brief Получает текущую позицию строки.
 *
 * @param x Ссылка на координату X.
 * @param y Ссылка на координату Y.
 */
void ScreenString::getPosition(int& x, int& y) const {
    x = positionX;
    y = positionY;
}

/**
 * @brief Перемещает строку в новую позицию.
 *
 * @param newX Новая позиция по оси X.
 * @param newY Новая позиция по оси Y.
 */
void ScreenString::moveTo(int newX, int newY) {
    positionX = newX;
    positionY = newY;
    std::cout << "Строка перемещена на позицию (" << positionX << ", " << positionY << ")." << std::endl;
}

/**
 * @brief Печатает строку по указанным координатам.
 *
 * @param x Позиция по оси X.
 * @param y Позиция по оси Y.
 */
void ScreenString::printAtCoordinates(int x, int y) const {
    // Проверка на соответствие координат текущей строки
    if (positionX == x && positionY == y) {
        std::cout << "Строка \"" << str << "\" отображается на координатах (" << x << ", " << y << ")." << std::endl;
    } else {
        std::cout << "На координатах (" << x << ", " << y << ") нет строки." << std::endl;
    }
}

/**
 * @brief Проверяет возможность перемещения строки на новые координаты.
 *
 * @param newX Новая позиция по оси X.
 * @param newY Новая позиция по оси Y.
 * @param strings Вектор строк для проверки занятости координат.
 * @return true, если перемещение возможно, иначе false.
 */
bool ScreenString::canMoveTo(int newX, int newY, const std::vector<ScreenString*>& strings) const {
    for (const auto& str : strings) {
        if (str != this) { // Проверяем, что это не сам объект
            int x, y;
            str->getPosition(x, y);
            if (x == newX && y == newY) { // Если координаты совпадают
                return false; // Координаты заняты
            }
        }
    }
    return true; // Координаты свободны
}
