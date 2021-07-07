#include<stdio.h>
#include<stdlib.h>
#define N 5

int top = -1;
int stack[N];

void push(int item);
int pop();

int main()
{
    int item, choice, cont = 1;
    while(cont == 1){
        printf("-----------Menu-----------\n");
        printf("\n1.Push onto stack.\n");
        printf("\n2.Pop from stack.\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("\nEnter the value of item:");
            scanf("%d",&item);
            push(item);
            break;

            case 2:
            item = pop();
            if(item != 0){
                printf("\nItem poped out : %d\n",item);
            }                
            break;

            default:
            printf("\nInvalid choice.\n");
            break;
        }
        printf("\nDo you want to continue (1,0): \n");
        scanf("%d",&cont);
    }
    return 0;
}

void push(int item)
{
    if(top >= N-1){
        printf("\nStack Overflow. Push not possible.\n");
    }else{
        top = top+1;
        stack[top] = item;
    }
}

int pop()
{
    int item = 0;
    if(top == -1){
        printf("\nStack Underflow. Pop not possible.\n");
    }else{
        top = top-1;
        item = stack[top+1];
        stack[top+1]=0;
    }
    return(item);
}