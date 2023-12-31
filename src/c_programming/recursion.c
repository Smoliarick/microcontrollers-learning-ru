#include <stdio.h>

// printd: вывод числа n десятичными цифрами
void printd(int n)
{
  if (n < 0)
  {
    putchar('-'); // вывод символа в стандартный поток вывода
    n = -n;
  }

  if (n / 10)
  {
    printd(n / 10); // рекурсивный вызов функции
  }

  putchar(n % 10 + '0'); // вывод цифры в стандартный поток вывода
}

int main(void)
{
  printd(-152425); // Вывод: -152425
  return 0;
}