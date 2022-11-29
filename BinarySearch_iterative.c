#include<stdio.h>

int BinarySearch(int arr[],int n, int key){
    int low = 0, high = n-1;
    
    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == key){
            return key;
        } else if(key<arr[mid]){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

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

    int result = BinarySearch(arr, n , key);

    if(result == -1){
        printf("The element is not present in array");
    } else {
        printf("The element is present at index %d",result);
    }
    return 0;
}