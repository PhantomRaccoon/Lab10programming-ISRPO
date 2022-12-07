#include <stdio.h>
#include <string.h>

// Наибольший общий делитель
int nod(int first, int second){
  if (second == 0)
    return first;
  return nod(second, first % second);
}

// Наименьшее общее кратное
int nok(int first, int second){
  return (first / nod(first, second) * second);
}

// Длина целого числа
int intLen(int a){
  int num = a;
  int res = 0;
  while (a != 0){
    res++;
    a /= 10;
  }
  return res;
}

// Разбиение числа на цифры
void digits(int a, int digits[]){
  int num = a;
  int i = intLen(a) - 1;
  while (num != 0){
    digits[i] = num % 10;
    num /= 10;
    i--;
  }
}

int main(){
  // Вывод НОД и НОК
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  printf("%d\n", nod(a, b));
  printf("%d\n", nok(a, b));

  // Вывод цифр числа
  int num;
  scanf("%d", &num);
  const int len = intLen(num);
  int dig[len];
  digits(num, dig);
  for (int i = 0; i < len; i++)
    printf("%d ", dig[i]);
}