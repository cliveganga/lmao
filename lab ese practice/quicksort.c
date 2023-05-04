#include <stdio.h>
void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]= temp;
}

int partition(int *arr, int l , int r)
{
    int pivot =  l;
    int p = l+1;
    int q = r;
    while(p<q)
    {
        while(arr[p]<arr[pivot])
        {
            p++;
        }
        while(arr[q]>arr[pivot])
        {
            q--;
        }
        if(p<q)
        {
            swap(arr, p, q);
        }
    }
    swap(arr, pivot, q);
    return q;
}



void quickSort(int *arr, int l, int r)
{
    if(l < r){
        int m = partition(arr, l, r);
        quickSort(arr, l, m-1 );
        quickSort(arr, m+1, r);
        
        
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
    quickSort(arr, 0, n-1);
    for(int i = 0; i< n; i++)
    {
        printf(" %d", arr[i]);
    }

}