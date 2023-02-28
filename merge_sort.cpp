/****************************************************************
     ************************ Taima Hamadneh ************************
     ************************   11923521     ************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void mergeSort(int arr[],int l, int r);

void merge(int arr[], int l,int m, int r);
int main()
{

    int size;
    scanf("%d",&size);
    int array[size];
    int count = 0;
    do {
        scanf("%d", &array[count++]);
    } while (getchar() != '\n' && count < size);
 
    mergeSort(array,0 , size-1);
            printf("[");

    for (int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){printf(",");}
        
    }
            printf("]");

    
    return 0;
    
}

void merge(int arr[], int l,
        int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],
            int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

