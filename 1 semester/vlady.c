#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int a;
	struct _node *next;
} node;

node *create_list (void)
{
	node *storage, *b, *root;
	int i = 1, c;

	 storage =  malloc (sizeof(node));
	 if (storage != NULL)
     {
	 printf("element #%d:", i);
	 scanf ("%d", &c);

	 storage -> a = c;
	 storage -> next = NULL;
	 root = storage;

	while (c != 0)

	{
	 i++;
	 printf("element #%d:", i);
	 scanf("%d", &c);
	 if(c==0) break;
	 b = malloc (sizeof(node));
	 if  (b != NULL)
     {
     //a=storage;
	 //printf("element #%d:", i);
	 //scanf("%d", &c);
	 //if(c==0) break;
	 b -> a = c;
	 b -> next = NULL;

	 storage->next=b;
	 storage=b;
     }
     else printf ("No memory allocated");
	}
	//a->next=NULL;
     } else printf ("No memory allocated");
	printf("List with %d element(s) was created.\n", i - 1);
	return root;
}

void print_list (node *root)
{
	printf("List:\n");
	int i = 1;

	while (root  != NULL)
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
	} while (a != NULL);

	printf("List with %d element(s) was deleted.\n", i );
}

int main(void)
{
	node *root = create_list();
	print_list (root);
	delete_list (root);
	return 0;
}
