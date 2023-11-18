#include<stdio.h>
int binarySearch(int array[], int x, int low, int high){
  while(low<=high){
    int mid=low+(high-low)/2;
    if(array[mid]==x)
    return mid;
    if(array[mid]<x){
      low=mid+1;
    }
    else
    high=mid-1;
  }
  return -1;
}
int main(void){
  int i,n,x,array[100];
  printf("enter no. of elements:");
  scanf("%d", &n);
  printf("enter the %d elements:",n);
  for(i=0;i<n;i++){
    scanf("%d", &array[i]);
  }
  printf("enter the element to search:");
  scanf("%d", &x);
  int result=binarySearch(array,x,0,n-1);
  if(result==-1)
  printf("element not found");
  else
  printf("element found at position %d", result);
  return 0;
}