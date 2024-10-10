#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node *next;
} node ;

node *head;

void init( node **h)
{
	*h = NULL;
}

void sorted_insertion(node **h, int x)
{
	node *new, *prec, *p;
	
	new = (node*)malloc(sizeof(node));
	new -> val = x;
	
	if(*h == NULL || *h != NULL && (*h) -> val >= x  )
	{
		new -> next = *h;
		*h = new;
	}
	else
	{
		p = *h;
		while(p != NULL && p -> val < x )
		{
			prec = p;
			p = p -> next;
		}
		
		new -> next = p;
		prec -> next = new;
	}
	
}

void supression(node **h, int x)
{
    node *p, *precedent;
    
    if(*h != NULL)
    {
        if ((*h) -> val == x ) //**t
        {
            p = *h;
            *h = (*h) -> next; // p -> suivant 
            free (p);
        }    
        else
        {
           // precedent = *t;
         //   p = (*t) -> suivant ;//(*prec) -> suivant
            /*liste *prec; */
            p=*h ;
            while(p != NULL && p -> val != x)
            {
                precedent = p ;
                p = p -> next;
            }
            
            if(p != NULL) //if(prec -> suivant = NULL)
            {
                precedent -> next = p -> next ;
                free (p);
            }
            else 
                printf("doesn't exist\n");
        }
        
    }
    
   
}
void printList(node *h)
{
	node *p = h;
	
	while(p != NULL)
	{
		printf("%d \n", p -> val);
		p = p -> next;
	}
}

int main()
{
	init(&head);
	int num, del;
	char c, temp;
	
	printf("enter the first elem of the linked list :");
	scanf("%d", &num);
	sorted_insertion(&head, num);
	
	do
	{
		printf("Do you want to add another elem y/n ? :");
		scanf("%d", &temp);
		scanf("%c", &c);
	
		if(c == 'y')
		{
			printf("enter the next elem of the linked list :");
			scanf("%d", &num);
			sorted_insertion(&head, num);
		}
	} while (c == 'y');
	
	printf("your linked list:");
	printList(head);
	
	do
	{
		printf("Do you want to delete an elem y/n ? :");
		scanf("%d", &temp);
		scanf("%c", &c);
	
		if(c == 'y')
		{
		  printf("what do you want to delete: ");
   	scanf("%d", &del);
 
    supression (&head, del);
    if (head != NULL) 
    {
        printf("your list after deletion : ");
        printList(head) ; 
    }
     else puts(" \n empty list");
		}
	} while (c == 'y' && head != NULL);
}