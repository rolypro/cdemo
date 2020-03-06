#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int arr[], int low, int height) {
    if (low > height) 
        return;

    int i = low, j = height;
    int tmp = arr[i];
    while (i!=j) {
        while(arr[j] >= tmp && j > i) j--;    //在高位找到一个比基准小的值
        while(arr[i] <= tmp && j > i) i++;    //在低位找到一个比基准大的值
        if (i<j) {
            //交换
            swap(&arr[i], &arr[j]);
        }
    }
    //i == j
    swap(&arr[i], &arr[low]);
    quick_sort(arr, low, i-1);
    quick_sort(arr, i+1, height);
}

void show_array(int arr[], int n) {
    for (int i = 0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    
    int array[10] = {11,33,5,44,8,1,33,65,47,52};
    int n = 10;
    quick_sort(array, 0, n-1);
    show_array(array, n);
    system("pause");
    return 0;
}
