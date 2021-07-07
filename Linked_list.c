#include<stdlib.h>
#include <stdio.h>
     
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
 
 
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;

int main(){
    int choice;
    while(1){           
        printf("\n                MENU                           \n");
        printf("\n 1.Create\n");
        printf("\n 2.Display\n");
        printf("\n 3.Insert at the beginning\n");
        printf("\n 4.Insert at the end\n");
        printf("\n 5.Insert at specified position\n");
        printf("\n 6.Delete from beginning\n");
        printf("\n 7.Delete from the end \n");
        printf("\n 8.Delete from specified position\n");
        printf("\n 9.Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create();
            break;

            case 2:
            display();
            break;

            case 3: 
            insert_begin();
            break;

            case 4:
            insert_end();
            break;

            case 5:
            insert_pos();
            break;

            case 6:
            delete_begin();
            break;

            case 7:
            delete_end();
            break;

            case 8:
            delete_pos();
            break;
                        
            case 9:
            exit(0);
            break;
                             
            default:
            printf("\n Wrong Choice:\n");
            break;
        }
    }
    return 0;
}
void create()
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nOut of Memory Space:\n");
        exit(0);
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nList is empty:\n");
        return;
    }else{
        temp=head;
        printf("\nThe List elements are:\n");
        while(temp!=NULL){
            printf("%d\t",temp->data );
            temp=temp->next ;
        }
    }
}
void insert_begin()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node: " );
    scanf("%d",&newnode->data);
    newnode->next =NULL;
    if(head==NULL){
        head=newnode;
    }else{
        newnode->next=head;
        head=newnode;
    }
}
void insert_end(){
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:");
    scanf("%d",&newnode->data );
    newnode->next =NULL;
    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->next !=NULL){
            temp=temp->next ;
        }
        temp->next =newnode;
    }
}
void insert_pos()
{
    struct node *temp,*newnode;
    int i,pos;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted: ");
    scanf("%d",&pos);
    printf("\nEnter the data value of the node: ");
    scanf("%d",&newnode->data) ;
  
    newnode->next=NULL;
    if(pos==0){
        newnode->next=head;
        head=newnode;
    }else{
        for(i=0,temp=head;i<pos-1;i++){
            temp=temp->next;
            if(temp==NULL){
                printf("\nPosition not found:[Handle with care]\n");
                return;
            }
        }
        newnode->next =temp->next ;
        temp->next=newnode;
    }
}
void delete_begin()
{
    struct node *temp;
    if(temp==NULL){
        printf("\nList is Empty:\n");
        return;
    }else{
        temp=head;
        head=head->next ;
        printf("\nThe deleted element is :%d ",temp->data);
        free(temp);
    }
}
void delete_end()
{
    struct node *newnode,*temp;
    if(head==NULL){
        printf("\nList is Empty:");
        exit(0);
    }
    else if(head->next ==NULL){
        temp=head;
        head=NULL;
        printf("\nThe deleted element is:%d\t",temp->data);
        free(temp);
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            newnode=temp;
            temp=temp->next;
        }
        newnode->next=NULL;
        printf("\nThe deleted element is:%d\t",temp->data);
        free(temp);
    }
}
void delete_pos()
{
    int i,pos;
    struct node *newnode,*temp;
    if(head==NULL)
    {
        printf("\nThe List is Empty:\n");
        exit(0);
    }
    else
    {
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d",&pos);
        if(pos==0)
        {
            temp=head;
            head=head->next ;
            printf("\nThe deleted element is:%d\t",temp->data  );
            free(temp);
        }else{
            temp=head;
            for(i=0;i<pos;i++){
                newnode=temp; temp=temp->next ;
                if(temp==NULL){
                    printf("\nPosition not Found:\n");
                    return;
                }
            }
            newnode->next =temp->next ;
            printf("\nThe deleted element is:%d\t",temp->data );
            free(temp);
        }
    }
}
