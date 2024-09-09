#include <stdio.h>

int main()
{
  char operator;
  double num1, num2, result;

  printf("Ingrese la operación a realizar: (+, -, *, /): ");
  scanf("%c", &operator);

  printf("Ingrese dos números separados por espacio: ");
  scanf("%lf %lf", &num1, &num2);

  switch (operator)
  {
  case '+':
    result = num1 + num2;
    printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
    break;

  case '-':
    result = num1 - num2;
    printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
    break;

  case '*':
    result = num1 * num2;
    printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
    break;

  case '/':
    if (num2 != 0)
    {
      result = num1 / num2;
      printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
    } else
    {
      printf("Error! Division by zero.\n");
    }
    break;

  default:
    printf("Invalid operator!\n");
  }

  return 0;
}