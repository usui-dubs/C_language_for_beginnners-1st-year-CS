#include<stdio.h>
main()
{	
	 char x, y, z,temp;
	printf("donner les 3 charactére: ");
	//scanf(" %c %c %c",&x,&y,&z); //flhorof lazem dir elespace parceque "entrer" y9raha harf w yhotha fla cas y
	
	/*scanf("%c",&x); 
	//while ((getchar()) != '\n'); // tkhdm m3a getchar brk
	scanf("%c",&y);
	scanf("%c",&z);*/
	
	/*scanf(" %c",&x); 
	fflush(stdin);				//fflush(stdin) fflush(stdout)     	Although using “fflush(stdin)” after “scanf()” statement also clears the input buffer in certain compilers, it is not recommended 
								//flushes the input buffer								to use it as it is undefined behavior by the language standards. In C and C++,
																	we have different methods to clear the buffer discussed in this post.							
	scanf("%c",&y);
	fflush(stdin);
	scanf("%c",&z);*/
	
	/*x = getchar(); 
	fflush(stdin);
	y = getchar();
	fflush(stdin);
	z = getchar();*/
	
	/*x = getchar(); 
	getchar(); 
	y = getchar();
	getchar(); 
	z = getchar();*/
	
	x = getchar(); 
	while ((getchar()) != '\n');
	y = getchar();
	while ((getchar()) != '\n'); 
	z = getchar();
	
	temp=x;
	x=z;
	z=y;
	y=temp;
	printf("la permutation: %c, %c, %c",x,y,z); 
	return 0;
}
