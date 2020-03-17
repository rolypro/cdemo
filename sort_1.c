#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void show_arr(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void select_sort(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        int tmp = i+1;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[tmp])
                tmp = j;
        }
        if (arr[tmp] < arr[i])
            swap(&arr[i], &arr[tmp]);
    }
}

void insert_sort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

//递归快排
void quick_sort_1(int *arr, int start, int end) {
    if (start >= end)
        return;
    int i = start, j = end, index_data = arr[start];
    while (i != j) {
        while (arr[j] >= index_data && i < j) j--; //在j中找一个比index小的  防止i j越界
        while (arr[i] <= index_data && i < j) i++; //在i中找一个比index大的
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[i], &arr[start]); //交换中轴
    quick_sort_1(arr, start, i-1);
    quick_sort_1(arr, i+1, end);
}

//非递归
void quick_sort_2(int *arr, int start, int end) {

}

void adjust_max(int *arr, int head, int n) {
    
    int max_index = head;  //只交换一次就可以
    //左子节点
    if (2*head+1 < n && arr[2*head+1] > arr[max_index]) {
        max_index = 2*head+1;
    }
    
    //右子节点
    if (2*head+2 < n && arr[2*head+2] > arr[max_index]) {
        max_index = 2*head+2;
    }    

    if(head != max_index) {
        swap(&arr[head], &arr[max_index]);
        adjust_max(arr, max_index, n);
    }
}

//大顶堆
void build_max_heap(int *arr, int n) {
    for(int i = n/2-1; i >= 0; i--) {
        adjust_max(arr, i, n);
    }
}

void top_k(int *arr, int n, int *res, int k) {
    for (int i = 0; i < k, res[i] = arr[i]; i++);
    //对res做大顶堆，因为每次根据res[0]对比
    build_max_heap(res, k);

    for(int i = k; i < n; i++) {
        if (arr[i] < res[0]) {  //最小top 大顶堆 0号位比后面的大，所以只能最小top k
            res[0] = arr[i];
            build_max_heap(res, k);
        }
    }

}

//堆排序
void heap_sort_min(int *arr, int n) {    
    build_max_heap(arr, n); //构建大顶堆
    while (n) {        
        swap(&arr[0], &arr[n-1]);        
        --n;
        adjust_max(arr,0,n);
    }
}

void adjust_min(int *arr, int head, int n) {
    int min_index = head;

}



int main() {

    int arr[10] = {12,3,2,44,5};
    int n = 5;

    // select_sort(arr, n);
    // show_arr(arr, n);

    // insert_sort(arr, n);
    // show_arr(arr, n);

    // quick_sort_1(arr, 0, n-1);
    // show_arr(arr, n);

    // heap_sort_min(arr, n);
    // show_arr(arr, n);

    int res[5];
    int k = 3;
    top_k(arr, n, res, k);
    show_arr(res, k);

    system("pause");
    return 0;
}