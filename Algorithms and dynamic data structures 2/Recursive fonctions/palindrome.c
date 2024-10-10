#include <stdio.h>
#include <string.h>
#define MAX 100

int palindrome ( char str[MAX], int left, int right)
{
    if(left >= right)
        return 1;
    if(str[left] != str[right])
        return 0;
    return palindrome (str, left + 1, right - 1);


    /*if(NULL == str || l < 0 || r < 0){

         return 0;

     }

     if(l >= r)

         {

             return 1;

         }

     if(str[l] == str[r]){

         return isPalindrome(str, l + 1, r - 1);

     }

     return 0;*/
    
    /* for(i = 0, j = len - 1; i < j; i++, j--)
    {
        if(str[i] != str[j]) //if (str[i++] != str[j--])
            return 0;
            //if(str[i]==str[len-i-1]) com++ //i<len /2
    }        
    return 1 ;*/
 }   
     
int main()
{
    char str[MAX];
    int l, i = 0;
    
    do
    {
        printf("Enter the string : ") ;
        gets (str) ;
        l = strlen(str);
   } while(l <= 0 || l >= MAX) ;
    
    if(palindrome (str, i, l - 1))
        printf("Palindrome");      
    else
        printf("not palindrome");      
            
}