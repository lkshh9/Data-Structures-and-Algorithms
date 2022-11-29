#include <stdio.h>

int binaryScr(int a[], int low, int high, int m) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
    if (a[mid] == m)
        return mid;
    if(a[mid] > m)
        return binaryScr(a, low, mid - 1, m);
        return binaryScr(a, mid + 1, high, m);
    }
    return -1;
}
int main() {
    int i,key,n, arr[20];

    printf("How many elements ? : ");
    scanf("%d",&n);

    printf("Enter array elements : ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter element to be searched : ");
    scanf("%d",&key);

    int result = binaryScr(arr, 0, n - 1, key);
    
    if(result == -1){
        printf("The element is not present in array");
    } else {
        printf("The element is present at index %d",result);
    }

    return 0;
}