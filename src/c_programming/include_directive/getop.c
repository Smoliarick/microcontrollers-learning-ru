#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// getop: извлекает следующий операнд или знак операнда
int getop(char s[])
{
  int i;
  static int c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  if (!isdigit(c) && c != '.')
  {
    return c; // не число
  }

  i = 0;
  if (isdigit(c)) // накопление целой части
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  if (c == '.') // накопление дробной части
  {
    while (isdigit(s[++i] = c = getch()))
      ;
  }

  s[i] = '\0';

  return NUMBER;
}