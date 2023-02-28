/****************************************************************
     ************************ Taima Hamadneh ************************
     ************************   11923521     ************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *x, int *y);
void quicksort(int array[], int size);
void quicksort_recursion(int array[], int min, int max);
int divider(int array[], int min, int max);

int main()
{
  
    int size;
    scanf("%d",&size);
    int array[size];
    int count = 0;
    do {
        scanf("%d", &array[count++]);
    } while (getchar() != '\n' && count < size); 
    quicksort(array , size);
            printf("[");
    for (int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){printf(",");}       
    }
            printf("]");    
    return 0;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void quicksort(int array[], int size)
{
  quicksort_recursion(array, 0, size - 1);
}

void quicksort_recursion(int array[], int min, int max)
{
  // stop recursion when min >= max
  if (min < max)
  {
    // cut the array
    int pivot_index = divider(array, min, max);
    //quicksort to the left side 
    quicksort_recursion(array, min, pivot_index - 1);
    //quicksort to the right side 
    quicksort_recursion(array, pivot_index + 1, max);
  }
}

int divider(int array[], int min, int max)
{
  int pivot_index = min + (rand() % (max - min));
  
  if (pivot_index != max)
    swap(&array[pivot_index], &array[max]);
  
  int rootValue = array[max];
  
  int i = min; 
  for (int j = min; j < max; j++)
  {
    if (array[j] <= rootValue)
    {
      swap(&array[i], &array[j]);
      i++;
    }
  }
  swap(&array[i], &array[max]);
  return i;
}
