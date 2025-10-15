#include "lab2.h"
#include <math.h>
#include <stdio.h>

// Задача 1 - Чётное или нечётное
int is_even(int n) {
    if (n % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// Задача 2 - Максимум из трёх чисел
int max_of_three(int a, int b, int c) {
    int max = a;  

    if (b > max) {     
        max = b;       
    }
    
    if (c > max) {     
        max = c;       
    }
    return max;    
}

// Задача 3 - Знак числа
int sign_of_number(int n) {
    if (n > 0) {
        return 1;
    }
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
}

// Задача 4 - Абсолютное значение
int absolute_value(int n) {
    if (n < 0) {
        return -n;
    }
    if (n >= 0) {
        return n;

    }
}

// Задача 5 - Треугольник существует
int triangle_exists(int a, int b, int c) {
    if (a + b <= c) {
        return 0;
    }
    if (a + c <= b) {
        return 0;
    }
    if (b + c <= a) {
        return 0;
    }
    return 1;
}

// Задача 6 - Класс оценок
const char* get_grade(int score) {
    if (score < 0) {
        return "некорректно";
    }
    if (score > 100) {
        return "некорректно";
    }
    if (score < 60) {
        return "неудовлетворительно";
    }
    if (score < 75) {
        return "удовлетворительно";
    }
    if (score < 90) {
        return "хорошо";
    }
    return "отлично";
}

// Задача 7 - Евклидово расстояние
double euclidean_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dx_squared = dx * dx;
    double dy_squared = dy * dy;
    double sum = dx_squared + dy_squared;
    double distance = sqrt(sum);
    return distance;
}

// Задача 8 - Манхэттенское расстояние
int manhattan_distance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int abs_x = absolute_value(dx);
    int abs_y = absolute_value(dy);
    int distance = abs_x + abs_y;
    return distance;
}

// Вспомогательная функция для проверки простоты (можно писать сразу в задаче 9, но это плохой тон)
int is_prime(int n) {
    if (n < 2) {
        return 0;  
    }
    if (n == 2) {
        return 1;  
    }
    if (n % 2 == 0) {
        return 0; 
    }
    
    //проверка нечетных делителей
    int i = 3;
    while (i < n) {
        if (n % i == 0) {
            return 0;
        }
        i = i + 2;
    }
    
    return 1;
}

// Задача 9 - Среднее арифметическое простых чисел в интервале
double average_primes_in_interval(int a, int b) {
    int count = 0;
    double sum = 0;

    if (a > b) {
        return 0.0;
    }

    int i = a;
    while (i <= b) {
        if (is_prime(i) == 1) {
            count = count + 1;
            sum = sum + i;
        }
        i = i + 1;
    }

    if (count == 0) {
        return 0.0;
    }

    double average = sum / count;
    return average;
}

// Задача 10 - Кратные числа в интервале
int count_multiples(int start, int end, int k) {
    int count = 0;
    int i = start;
    
    while (i <= end) {
        if (i % k == 0) {
            count = count + 1;
        }
        i = i + 1;
    }
    
    return count;
}

// Задача 11 - Високосный год
int is_leap_year(int year) {
    if (year % 4 != 0) {
        return 0;
    }
    if (year % 100 != 0) {
        return 1;
    }
    if (year % 400 == 0) {
        return 1;
    }
    return 0;
}

// Задача 12 - Сезон по номеру месяца
const char* season_by_month(int month) {
    if (month == 12 || month == 1 || month == 2) {
        return "зима";
    }
    if (month == 3 || month == 4 || month == 5) {
        return "весна";
    }
    if (month == 6 || month == 7 || month == 8) {
        return "лето";
    }
    if (month == 9 || month == 10 || month == 11) {
        return "осень";
    }
    return "некорректный месяц";
}

// Задача 13 - День недели
const char* day_of_week(int day_num) {
    if (day_num == 1) {
        return "понедельник";
    }
    if (day_num == 2) {
        return "вторник";
    }
    if (day_num == 3) {
        return "среда";
    }
    if (day_num == 4) {
        return "четверг";
    }
    if (day_num == 5) {
        return "пятница";
    }
    if (day_num == 6) {
        return "суббота";
    }
    if (day_num == 7) {
        return "воскресенье";
    }
    return "некорректный день";
}

// Задача 14 - Подсчёт цифр в числе
int count_digits(int n) {
    if (n == 0) {
        return 1;
    }
    
    int count = 0;
    int number = n;
    
    if (number < 0) {
        number = -number;
    }
    
    while (number > 0) {
        number = number / 10;  
        count = count + 1;  
    }
    return count;
}

// Задача 15 - Реверс числа
int reverse_number(int n) {
     int reversed = 0;
    int number = n;
    
    if (n < 0) {
        number = -number;
    }
    
    while (number > 0) {
        int last_digit = number % 10;
        reversed = reversed * 10 + last_digit;
        number = number / 10;
    }
    
    if (n < 0) {
        reversed = -reversed;
    }
    
    return reversed;
}

