#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void insertion_sort(int array[], int lenght);
int main() {
    /****************************************************************
     ************************ Taima Hamadneh ************************
     ************************   11923521     ************************/
  //  printf("Enter the size of the array : ");
    int size;
    scanf("%d",&size);
    int array[size];
    //printf("The values you want to sort it (numbers seperated by spaces): \n");
    int count = 0;
    do {
        scanf("%d", &array[count++]);
    } while (getchar() != '\n' && count < size);
 
    insertion_sort1(array , size);
            printf("[");

    for (int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){printf(",");}
        
    }
            printf("]");

    
    return 0;
}
void insertion_sort1(int array[] , int length){
    for(int i=1 ; i<length ;i++){
        int j = i;
        
        while(j>0 && array[j-1]>array[j]){
            int tmp =array[j-1];
            array[j-1]= array[j];
            array[j]=tmp;
            j-=1;
        }
    }
}


