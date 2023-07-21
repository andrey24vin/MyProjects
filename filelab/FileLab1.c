#include <stdio.h>

int main()
{
  FILE *file1;
  file1 = fopen("test_text.txt", "w+t");
  fprintf(file1, "Hello HEllooo woooordl");
  int a;
  fscanf(stdin,"%d",&a);
  fprintf(file1,  "%.3d", a);
  fclose(file1);
  return 0;
}
