#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char c;
    int nb = 0;
    FILE * fpointer = fopen("anacool.txt","r+");//read and write

    if(fpointer == NULL)
        printf("erreur");
  /*  fpointer = fopen("anacool.txt","w");
    printf(fpointer, "Adslm hh\nidk AaAajk aA Z AA");*/
    c = fgetc(fpointer);
    if( c == 'A')
        nb++;
    while((c = fgetc(fpointer))!= EOF)
    {
        if( c == ' ' || c == '\n')
        {
            c = fgetc(fpointer);
            if( c == 'A')
                nb++;
        }
    }

    printf(" numbre of words that starts with 'A' is : %d", nb);
    fclose(fpointer);
/*
    FILE * f;
    char s[10000];
    int nb = 0;

    f = fopen("anacool.txt", "r");

    fread(s, sizeof(char), 10000, f);
    puts(s);
//   fgets (s, 1000, f); //doesnt write the second phrase stops at \n
//   printf("%s", s);
//	fgets (s, 1000, f);
//	printf("%s", s);

    char *token = strtok(s, " "); //first word address
    // printf("%s", token);
    while(token != NULL)
    {
        if(token[0] == 'A' ){
            nb++;
        }
        token = strtok(NULL, " ");
        //printf("%s \n", token);
    }
    printf("\nTHE numbre of words that starts with 'A' is : %d", nb);

    fclose(f);
    */
    return 0;
}
