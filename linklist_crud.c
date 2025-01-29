#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
/*void createnode(int value)
{
    struct node* newnode =(struct node*)malloc(sizeof(struct node))
    newnode->data = value;
    newnode->next=NULL;
    return newnode;
}*/
void insert()
{
    int position, value;
    printf("Enter the position to insert: ");
    scanf("%d", &position);
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (position <= 0)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    if (position == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    struct node *ptr = head;
    for (int i = 1; i < position - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Position is beyond\n");
        struct node *temp = head;
        if (temp == NULL)
        {
            head = newnode;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
    else
    {
        newnode->next = ptr->next;
        ptr->next = newnode;
    }
}
void Delete_at_Begining()
{
    if (head == NULL)
    {
        printf("linklist is empty");
    }
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
}
void Delete_at_end()
{
    if (head == NULL)
    {
        printf("linklist is empty");
    }
    struct node *ptr;
    ptr = head;
    struct node *previous_node;

    while (ptr->next != NULL)
    {
        previous_node = ptr;
        ptr = ptr->next;
    }
    free(ptr->next);
    previous_node->next = NULL;
}
void delete_at_any_position()
{
    int position;
    struct node *previous_node;

    printf("enter the position ");
    scanf("%d", &position);
    struct node *ptr;
    ptr = NULL;
    ptr = head;
    int position_count = 0;
    while (ptr != NULL)
    {
        position_count++;
        ptr = ptr->next;
    }
    if (position_count < position)
    {
        printf("position is not valid");
        return;
    }
    ptr = head;
    for (int i = 1; ptr != NULL && i < position - 1; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    struct node *nodeToDelete;
    nodeToDelete = ptr->next;
    ptr->next = ptr->next->next;
    free(nodeToDelete);
}

void create()
{
    struct node *ptr, *crt;
    ptr = NULL;
    // crt=NULL;
    int num;
    while (scanf("%d", &num) == 1)
    {

        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = num;

        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;

            crt = ptr;
        }

        else
        {
            crt->next = ptr;
            crt = ptr;
        }
        if (getchar() == '\n')
        {

            break;
        }
    }
}

void print()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{

    create();
    print();
    // Delete_at_Begining();
    // Delete_at_end();
    // delete_at_any_position();
    insert();
    print();
    return 0;
}