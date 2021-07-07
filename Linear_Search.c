#include<stdio.h>
  
int main()
{
    int size;
    printf("Enter size of Array : ");
    scanf("%d", &size);
    int a[size],i,x;
     
    printf("Enter %d elements : ",size);
    for(i=0; i<size; ++i){
        scanf("%d",&a[i]);
    }
    printf("Enter element to search : ");
    scanf("%d",&x);
     
    for(i=0; i<size; ++i){
        if(a[i] == x){
            break;
        }
    }
     
    if(i<size){
        printf("Element found at index %d",i+1);
    }else{
        printf("Element not found");
    }
    return 0;
}