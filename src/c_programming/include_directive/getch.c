#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE]; // буфер для ungetch
static int bufp = 0;      // следующая свободная позиция в buf

// getch: извлекает следующий символ из потока ввода
int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: запоминает символы, возвращаемые в потом, чтобы при следующем вызове getch вначале вводились они,
   а потом уже те, которые действительно поступают из потока ввода
*/
void ungetch(int c)
{
  if (bufp >= BUFSIZE)
  {
    printf("ungetch: too many characters\n");
  }
  else
  {
    buf[bufp++] = c;
  }
}