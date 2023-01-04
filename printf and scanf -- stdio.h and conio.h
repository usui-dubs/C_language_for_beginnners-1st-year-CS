#include <stdio.h> //header file
//preprocessor directive handled by the pre-processor
//stands for "STanDard input/output" 
//whereas include<conio.h> stands for COnSole input-output
//one of its functions is getch();

int main(void)
{
  int a;
  
  printf("assign the variable a value of integer type: \n");
  scanf("%d",&a);
  
  printf("a = %d",a);
  
  return 0;
}
