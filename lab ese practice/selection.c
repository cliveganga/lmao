#include <stdio.h>

void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]= temp;
}

void selectionSort(int n, int *arr)
{
    for(int j =  0; j<n ;j++)
    {
        int min = j;
        for(int i = j+1;i<n;i++){
            if(arr[i]< arr[min])
            {
                min = i;
            }
        }
        if(min != j)
            swap(arr, min, j);
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
    printf("\nSorted Elements");
    selectionSort(n, arr);
    for(int i = 0; i< n; i++)
    {
        printf(" %d", arr[i]);
    }

}