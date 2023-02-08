#include <stdio.h>
#include <string.h>
#define NUMBER_OF_STRINGS 20
#define MAX_STRING_SIZE 100


bubble_sort(int N, char string[N][MAX_STRING_SIZE])
{
    int i,j,b=1,k;
    for(i=0; i<N-1 && b==1; i++) //for(i=N-1; i>0; i--)
    {
        b=0;
        for(j=0; j<N-i-1; j++) //for(j=0; j<i; j++) 
        {
            if(string[j][0] > string [j+1][0])
            {
                char temp[MAX_STRING_SIZE];
                strcpy(temp, string[j+1]);
                strcpy(string [j+1], string [j]);
                strcpy(string [j], temp);
                b=1;
            }
        }      
    }
}
    
string_binary_search(int N, char string[N][MAX_STRING_SIZE], char x[MAX_STRING_SIZE])
{
    int start, end, mid;
    start = 0;
    end = N-1;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        if (strcmp(string [mid], x) == 0 )
            return mid;
        else if (string[mid][0] > x[0])
        {
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return -1;
}    
    
int main()
{
    char string[NUMBER_OF_STRINGS][MAX_STRING_SIZE] ;// = { 9,6,5,7,3,1,2,8,4 } ;
    int i, N;
    char temp; //to clear the buffer
    
    do
    {
    printf("Write the number of strings : ");
    scanf("%d", &N);
    scanf("%c", &temp);
    } while(N <= 0 || N > NUMBER_OF_STRINGS);
    printf("Write the strings : \n");
    
    for(i = 0; i < N; i++)
    {
        printf("string[%d] = ", i);
        //scanf("%s", string [i]); //doesn't work with spaces
        fgets(string[i],MAX_STRING_SIZE,stdin);
        //scanf("%[^\n]%*c", &string[i]); //works with the %[^\n] down here 
    }
    
    bubble_sort(N, string);
    
    printf("\n\n\n Your sorted array of strings (ton trieé chains de caracters ) :");
    for(i=0; i<N; i++)
        printf("string number %d : %s \n",i+1, string[i]);
        
    char x[MAX_STRING_SIZE];   
    int pos;
    
    do
    { 
    printf("enter the string you are searching : ");
    //scanf("%[^\n]",x);
    fgets(x,MAX_STRING_SIZE,stdin); //works with the fgets above, that's because fgets adds a new line to the array 
    
    pos = string_binary_search(N, string, x);
    
    if(pos != -1)
        printf("the string (%s) exist in the %d string of the sorted array ", string [pos], pos +1);
    
    else printf("the string you are searching for doesn't exist, please be presise, try again: \n\n");
    } while(pos == -1);
}