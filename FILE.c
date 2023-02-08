#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE * fpointer = fopen("/download/test.html","w");//write 
    
    fprintf(fpointer, "nsit html hh\nidk");
    
    fpointer = fopen("/download/test.html","a");//append 
    
    fprintf(fpointer, "\n جمال الروح يفدينا");
    
    char line[222];
    
    fpointer = fopen("/download/test.html","r");
    
    fgets (lign, 222, fpointer);
    printf("%s", line);
    
    //fpointer++ happens
    fgets (lign, 222, fpointer);
    printf("%s", line);
    
    fclose(fpointer);
    return 0;
}