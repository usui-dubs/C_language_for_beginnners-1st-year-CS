#include <stdio.h>
#include <stdlib.h>

//#define MAX = 100;

typedef struct Queue{
	int  val;
	struct Queue *next;
} Queue;

//Queue *head, *queue ; then fonction parameters has no point

void init(Queue **h, Queue **q)
{
	*q = NULL;
	*h = NULL;
}

int empty_queue(Queue *q)
{
	return q == NULL;
}

void enqueue(Queue **h ,Queue **q, int v) {
	Queue *new;
	new = (Queue*)malloc(sizeof(Queue));
	new -> val = v;
	new -> next =  NULL;
	if(empty_queue(*h)) // *h == NUll
	{
		*q = new;
		*h = new;	
	}
	else
	{
		(*q) -> next = new;
		*q = new;
	}
}
int dequeue(Queue **h, Queue **q, int *v)
{
	Queue *d;
	
	if(*h != NULL)
	{
		*v = (*h) -> val;
		d = *h;
		*h = (*h)->next;
		free(d);
	}
}

void print(Queue *h, Queue *q)
{
	Queue *h1 = h;
	int v;
	
	while(!empty_queue(h1))
	{
		dequeue(&h1, &q, &v);
		printf("%d ", v);
	}
}

int main()
{
	Queue *head, *queue ;
	int v;
	
	/*enqueue(&head, &queue, 5);
	enqueue(&head, &queue, 3);
	enqueue(&head, &queue, 7);
	enqueue(&head, &queue, 2);
	enqueue(&head, &queue, 9);
	
	dequeue(&head, &queue, &v);
	enqueue(&head, &queue, 15);
	dequeue(&head, &queue, &v);
	enqueue(&head, &queue, 4);
	dequeue(&head, &queue, &v);
	dequeue(&head, &queue, &v);
	
	print(head, queue);*/

 int taille=5,i;
   file *f,*q; int val;
   Pile *p,*im;
   init(&p);
   init(&im);
   int *v;
   Init_File(&f,&q);
   for(i=0;i<taille;i++)
   {
       printf("entrer la valeur \t ");
       scanf("%d",&val);
       Enfiler(&f,&q,val);
   }
   while(!File_vide(f))
   {
       if(f->val %2 == 0)
          empiler(&p,f->val);
       else empiler(&im,f->val);
       f=f->suivant;
   }
   printf("\n");
   printf("pile paire ");
   affichepile(p);
   printf("\n");
    printf("pile impaire ");
   affichepile(im);


 return 0
}