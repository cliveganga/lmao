#include <stdio.h>

void merge(int *arr, int l , int m, int r)
{
    int leftSize = m-l+1;
    int rightSize = r - m;
    int leftArr[leftSize], rightArr[rightSize];
    for(int i =0; i< leftSize; i++)
    {
        leftArr[i] = arr[l+i];
    }
    for(int i =0; i< rightSize; i++)
    {
        rightArr[i] = arr[m+1+i];
    }
    printf("\nLeft array before | Right before\n");
    for(int i = 0; i< leftSize; i++)
    {
        printf(" %d", leftArr[i]);
    }
    printf(" | ");
    for(int i = 0; i< rightSize; i++)
    {
        printf(" %d", rightArr[i]);
    }
    int k = l;
    int i =0, j = 0;
    while(i<leftSize && j < rightSize)
    {
        if(leftArr[i]< rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i<leftSize)
    {
       arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j<rightSize)
    {
       arr[k] = rightArr[j];
            j++;
        k++;
    }
    printf("\n after\n");
    for(int i = l; i< r+1; i++)
    {
        printf(" %d", arr[i]);
    }

    
}



void mergeSort(int *arr, int l, int r)
{
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l , m, r);
        
    }
    
}

void main()
{
    int n;
    printf("Entere size of array:");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter Elements:\t");
    for(int i = 0; i< n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n-1);
    for(int i = 0; i< n; i++)
    {
        printf(" %d", arr[i]);
    }

}