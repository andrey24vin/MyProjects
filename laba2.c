#include <stdio.h>
#define N 4


int main() {

int i,j;
int array[N][N];
for (i=0;i<N;i++)
{

for (j=0;j<N;j++)
{
array[i][j]=N;
printf("%d", array[i][j]);
}
printf("\n");
}





return 0;
}
