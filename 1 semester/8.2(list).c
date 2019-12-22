#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_list(void){
    struct node *head, *p, *q;
    int a;
    printf("a=");
    scanf("%d", &a);
    head=(struct node*)malloc(sizeof(struct node));
    p=(struct node*)malloc(sizeof(struct node));
    p->data=a;
    head=p;
    int i;

    while(a!=0){
        q=p;
        printf("a=");
        scanf("%d", &a);
        p->next=(struct node*)malloc(sizeof(struct node));
        p->next->data=a;
        p=p->next;
    }
    q->next=NULL;
    return head;
}

void print_list(struct node* head){
    struct node *q=head;
    int i;
    printf("\n\n");
    for(i=1; q!=NULL; i++){
            printf("#%d:%d\n", i, q->data);
            q=q->next;
    }
}

void delete_list(struct node* head){
    /*struct node *n=head->next;
    free(head);
    while(n!=NULL){
        head=n;
        n=n->next;
        free(head);
    }*/
    struct node *p=head;
    while(head!=NULL){
    p=head->next ;
    free(head);
    head=p;
}
}


int main()
{
    struct node *l=create_list();
    print_list(l);
    delete_list(l);
    return 0;
}
