#include <stdio.h>

int main() {

int a=0x00ffaabb;
int *ptr;
char *ptr1;
unsigned char c;
int i;
ptr=&a;
ptr1=&c;
for(i=0;i<3;i++)
{
*ptr1=(*ptr & 0x00FFFFFF);
printf("%x\n" , *ptr1);
*ptr=*ptr>>8;
if (i==2){*ptr1=(*ptr | 0x000000CC);
printf("%x\n" , *ptr1);
}
}

return 0;
}
