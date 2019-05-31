#include "stdio.h"
#include "stdlib.h"

int arr[] = {5,54,1,69,8,47,52,14,63,78};

void print_arr(int *arr, int len)
{
    for (int i=0; i<len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int *a, int first, int mid, int end)
{   
    int leftLen = mid-first+1;
    int rightLen = end-mid;
    int left[leftLen];
    int right[rightLen];
    int i, j, k;

    for (i = first; i<leftLen; i++){
        left[i] = a[first+i];
    }

    for (j = mid; j<rightLen; j++){
        right[j] = a[mid+j+1];
    }

    i = j = 0;
    k = first;

    while (i<leftLen && j<rightLen)
    {
        if (left[i] < right[j]){
            //把左边的放进去
            a[k++] = left[i++];
        }else
        {
            a[k++] = right[j++];
        }        
    }

    //左边没有放
    while (i<leftLen)
        a[k++] = left[i++];
    
    //右边没有放
    while (j<rightLen)
        a[k++] = right[j++];

}

void merge_sort(int arr[], int first, int end)
{
    if (first < end)
    {   
        int mid = (first + end)/2;
        merge_sort(arr,first,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,first,mid,end);
    }
    return;
}

int main()
{   
    int len = 10;
    // int arr[] = {5,54,1,69,8,47,52,14,63,78};
    merge_sort(arr,0,9);
    print_arr(arr,len);
    system("pause");
}

