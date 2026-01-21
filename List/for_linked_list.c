#include <stdio.h>
#include <stdlib.h>

struct node1
{
    int a;
    struct node1 *link;
};

int main()
{   int temp;
    int length;
    struct node1 *ptr; // pointer to the node
    int count;
    struct node1 *head = malloc(sizeof(struct node1));
    head->a = 0;
    head->link = NULL;

    for (int i = 1; i < 100; i++)
    {
        struct node1 *temp = malloc(sizeof(struct node1));
        temp->a = i;       // assigning value to temp node
        temp->link = head; // linking temp to head
        head = temp;       // linking temp to head
        printf("%d\n", i);
    }
    
    count = 0;
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("Length of list is %d\n", count);

    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    printf("%d",ptr->a);
    ptr->link=temp;


    

    return 0;
} 
