#include <stdio.h>
#include <stdlib.h> // для объявления atof()

#define MAXOP 100  // максимальный размер операнда или знака
#define NUMBER '0' // сигнал, что обнаружено число

// прототипы функций
int getop(char s[]);
void push(double);
double pop(void);

// калькулятор с обратной польской записью
int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
  {
    switch (type)
    {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
      {
        push(pop() / op2);
      }
      else
      {
        printf("error: zero divisor\n");
      }
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

// ---------------------------
// реализация push/pop функций
#define MAXVAL 100 // максимальная глубина стека val

int sp = 0;         // следующая свободная позиция в стеке
double val[MAXVAL]; // стек операндов

// push: помещает число f в стек операндов
void push(double f)
{
  if (sp < MAXVAL)
  {
    val[sp++] = f;
  }
  else
  {
    printf("error: stack full, can't push %g\n", f);
  }
}

// pop: извлекает и возвращает верхние число из стека
double pop(void)
{
  if (sp > 0)
  {
    return val[--sp];
  }
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

// ---------------------------
// реализация getop, getch/ungetch функций
#include <ctype.h>

int getch(void);
void ungetch(int);

// getop: извлекает следующий операнд или знак операнда
int getop(char s[])
{
  int i, c;

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
  if (c != EOF)
  {
    ungetch(c);
  }

  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; // буфер для ungetch
int bufp = 0;      // следующая свободная позиция в buf

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