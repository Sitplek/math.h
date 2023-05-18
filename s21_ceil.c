#include "s21_math.h"
// Возвращает ближайшее целое число возвращает ближайшее целое число, не
// превышающее заданное значение
long double s21_ceil(double x) {
  return (x == (long long int)x) ? x
         : (x < 0)               ? (long double)(((long long int)x))
         : (x > 0)               ? (long double)((long long int)x) + 1
                                 : 0;
}