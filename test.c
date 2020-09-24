#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
void create(int data)
{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->next=head;
        head=temp;
}

void position(int data,int position)
{
        struct node *ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        int i;
        struct node *temp=head;
        for(i=1;i<position-1;i++)
            temp=temp->next;
         ptr->next=temp->next;
        temp->next=ptr;

}

void printlist()
{
        struct node *temp=head;
        while(temp!=NULL)
        {
                printf("%d ",temp->data);
                temp=temp->next;
        }
}

int main()
{
    int i;
    int list[10]={10,9,8,7,6,5,4,3,2,1};
        for(i=0;i<10;i++)
            create(list[i]);
    printf("\nThe list present: \n");
    printlist();
    position(20,5);
    printf("\nThe new list after insertion: \n");
    printlist();

        return 0;
}
