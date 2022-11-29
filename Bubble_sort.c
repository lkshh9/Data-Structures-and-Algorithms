#include<stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int a[],int n){
    for(int i=0;i<n-1;i++){
        int flag = 0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void printArray(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main() {
    int i,n, arr[20];

    printf("How many elements ? : ");
    scanf("%d",&n);

    printf("Enter array elements : ");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    bubble(arr, n);
    printf("Sorted array is : ");
    printArray(arr,n);
	return 0;
}
