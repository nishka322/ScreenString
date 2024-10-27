#ifndef SCREENSTRING_H
#define SCREENSTRING_H

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <vector>

/**
 * @class ScreenString
 * @brief Класс для работы со строками, включая их позиционирование и длину.
 *
 * Класс предоставляет функциональность для создания строк с заданными
 * координатами, а также методы для их перемещения и проверки позиций.
 */
class ScreenString {
private:
    std::string str; //!< Содержимое строки
    int positionX;   //!< Позиция по оси X
    int positionY;   //!< Позиция по оси Y
    size_t length;   //!< Длина строки в символах

public:
    /**
     * @brief Конструктор класса ScreenString.
     *
     * Инициализирует строку и задает её начальные координаты.
     *
     * @param input Строка для инициализации.
     * @param x Позиция по оси X.
     * @param y Позиция по оси Y.
     */
    ScreenString(const std::string& input, int x, int y);

    /**
     * @brief Деструктор.
     *
     * Освобождает ресурсы, используемые объектом класса.
     */
    ~ScreenString();

    /**
     * @brief Получает содержимое строки.
     *
     * Возвращает указатель на строку, хранящуюся в объекте.
     *
     * @return Указатель на строку.
     */
    const char* getStr() const;

    /**
     * @brief Получает длину строки.
     *
     * @return Длина строки в символах.
     */
    size_t getLength() const;

    /**
     * @brief Получает размер строки в байтах (UTF-8).
     *
     * @return Размер строки в байтах.
     */
    size_t getByteSize() const;

    /**
     * @brief Печатает строку на экране в заданной позиции.
     *
     * @param x Позиция по оси X.
     * @param y Позиция по оси Y.
     */
    void printAt(int x, int y) const;

    /**
     * @brief Получает текущую позицию строки.
     *
     * @param x Ссылка на координату X.
     * @param y Ссылка на координату Y.
     */
    void getPosition(int& x, int& y) const;

    /**
     * @brief Перемещает строку в новую позицию.
     *
     * @param newX Новая позиция по оси X.
     * @param newY Новая позиция по оси Y.
     */
    void moveTo(int newX, int newY);

    /**
     * @brief Проверяет возможность перемещения строки на новые координаты.
     *
     * @param newX Новая позиция по оси X.
     * @param newY Новая позиция по оси Y.
     * @param strings Вектор строк для проверки занятости координат.
     * @return true, если перемещение возможно, иначе false.
     */
    bool canMoveTo(int newX, int newY, const std::vector<ScreenString*>& strings) const;

    /**
     * @brief Печатает строку по указанным координатам.
     *
     * @param x Позиция по оси X.
     * @param y Позиция по оси Y.
     */
    void printAtCoordinates(int x, int y) const;
};

#endif // SCREENSTRING_H
