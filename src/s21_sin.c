#include "s21_math.h"
// приводим число к синусу через ряды тейлора. счет в радианы
long double awdawd(double x) {
  while (x > s21_PI || x < -s21_PI) {
    x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
  }
  return x;
}

long double s21_sin(double x) {
  x = awdawd(x);
  long double y = x, rez = x;
  for (long double i = 1; s21_fabs(rez) > s21_EPS; i++) {
    rez = -rez * x * x / (2 * i * (2 * i + 1));
    y += rez;
  }
  return y;
}