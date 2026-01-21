#include <stdio.h>
#include <stdlib.h>

struct node1
{
    int a;
    struct node1 *link;
};

int main()
{
    struct node1 *head = malloc(sizeof(struct node1)); //creating head node
    head->a = 45;         
    head->link = NULL;
   printf("%d\n", head->a);

    struct node1 *head1 = malloc(sizeof(struct node1));  //creating head1 node
    head1->a=60;                                         //assigning value to head1 node
    head1->link=NULL;                                    //assigning NULL to link of head1 node
    head->link=head1;                                    //linking head1 to head
    printf("%d\n", head1->a);

     struct node1 *head2 = malloc(sizeof(struct node1));
    head2->a=77;
    head2->link=NULL;
    head2->link=head1;

    //  struct node1 *head1 = malloc(sizeof(struct node1));
    // head1->a=60;
    head1->link=NULL;          
    head2->link=head;               //linking head2 to head 1. This is circular linked list!!!

    return 0;
}
