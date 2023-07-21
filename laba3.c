#include <stdio.h>
#define N 8


int main() {

int i;
int array[N];
for(i=0;i<N;i++){
array[i]=i;
printf("%d",array[i]);
}
printf("\n");

for(i=0;i<N;i++)
{
printf("%d", array[N-i-1]);
}
printf("\n");
return 0;
}
