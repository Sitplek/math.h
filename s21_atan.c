#include "s21_math.h"
// высчитываем значение арктангенса через синус
long double s21_atan(double x) { return s21_asin((x) / (s21_sqrt(1 + x * x))); }