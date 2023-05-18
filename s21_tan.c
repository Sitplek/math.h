#include "s21_math.h"
// Тангенс вычесляем по формуле синус деленный на сосинус
long double S21_da(double x) {
  while (x > s21_PI || x < -s21_PI) {
    x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
  }
  return x;
}

long double s21_tan(double x) {
  x = S21_da(x);
  return s21_sin(x) / s21_cos(x);
}
