#include <stdio.h>

void insertionSort(int n, int *arr)
{
    for(int j =  1; j<n ;j++)
    {
        int key = arr[j];
        int i = j-1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1]= key;
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
    insertionSort(n, arr);
    for(int i = 0; i< n; i++)
    {
        printf(" %d", arr[i]);
    }

}