#include <stdio.h>

int main() {
const int N=3;
int i,j;
int array[N][N];
int d=3;
for (i=0;i<N;i++){
for (j=0;j<N;j++){

if(i+j<=1){
array[i][j]=1;
}
else{
array[i][j]=0;
}
printf("%d",array[i][j]);
}
printf("\n");
}






return 0;
}
