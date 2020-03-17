/*
堆排序
https://blog.csdn.net/weixin_41190227/article/details/86600821
https://www.cnblogs.com/eudiwffe/p/6202111.html
*/
#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void build_max_heap(int arr[], int n) {
    //从最后一个非叶子节点开始 公式 i = n/2-1
    for (int i = n/2-1; i>=0; i--) {
        adjust_heap(arr, i, n);
    }
}

void adjust_heap(int arr[], int head, int n) {

    int max_index = head;
    //左孩子序号为2*i+1，右孩子序号为2*i+2
    //左子树 
    if (2*head+1 < n && arr[2*head+1] > arr[max_index]) {
        max_index = 2*head+1;
    }

    //右子树
    if (2*head+2 < n && arr[2*head+2] > arr[max_index]) {
        max_index = 2*head+2;
    }

    if(max_index != head) {
        //交换父节点
        swap(&arr[max_index], &arr[head]);
        //调整剩下的节点
        adjust_heap(arr, max_index, n);
    }
}

//大根堆排序
void head_sort(int arr[], int n) {

    if (n<=1) {
        return;
    }

    //构建大根堆
    build_max_heap(arr, n);

    while(n > 0) {
        //把最大的元素放到末尾
        swap(&arr[0], &arr[n-1]);
        adjust_heap(arr, 0, n-1);   //重新构建的时候n-1数组长度-1
        n--;
    }
}

void top_k(int arr[], int n, int res[], int k) {
    //初始化res k个数据
    for(int i = 0; i < k; res[i] = arr[i], ++i);
    //构造res最大堆用来维护top k元素，作为top k的存储空间
    build_max_heap(res,k);
    show_array(res,k);

    //还是得遍历 i > k部分，找出比对顶小的数，那么就有可能是最小top k的数字
    for (int i = k; i < n; i++) {
        if (arr[i] < res[0]) {
            //有可能是top k的数
            res[0] = arr[i];
            build_max_heap(res,k);
        }
    }

}

void show_array(int arr[], int n) {
    for (int i = 0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {12,3,2,44,5};
    int n = 5;
    int k = 5;
    show_array(array, n);

    build_max_heap(array, n);
    show_array(array, n);

    // head_sort(array, n);
    // show_array(array, n);
    
    int res[k];
    top_k(array, n, res, k);
    show_array(res, k);

    system("pause");
}