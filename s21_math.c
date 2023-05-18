#include "s21_math.h"

#include <math.h>

// проверка находиться ли х в диапозоне от -2*pi и 2*pi
// если выходит за пределы то мы корректируем его до
// необходимоs21_NANs2го диапозона для работы с углами
long double s21_replace(double x) {
  while (x > s21_PI || x < -s21_PI) {
    x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
  }
  return x;
}

long double s21_pow(double x, double y) {
  long double rez;
  rez = s21_exp(y * s21_log(x));
  return rez;
}
// модуль числа
int s21_abs(int x) { return x < 0 ? x * -1 : x; }

// модуль числа с плавающей точкой
long double s21_fabs(double x) { return x < 0 ? x * -1 : x; }

// Вычесляет квалратный корень
long double s21_sqrt(double x) {
  long double res = 0.0 / 0.;
  if (x == 1. / 0.)
    res = 1. / 0.;
  else if (x >= 0) {
    res = 1.0;
    for (int i = 0; i < 100; i++) {
      res -= (res * res - x) / (2 * res);
    }
  }
  return res;
}

// Возвращает ближайшее целое число
long double s21_floor(double x) {
  return (x == (long long int)x) ? x
         : (x > 0)               ? (long double)(((long long int)x))
         : (x < 0)               ? (long double)((long long int)x) - 1
                                 : 0;
}
// Возвращает ближайшее целое число возвращает ближайшее целое число, не
// превышающее заданное значение
long double s21_ceil(double x) {
  return (x == (long long int)x) ? x
         : (x < 0)               ? (long double)(((long long int)x))
         : (x > 0)               ? (long double)((long long int)x) + 1
                                 : 0;
}

// приводим число к синусу через ряды тейлора. счет в радианы
long double s21_sin(double x) {
  x = s21_replace(x);
  long double y = x, rez = x;
  for (long double i = 1; s21_fabs(rez) > s21_EPS; i++) {
    rez = -rez * x * x / (2 * i * (2 * i + 1));
    y += rez;
  }
  return y;
}
// косинус вычесление по формуле от синуса
long double s21_cos(double x) {
  x = s21_replace(x);
  return s21_sin((s21_PI / 2.0) - x);
}
// Тангенс вычесляем по формуле синус деленный на сосинус
long double s21_tan(double x) {
  x = s21_replace(x);
  return s21_sin(x) / s21_cos(x);
}

// эпсилент числа
long double s21_exp(double x) {
  long double rez = 1, y = 1, i = 1;
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(rez) > s21_EPS) {
    rez *= x / i;
    i++;
    y += rez;
    if (y > s21_MAX_double) {
      y = s21_INF;
      break;
    }
  }
  y = flag == 1 ? y > s21_MAX_double ? 0 : 1. / y : y;
  return y = y > s21_MAX_double ? s21_INF : y;
}
// высчитываем значение арктангенса через синус
long double s21_atan(double x) { return s21_asin((x) / (s21_sqrt(1 + x * x))); }

// высчитываем значение арксинуса через ряды тейлора
long double s21_asin(double x) {
  long double sum = x, slog = x;
  int n = 1;
  if (s21_fabs(s21_fabs(x) - 1) < s21_EPS)
    sum = s21_PI / 2. * x;
  else if (x < -1 || x > 1)
    sum = 0 / 0.0;
  else
    while (s21_fabs((double)slog) > s21_EPS) {
      slog *= (x * x * (2. * n - 1) * (2. * n - 1)) / (2. * (2. * n + 1) * n);
      sum += slog;
      n++;
    }
  return sum;
}

// высчитываем значение аркz косинуса через аркосинус
long double s21_acos(double x) {
  long double result = 0.;
  if (x == 1 || x == -1)
    result = s21_PI * (1 - x) / 2;
  else if (x < -1 || x > 1)
    result = 0 / 0.0;
  else {
    result = (s21_PI / 2) - s21_asin(x);
  }
  return result;
}
// вычесляем натуральный логарифм по основанию эпсилент
long double s21_log(double x) {
  double res = 0;
  int i;
  for (i = 1; i < 100000; i++) res += (1 / (double)i) * pow((x - 1) / x, i);
  return res;
}
// вычесляем остаток от деления
long double s21_fmod(double x, double y) {
  if (y == 0) return 0;
  int q = x / y, res = x - y * q;
  ;
  return res >= 0 ? res : res + y;
}