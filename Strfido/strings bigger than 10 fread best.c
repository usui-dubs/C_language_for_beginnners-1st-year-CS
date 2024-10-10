#include<stdio.h>
#include<string.h>

int main()
{
    FILE* f, *g;
    char mot[50], temp;
    int i, n;
    
    f = fopen("bigger10.txt", "w");
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    scanf("%c", &temp);
    
    for(i = 0; i < n; ++i)
    {
        printf("Enter a string %d: ", i + 1);
        gets(mot);
        fwrite(mot, sizeof(char), 50, f);
        //fprintf(f, "%s\n", mot); //"%f" No, %f\n yes
    }
	
    fclose(f);
    
	fopen("bigger10.txt","r");
    g = fopen("wordbigger10", "w");
	while(fread(mot, sizeof(char), 50, f))
   // while(fscanf(f, "%s", mot) != EOF)// scans every word alone even if we entered two words in the string
	    {
        if(strlen(mot) > 10)
    	    //fprintf(g, "%s\n", mot); 
            fwrite(mot, sizeof(char), 50, g);
       }
    
    fclose(g);   
    fopen("wordbigger10", "r");
    //while(fscanf(g, "%s", mot) != EOF)
    while(fread(mot, sizeof(char), 50, g))
	    {
        printf("%s\n", mot);
       }
       
    fclose(g); 
    fclose(f);
    
    return 0;
}
    
    