#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
char *Name;
Name=malloc(500);
//free(Name);
Name=malloc(1000);
printf("Vse ALl GOOD\n");
free(Name);
//LostMemory in 500 byte




int  n=10;
int *array;
//Vudelenie massiva n*4 byte
array=(int*)malloc(n*sizeof(int));
//free(array);
return 0;
}
