#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <limits.h>

#define SIZE 10
void mergeSort(int arr[], int i_st, int i_end){
 printf("%d ", i_st);
 printf("%d \n", i_end);
 int i_mid=floor((i_st+i_end)/2);
 if (i_st<i_end){
  mergeSort(arr,i_st,i_mid);
  mergeSort(arr,i_mid+1,i_end);
 
  /*
  printf("total(%d~%d):",i_st,i_end);
  for (int i = i_st; i <= i_end ; i++) 
  {
    printf("%d ", arr[i]);
  }
  printf("\n" );*/

  //生成左陣列
  printf("L: " );
  int L[i_mid-i_st+1];
  for (int i = 0; i <= i_mid-i_st ; i++) 
  {
    L[i]=arr[i+i_st];
    printf("%d ", L[i]);
  }
  printf("\n" );

  //生成右陣列
  printf("R: " );
  int R[i_end-i_mid];
  for (int i = 0; i <= i_end-(i_mid+1) ; i++) 
  {
    R[i]=arr[i+(i_mid+1)];
    printf("%d ", R[i]);
  }
  printf("\n" );
  //Buttom up使左右陣列都已完成升冪排列
  //比較左陣列或右陣列未排列的第一個元素大小並排進arr[i] 
  //因升冪機制，未排列的第一個元素就是該陣列最小元素

  int i_st_L = 0;//當前L_array未排列的最小元素號碼
  int i_end_L = i_mid-i_st;
  int i_st_R = 0;//當前R_array未排列的最小元素號碼 
  int i_end_R = i_mid-i_st;
 
  printf("Merge: ");
  for (int i = i_st; i <= i_end; i++) 
  {

        if (L[i_st_L]<R[i_st_R]) {
          arr[i]=L[i_st_L];
          if ((i_st_L+1)<=i_end_L){i_st_L=i_st_L+1;}
          else{L[i_st_L]=INT_MAX;}
          printf("%d ", arr[i]);}
        else {
          arr[i]=R[i_st_R];
          if ((i_st_R+1)<=i_end_R){i_st_R=i_st_R+1;}
          else{R[i_st_R]=INT_MAX;}
          printf("%d ", arr[i]);}
      
                         
  }
  



  printf("\n" );


 }



}



/* Feel free to utilize any libraries of your choice. */



int main() {
  int arr[SIZE] = {20, 7, 17, 14, 8, 3, 18, 3, 14, 1};

  
  mergeSort(arr,0,9);
  for (int i = 0; i < SIZE; ++i)
    printf("%d ", arr[i]);
  
  return 0;
}