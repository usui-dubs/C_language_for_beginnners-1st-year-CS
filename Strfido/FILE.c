#include<stdio.h>
#include<stdlib.h>

int main()
{
    char c;
    FILE * fpointer = fopen("anacool.txt","r+");//read and write

    if(fpointer == NULL)
        printf("erreur");

    //printf(fpointer, "jdslm hh\nidk"); //fputs("a string", f)

    while((c = fgetc(fpointer)) != EOF) //1st method to read char
        printf("%c", c);
	
    /*fpointer = fopen("anacool.txt","a");//append

    fprintf(fpointer, "\n جمال الروح يفدينا") ;        //fwrite(num, sizeof(int), 5, f); given num is arr meaning num contains address of 1st elem  //fputc(c, f);

*/
    /*char line[222]; //2nd method reads only first line

    fpointer = fopen("anacool.txt","r"); //r+ read and write
//2nd
    fgets (line, 222, fpointer);    
    printf("%s", line);

   // fpointer++ happens //for second line
   //or:
   while(fgets() != NULL)
   {}
    fgets (line, 222, fpointer);
    printf("%s", line);              //puts(line);
    
    //3rd fread(line, sizeof(char), 222, fpointer);
    while (fread(&personne, sizeof(struct Person), 1, fichier)) {
        printf("%s\n", personne.nom);
    }
    
    //4th
    while(fscanf(f, "%d", &num) != EOF)
*/
    fclose(fpointer);
    system ("color a0");
    return 0;
}
