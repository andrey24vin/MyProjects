#include <stdio.h>

int main() {

int a=0x00ffaabb;
unsigned char c;
int i;
for(i=0;i<3;i++)
{
c=(a & 0x00FFFFFF);
printf("%x\n" , c);
a=a>>8;
if (i==2){a=(a | 0x000000CC);
printf("%x\n" , a);
}
}

return 0;
}
