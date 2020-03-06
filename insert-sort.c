#include "stdio.h"
#include "stdlib.h"

void insertSort(int arr[], int length) {

    for (int i = 1; i < length; i++) {
        int index = i;      //指向要排序的值
        int current = arr[i];

        while (index > 0 && arr[index-1] > current) {
            //交换
            arr[index] = arr[index-1]; 
            index--;
        }

        arr[index+1] =  current;
    }
}

void showArray(int arr[], int length) {
    
    for (int i = 0; i<length; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[10] = {10,2,32,4,51,6,12,1,5,100};
    int length = 10;
    showArray(arr, length);
    system("pause");
    return 0;
}
