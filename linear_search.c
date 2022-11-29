#include<stdio.h>

int main(){
    int i,key,n, arr[20];
    printf("How many elements ? : ");
    scanf("%d",&n);
    printf("Enter array elements : ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched : ");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i] == key && i<n){
            printf("Element found at index : %d ", i);
            break;
        }
    }
    if(i == n){
        printf("Element not found \n");
    }
    return 0;
}