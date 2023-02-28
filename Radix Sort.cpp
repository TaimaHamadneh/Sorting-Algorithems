/****************************************************************
     ************************ Taima Hamadneh ************************
     ************************   11923521     ************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int get_max(int array[], int size);     
void radix_sort (int array[], int size);
int main (){
    int size;
    scanf("%d",&size);
    int array[size];
    int count = 0;
    do {
        scanf("%d", &array[count++]);
    } while (getchar() != '\n' && count < size); 
    radix_sort(array , size);
            printf("[");
    for (int i=0; i<size; i++){
        printf("%d", array[i]);
        if(i<size-1){printf(",");}       
    }
            printf("]");    
    return 0;
  
}
int get_max (int array[], int size){
   int max = array[0];
   for (int i = 1; i < size; i++)
      if (array[i] > max)
         max = array[i];
   return max;
}

void radix_sort (int array[], int size){
   int bucket[10][10], bucket_cnt[10];
   int i, j, k, r, NOP = 0, divisor = 1, lar, pass;
   lar = get_max (array, size);
   while (lar > 0){
      NOP++;
      lar /= 10;
   }
   for (pass = 0; pass < NOP; pass++){
      for (i = 0; i < 10; i++){
         bucket_cnt[i] = 0;
      }
      for (i = 0; i < size; i++){
         r = (array[i] / divisor) % 10;
         bucket[r][bucket_cnt[r]] = array[i];
         bucket_cnt[r] += 1;
      }
      i = 0;
      for (k = 0; k < 10; k++){
         for (j = 0; j < bucket_cnt[k]; j++){
            array[i] = bucket[k][j];
            i++;
         }
      }
      divisor *= 10;
      
   }
}
