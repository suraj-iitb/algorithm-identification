#include<stdio.h>

void marge(int [],  int, int ,int);
void margeSort( int [],int, int);
int L[250002],R[250002],count;

int main(){

  int left, mid, right,i,j,n1,n2,sumdata;
  int A[500000];

  scanf("%d",&sumdata);

  for(i = 0; i < sumdata; i++){

    scanf("%d",&A[i]);

  }

  margeSort(A,0,sumdata);

  for(i = 0; i < sumdata; i++){

    if(i == sumdata -1){

      printf("%d\n",A[i]);

    }

    else{
    printf("%d",A[i]);
    printf(" ");

    }

  }

  printf("%d\n",count);

  return 0;

}

void marge( int A[], int left, int mid, int right){ /*???????????????????????????????????????????????±???*/

  int n1,n2,i,j,k;

  n1 = mid -left; /*?????????????????????????????????????´???°*/
  n2 = right - mid; /*??????????????????????????????*/

  for(i = 0; i < n1  ; i++){

    L[i] = A[left + i];
  }

  for(i = 0; i <  n2  ; i++){

    R[i] = A[mid + i];
  }

  L[n1] = 2000000000;
  R[n2] = 2000000000;

  i = 0;
  j  = 0;

  for(k = left; k < right  ; k++){

    if(L[i] <= R[j]){

      count = count + 1;

      A[k] = L[i];

      i = i + 1;
      

    }

    else{

      count = count + 1;

      A[k] = R[j];

      j = j + 1;


    }

  }
}

void margeSort( int A[],int left, int right){

  int i,j,mid;

  if(left + 1 < right){

    mid = (left + right) /2;

    margeSort(A,left,mid);
    margeSort(A,mid,right);
    marge(A,left, mid, right);

      }
}
