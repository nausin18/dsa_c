#include<stdio.h>
#include<math.h>
void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<=n-1;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
    printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int arr[10],i,n;
    printf("ENTER NO OF ELEMENTS:");
    scanf("%d", &n);
    printf("ENTER THE ELEMENTS:");
    for(i=0;i<n;i++)
    scanf("%d", &arr[i]);
    printf("ARRAY BEFORE SORT:\n");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("SORTED ARRAY:\n");
    printArray(arr,n);
    return 0;
}