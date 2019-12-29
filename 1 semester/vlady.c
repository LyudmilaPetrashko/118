#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node {
	int a;
	struct _node *next;
} node;

node *create_list (void)
{
    node *head, *p, *q;
    int a;
    printf("a=");
    scanf("%d", &a);
    head=malloc(sizeof(node));
    p=malloc(sizeof( node));
    p->a=a;
    head=p;
    int i;

    while(a!=0){
        q=p;
        printf("a=");
        scanf("%d", &a);
        p->next=malloc(sizeof(node));
        p->next->a=a;
        p=p->next;
    }
    q->next=NULL;
    return head;
}

node * creat_list_rand(void){

    printf("\n\n");
    node *a, *b, *root;
    int r;

    a =  malloc (sizeof(node));
    r=rand()%11-5;
    printf("r=%d\n",r);
    while(r%2==0) {
            r=rand()%11-5;
            printf("r=%d\n",r);
    }

    if(r==0) return NULL;

    a->a=r;
    root=a;

    r=rand()%11-5;
    printf("r=%d\n",r);
    while(r!=0){
        if(r%2==1){
            a=a->next;
            a=malloc(sizeof(node));
            a->a=r;
        }
        r=rand()%11-5;
        printf("r=%d\n",r);
    }

    a->next=NULL;

	return root;
}

void print_list (node *root)
{
	printf("\n\nList:\n");
	int i = 1;

	while (root != NULL)
	{
	 printf("#%d: %d\n", i, root -> a);
	 root = root -> next;
	 i++;
	}
}

void delete_list (node *root)
{
	int i = 0;
	node *a;

	do
	{
	 a = root -> next;
	 free (root);
	 root = a;
	 i++;
	} while (a!= NULL);

	printf("List with %d element(s) was deleted.\n", i - 1);
}



int main(void)
{
	node *root = create_list();
	print_list (root);
	delete_list (root);


	node *l=creat_list_rand();
	print_list (l);
	return 0;
}
