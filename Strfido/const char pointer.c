#include <stdio.h>
int main() {
   //Example: char const*
   //Note: char const* is same as const char*
   const char p = 'A';
   // q is a pointer to const char
   char const* q = &p;
   //Invalid asssignment
   // value of p cannot be changed
   // error: assignment of read-only location '*q'
   //*q = 'B';
   const char r = 'C';
   //q can point to another const char
   q = &r;
   printf("%c\n", *q);
   //Example: char* const
   char u = 'D';
   char * const t = &u;
   //You can change the value
   *t = 'E';
   printf("%c", *t);
   // Invalid asssignment
   // t cannot be changed
   // error: assignment of read-only variable 't'
   //t = &r;
/*   char * const text = "Hello, World!";
    // this line would result in a compilation error, 
	// since myString is a constant pointer
    //  text = "Goodbye, World!";*/
   //Example: char const* const
   char const* const s = &p;
   // Invalid asssignment
   // value of s cannot be changed
   // error: assignment of read-only location '*s'
   // *s = 'D';
   // Invalid asssignment
   // s cannot be changed
   // error: assignment of read-only variable 's'
   // s = &r;
   return 0;
}
/*
// constant pointer to constant char
const char * const
// constant pointer to char
char * const
// pointer to constant char
const char * or char const*
*/