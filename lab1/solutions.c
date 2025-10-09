#include "lab1.h"
#include <math.h>
#include <stdio.h>
// Задача 1 - Чётное или нечётное
int is_even(int n) {
    if (n % 2 == 0){
        return 1;
    }
    else {
        return 0;
    }
}

// Задача 2 - Максимум из трёх чисел
int max_of_three(int a, int b, int c) {
    if ((a > b) && (b > c)) return a;
    if ((b > a) && (a > c)) return b;
    if ((a < b) && (c > b)) return c;
}

// Задача 3 - Знак числа
int sign_of_number(int n) {
    if (n > 0){
        return 1;
    }
    if (n == 0){
        return 0;
    }
    if (n < 0) {
        return -1;
    }
}

// Задача 4 - Абсолютное значение
int absolute_value(int n) {
    if (n >= 0){
        return n;
    }
    if (n < 0){
        return (-1) * n;
    }
}


// Задача 5 - Треугольник существует
int triangle_exists(int a, int b, int c) {
    if ((a + b) > c && (a + c) > b && (c + b) > a) {
        return 1;
    }
    else return 0;
}

// Задача 6 - Класс оценок
const char* get_grade(int score) {
    if (score < 0 || score > 103) return "некорректно";
    if (score < 60) return "неудовлетворительно";
    if (score > 59 && score <= 74) return "удовлетворительно";
    if (score > 74 && score <= 90) return "хорошо";
    if (score > 90) return "отлично";
}

// Задача 7 - Евклидово расстояние
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Задача 8 - Манхэттенское расстояние
int manhattan_distance(int x1, int y1, int x2, int y2) {
    return (abs(x2 - x1) + abs(y2 - y1));
}

// Вспомогательная функция для проверки простоты (можно писать сразу в задаче 9, но это плохой тон)
int is_prime(int n) {
    // Быстрая отработка особых случаев
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    // Отработка нечётных чисел до корня из n для оптимизации
    int limit = (int)sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Задача 9 - Среднее арифметическое простых чисел в интервале
double average_primes_in_interval(int a, int b) {
    // Определяем границы интервала
    int low = (a < b) ? a : b;
    int high = (a > b) ? a : b;
    
    int sum = 0;
    int count = 0;
    
    // Перебираем все числа в интервале
    for (int i = low; i <= high; i++) {
        if (is_prime(i)) {
            sum += i;
            count++;
        }
    }
    // Если простых чисел нет, возвращаем 0
    if (count == 0) {
        return 0.0;
    }
    
    return (double)sum / count;
}

// Задача 10 - Кратные числа в интервале
int count_multiples(int a, int b, int k) {
    int counter = 0;
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            counter ++;
        }
    }
    return counter;
}

// Задача 11 - Високосный год
int is_leap_year(int year) {
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) return 1;
    else return 0;
}

// Задача 12 - Сезон по номеру месяца
const char* season_by_month(int month) {
    if (month < 1 || month > 12) return "некорректно";
    switch (month) {
    case 1: return "зима";
    case 2: return "зима";
    case 3: return "весна";
    case 4: return "весна";
    case 5: return "весна";
    case 6: return "лето";
    case 7: return "лето";
    case 8: return "лето";
    case 9: return "осень";
    case 10: return "осень";
    case 11: return "осень";
    case 12: return "зима";
    }
}

// Задача 13 - День недели
const char* day_of_week(int day_num) {
    if (day_num < 1 || day_num > 7) return "некорректно";
    switch (day_num) {
    case 1: return "понедельник";
    case 2: return "вторник";
    case 3: return "среда";
    case 4: return "четверг";
    case 5: return "пятница";
    case 6: return "суботта";
    case 7: return "воскресенье";
    }
}

// Задача 14 - Подсчёт цифр в числе
int count_digits(int n) {
    int counter = 0;
    do {
    // с помощью целочисленного деления на 10 считаем сколько разрядов в числе
        n /= 10;
        counter++;
} while (n > 0);
return counter;
}

// Задача 15 - Реверс числа
int reverse_number(int n) {
    int digit = 0;
    int result = 0;
    do {
    // получаем последнюю цифру числа и дописымваем её как новый разряд
    digit = n % 10;
    n /= 10;
    result = result * 10 + digit;
} while (n > 0);
return result;
}
