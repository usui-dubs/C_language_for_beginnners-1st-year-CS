#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int val;
	struct stack *prec;
} stack;

stack *p;

void init(stack **s)
{
	*s = NULL;
}

int emptyStack(stack *s)
{
	return (s == NULL);
}

int stack_summit(stack *s)
{
	if(s != NULL)
		return (s -> val);
}

void push(stack **s, int v)
{
	stack *new;
	init(&new);
	
	new = (stack*)malloc(sizeof(stack));
	new -> val = v;
	new -> prec = *s;
	*s = new;
}

void pop(stack **s, int *v)
{
	stack *d;
	init(&d);
	
	if(*s != NULL)
	{
		d = *s;
		*v = (*s) -> val;
		*s = (*s) -> prec;
		free(d);		
	}	
}

void posNegStack(stack *s, stack **pos, stack **neg)
{
	int v;
 stack *s1;
 init(&s1);
	/*stack *s1 = s;
	
	while(!emptyStack(s1))
	{
		pop(&s1, &v);
		if(v >= 0)
			push(pos, v);
		else
			push(neg, v);
	}*/
 
 while(!emptyStack(s))
	{
		pop(&s, &v);
		if(v >= 0)
			push(pos, v);
		else
			push(neg, v);
  push (&s1, v);
	}

 while(!emptyStack(s1))
	{
		pop(&s1, &v);
  push (&s, v);
	}

}

void printStack(stack *s)
{
	stack *s1 = s;
	int v;
	while(s1 != NULL)
	{
		pop(&s1, &v);
		printf("%d ", v);
	}
}

int main(void)
{
	int num;
	char c, temp;
	init(&p);
	
	printf("Enter the first elem: ");
 scanf("%d", &num);
	push(&p,num);
	
	do
	{
		printf("do you want to Enter another elem? IF Yes print y :");
		scanf("%d", &temp);
		scanf("%c", &c);
		if(c == 'y')
		{
			printf("Enter :");
			scanf("%d", &num);
			push(&p,num);
		}
	} while (c == 'y');
	
	printf("your stack : \n");
	printStack(p);
	
 stack *pos,*neg;
 init(&pos);
 init(&neg);

	posNegStack(p, &pos, &neg);
	
 printf("\nPositive elements : ");
	printStack(pos);
	printf("\nnegative :");
	printStack(neg);	

	return 0;
}
    