#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "lab2.h"
int is_even(int n);
int max_of_three(int a, int b, int c);
int sign_of_number(int n);
int absolute_value(int n);
int triangle_exists(int a, int b, int c);
const char* evaluate_score(int score);
double euclidean_distance(double x1, double y1, double x2, double y2);
int manhattan_distance(int x1, int y1, int x2, int y2);
int is_prime(int n);
double average_primes_in_interval(int a, int b);
int count_multiples(int start, int end, int k);
int is_leap_year(int year);
const char* season_by_month(int month);
const char* day_of_week(int day_num);
int count_digits(int n);
int reverse_number(int n);

int main() {
    // ====== Задача 1: Чётное или нечётное ======
    log_result("Задача 1", "Начинаем тестирование");
    assert(is_even(6) == 1);
    assert(is_even(9) == 0);
    
    assert(is_even(0) == 1);
    assert(is_even(-4) == 1);
    assert(is_even(-5) == 0);
    log_result("Задача 1", "Все тесты пройдены");

    // ====== Задача 2: Максимум из трёх чисел ======
    log_result("Задача 2", "Начинаем тестирование");
    assert(max_of_three(1, 2, 3) == 3);
    assert(max_of_three(5, 2, 5) == 5);
    
    assert(max_of_three(-1, -5, -3) == -1);
    assert(max_of_three(0, 0, 0) == 0);
    assert(max_of_three(7, 7, 7) == 7);
    log_result("Задача 2", "Все тесты пройдены");

    // ====== Задача 3: Знак числа ======
    log_result("Задача 3", "Начинаем тестирование");
    assert(sign_of_number(5) == 1);
    assert(sign_of_number(-3) == -1);
    assert(sign_of_number(100) == 1); 

    assert(sign_of_number(0) == 0);
    assert(sign_of_number(-1) == -1);
    assert(sign_of_number(-100) == -1);
    log_result("Задача 3", "Все тесты пройдены");

    // ====== Задача 4: Абсолютное значение ======
    log_result("Задача 4", "Начинаем тестирование");
    assert(absolute_value(5) == 5);
    assert(absolute_value(-4) == 4);
    assert(absolute_value(100) == 100); 

    assert(absolute_value(0) == 0);
    assert(absolute_value(-10) == 10);
    assert(absolute_value(-100) == 100);
    log_result("Задача 4", "Все тесты пройдены");

    // ====== Задача 5: Треугольник существует ======
    log_result("Задача 5", "Начинаем тестирование");
    assert(triangle_exists(3, 4, 5) == 1);
    assert(triangle_exists(1, 2, 3) == 0);
    
    assert(triangle_exists(5, 5, 5) == 1);
    assert(triangle_exists(0, 3, 4) == 0);
    assert(triangle_exists(-1, 2, 3) == 0);
    log_result("Задача 5", "Все тесты пройдены");

    // ====== Задача 6: Класс оценок ======
    log_result("Задача 6", "Начинаем тестирование");
    assert(strcmp(evaluate_score(85), "хорошо") == 0);
    assert(strcmp(evaluate_score(59), "неудовлетворительно") == 0);
    
    assert(strcmp(evaluate_score(100), "отлично") == 0);
    assert(strcmp(evaluate_score(0), "неудовлетворительно") == 0);
    assert(strcmp(evaluate_score(105), "некорректно") == 0);
    assert(strcmp(evaluate_score(-5), "некорректно") == 0);
    log_result("Задача 6", "Все тесты пройдены");

    // ====== Задача 7: Евклидово расстояние ======
    log_result("Задача 7", "Начинаем тестирование");
    assert(double_equals(euclidean_distance(0, 0, 3, 4), 5.0));
    assert(double_equals(euclidean_distance(1, 1, 1, 1), 0.0));

    assert(double_equals(euclidean_distance(-1, -1, 2, 3), 5.0));
    assert(double_equals(euclidean_distance(0.5, 1.5, 2.5, 3.5), 2.828427)); 
    assert(double_equals(euclidean_distance(100, 100, 104, 103), 5.0));
    log_result("Задача 7", "Все тесты пройдены");

    // ====== Задача 8: Манхэттенское расстояние ======
    log_result("Задача 8", "Начинаем тестирование");
    assert(manhattan_distance(0, 0, 3, 4) == 7);
    assert(manhattan_distance(1, 1, 1, 1) == 0);

    assert(manhattan_distance(-1, -1, 2, 3) == 7);
    assert(manhattan_distance(-5, -5, -1, -1) == 8); 
    assert(manhattan_distance(10, 20, 15, 25) == 10); 
    log_result("Задача 8", "Все тесты пройдены");

    // ====== Задача 9: Среднее простых чисел ======
    log_result("Задача 9", "Начинаем тестирование");
    assert(double_equals(average_primes_in_interval(1, 10), 4.25));
    assert(double_equals(average_primes_in_interval(10, 20), 15.0)); 

    assert(double_equals(average_primes_in_interval(10, 10), 0.0));
    assert(double_equals(average_primes_in_interval(13, 13), 13.0));
    assert(double_equals(average_primes_in_interval(2, 3), 2.5)); 
    assert(double_equals(average_primes_in_interval(14, 16), 0.0)); 
    log_result("Задача 9", "Все тесты пройдены");

    // ====== Задача 10: Кратные числа ======
    log_result("Задача 10", "Начинаем тестирование");
    assert(count_multiples(1, 10, 3) == 3);
    assert(count_multiples(1, 20, 5) == 4); 

    assert(count_multiples(5, 5, 5) == 1);
    assert(count_multiples(1, 5, 10) == 0);
    assert(count_multiples(10, 1, 2) == 0);
    log_result("Задача 11", "Все тесты пройдены");

    // ====== Задача 11: Високосный год ======
    log_result("Задача 11", "Начинаем тестирование");
    assert(is_leap_year(2016) == 1);
    assert(is_leap_year(2021) == 0);
    
    assert(is_leap_year(2000) == 1);
    assert(is_leap_year(1900) == 0);
    assert(is_leap_year(0) == 1);
    log_result("Задача 11", "Все тесты пройдены");

    // ====== Задача 12: Сезон по месяцу ======
    log_result("Задача 12", "Начинаем тестирование");
    assert(strcmp(season_by_month(6), "лето") == 0);
    assert(strcmp(season_by_month(12), "зима") == 0);
    
    assert(strcmp(season_by_month(0), "некорректный месяц") == 0);
    assert(strcmp(season_by_month(13), "некорректный месяц") == 0);
    assert(strcmp(season_by_month(3), "весна") == 0);
    log_result("Задача 12", "Все тесты пройдены");

    // ====== Задача 13: День недели ======
    log_result("Задача 13", "Начинаем тестирование");
    assert(strcmp(day_of_week(1), "понедельник") == 0);
    assert(strcmp(day_of_week(7), "воскресенье") == 0);
    assert(strcmp(day_of_week(4), "четверг") == 0); 
    
    assert(strcmp(day_of_week(0), "некорректный день") == 0);
    assert(strcmp(day_of_week(8), "некорректный день") == 0);
    assert(strcmp(day_of_week(-1), "некорректный день") == 0); 
    log_result("Задача 13", "Все тесты пройдены");

    // ====== Задача 14: Подсчёт цифр ======
    log_result("Задача 14", "Начинаем тестирование");
    assert(count_digits(123) == 3);
    assert(count_digits(0) == 1);
    assert(count_digits(9) == 1); 

    assert(count_digits(-456) == 3);
    assert(count_digits(1000) == 4);
    assert(count_digits(-1000) == 4);
    log_result("Задача 14", "Все тесты пройдены");

    // ====== Задача 15: Реверс числа ======
    log_result("Задача 15", "Начинаем тестирование");
    assert(reverse_number(123) == 321);
    assert(reverse_number(100) == 1);
    
    assert(reverse_number(-456) == -654);
    assert(reverse_number(0) == 0);
    assert(reverse_number(5) == 5);
    log_result("Задача 15", "Все тесты пройдены");

    printf("Все тесты пройдены успешно!\n");
    return 0;
}

