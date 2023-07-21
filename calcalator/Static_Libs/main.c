#include "plus.h"
#include "minus.h"
#include "multiplication.h"
#include "division.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
int a,b,n;
int result;
printf("Enter two number:");
scanf("%d %d",&a,&b);
printf("ENTER YOUR CHOICE\n");
printf("1)PLUS\n 2)MINUS\n 3)MULTIPLICATION\n 4)DIVISION\n");
scanf("%d", &n);
switch(n)
{
case 1: result=plus(a,b);
break;
case 2: result=minus(a,b);
break;
case 3: result=multiplication(a,b);
break;
case 4: result=division(a,b);
break;
default: printf("INVALID NUMBER\n");
}

printf(" Result=\n", result);

return 0;
}
