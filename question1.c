#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    char serverity[100]; 
    struct node*next;
};
 struct node* head=NULL;
 struct node* head1=NULL;
 void create(struct node **head)
 {
    struct node*ptr ,*curr;
    ptr=NULL;
    curr=NULL;
     int id;
    char serverity[100];
    
    int i =0;
    while(scanf("%d ",&id) && scanf("%s",&serverity[i]))
    {
        ptr->id=id;
        ptr->serverity=serverity[i];
        ptr=(struct node*)malloc(sizeof(struct node));
        if(*head==NULL)
        {
            *head=ptr;
            curr=ptr;
        }
        else{
            curr=ptr->next;
            curr=ptr;
        }
        if(getchar()=='\n')
        {
            break;
        }
        i++;

    }




 }
 void newlink()
 {
    struct node * ptr ,*curr, *newp,*prev;
    ptr=NULL;
    curr=NULL;
    newp=NULL;
    prev=NULL;
    ptr=head;
    curr=head1;
    while(ptr!=NULL)
     
    {
        prev=ptr->next;
        while(prev != NULL)
        
        {

        
        if(ptr->serverity=='critical' && ptr->serverity == 'Critical')
        {
            if(head1==NULL)
            {
                head1==curr;
                curr= newp;
            }
            else{
                newp->next=curr;
                curr=newp;
            }
        }
        if(ptr->serverity=='stable' && ptr->serverity == 'Stable')
        {
            if(head1==NULL)
            {
                head1==curr;
                curr= newp;
            }
            else{
                newp->next=curr;
                curr=newp;
            }
        }
        if(ptr->serverity=='Serious'&& ptr->serverity=='serious')
        {
            if(head1==NULL)
            {
                head1==curr;
                curr= newp;
            }
            else{
                newp->next=curr;
                curr=newp;
            }
        }
        prev=prev->next;

    }
    ptr=ptr->next;
 }
 }
//  void sort()
//  {
//     struct node* ptr *prev;
//     ptr=NULL;
//     prev=NULL;
//     ptr=head;
//     while(ptr != NULL)
//     {
//         prev=ptr->next;
//         while(prev != NULL)
//         {
//             if(ptr->serverity)

//         }

//     }

//  }
void display(struct node ** head1)
{
    struct node * ptr;
    ptr=head1;
    while(ptr!=NULL)
    {
        printf("%s",ptr->serverity);
        ptr=ptr->next;
    }
    printf("\n");
}

int main()
{
    create(&head);
    display(head1);
    return 0;

}