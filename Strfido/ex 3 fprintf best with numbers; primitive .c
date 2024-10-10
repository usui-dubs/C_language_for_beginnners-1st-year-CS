#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE * f;
    float moy, num[1000], num1, sum = 0, nb = 0;
    int i, n;
    
    f = fopen("Numbers.bin", "wb");
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; ++i)
    {
        printf("Enter the value %d: ", i + 1);
        scanf("%f", &num[i]);
 //no       //fprintf(f, "%f ", num[i]); //"%f + something like space"
    }
	fwrite(num, sizeof(float), n, f); //n is a must
    

    /*for(i = 0; i < n; ++i)
    {
        printf("Enter the value %d: ", i + 1);
        scanf("%f", &num1);
        fprintf(f, "%f ", num1);
 //no       //fwrite (&num1, sizeof(float), 1, f);
    }*/
    fclose(f);
    
	fopen("Numbers.bin","rb");
    
    fread(num, sizeof(float), n, f);
    
	for(i = 0; i < n; ++i)
	{
        //fscanf(f, "%f", &num[i]); //&
        sum += num[i];
    	printf("les nombres %f\n",num[i]);
        nb++;
    }
    //or:
   /* while(fread(&num1, sizeof(float), 1, f))
    {
        sum += num1;
    	printf("les nombres %f\n", num1);
        nb++;
    }*/
    
    
    
    /*while(fscanf(f, "%f", &num1) != EOF)
	{
        sum += num1;
    	printf("les nombres %f\n", num1);
        nb++;
    }*/
    
    if(n != 0)
    {
        moy = (sum / nb);
        printf("sum: %f\nmoyen: %f", sum, moy);
    }
    
    fclose(f);
    
    return 0;
}
    
