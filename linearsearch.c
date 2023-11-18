#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,a[10],x,flag=0;
    printf("Enter the no of elements:");
    scanf("%d",&n);
    printf("Enter the %d elements:", n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched:");
    scanf("%d", &x);
    for(i=0;i<n;i++){
        if(x==a[i]){
            flag=1;
            break;
        }
    }
    if(flag==0)
    printf("ELEMENT NOT FOUND");
    else
        printf("ELEMENT FOUND AT POSITION %d", i);
    getch();
}