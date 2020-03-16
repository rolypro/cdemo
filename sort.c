#include "stdio.h"
#include "stdlib.h"

#define MAX_ARR_LEN 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printf_arr(int arr[],int len)
{
    for (int i=0; i<len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insert_sort(int arr[],int len)
{   
    int i,j,temp;
    
    for(i = 1; i<len; i++)
    {
        temp = arr[i];
        for(j=i; j>0 && arr[j-1] > temp ; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
    printf("-------insert_sort-------\n");
    printf_arr(arr,len);    
}

void select_sort(int arr[], int len)
{
    int i, j, k;
    for (i=0; i<len-1; i++)
    {
        int min = i;
        for (j=i+1; j<len; j++)
        {
            if (arr[j] < arr[min])
            {
                k = min;
            }
            swap(&arr[i],&arr[min]);
        }
    }
    printf("-------select_sort-------\n");
    printf_arr(arr,len);
}


int main()
{
    int arr[MAX_ARR_LEN] = {55,9,66,78,52,1,62,87,123,2};
    insert_sort(arr,MAX_ARR_LEN);
    select_sort(arr,MAX_ARR_LEN);


    system("pause");
    return 0;
}