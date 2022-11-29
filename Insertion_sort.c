#include<stdio.h>

int insertionSort(int a[], int n){
    int i,j,temp;

    for(i=1;i<n;i++){
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = temp;
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

    insertionSort(arr, n);
    printf("Sorted array is : ");
    printArray(arr,n);
	return 0;
}