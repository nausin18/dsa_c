#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
void printArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}
int main(){
    int arr[10],n,i;
    printf("enter no of elements:");
    scanf("%d", &n);
    printf("enter the elements:\n");
    for(i=0;i<n;i++)
    scanf("%d", &arr[i]);
    printf("array before sort:");
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printf("sorted array:"); 
    printArray(arr,n);
    return 0;

}