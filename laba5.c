#include <stdio.h>
int main()
{
int i=0,j=0;
int const N=4;
int array[N][N];
int k=1;
int ibeg=0,ifin=0,jbeg=0,jfin=0;

while (k<=N*N)
{
array[i][j]=k;
if(i==ibeg && j<N-jfin-1) {++j;}
else if(j==N-jfin-1 && i<N-ifin-1) {++i;}
else if(i==N-ifin-1 && j>jbeg){--j;}
else --i;

if((i==ibeg+1) && (j==jbeg) && (jbeg!=N-jfin-1))
{
++ibeg;
++jbeg;
++ifin;
++jfin;
}
++k;
}

for(i=0;i<N;i++){
for(j=0;j<N;j++){
printf("%d       ", array[i][j]);
}
printf("\n");
}
return 0;
}
