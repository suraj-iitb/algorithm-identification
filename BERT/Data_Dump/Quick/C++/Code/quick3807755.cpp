#include "stdio.h"

struct Card{
  char suit;
  int value;
};

void merge(Card matrix[], int left, int mid, int right){
  int n1,n2;
  n1 = mid - left;
  n2 = right - mid;

  Card* Left = new Card [n1+1];
  Card* Right = new Card [n2+1];

  for(int i=0;i<n1;i++){
    Left[i] = matrix[left+i];
  } 
  for(int a=0;a<n2;a++){
    Right[a] = matrix[mid+a];
  }

  Card max;
  max.suit = 'M';
  max.value = 2000000000;
  Left[n1] = max;
  Right[n2] = max;

  int i=0;
  int j=0;

  for(int k=left;k<right;k++){
    if(Left[i].value <= Right[j].value){
      matrix[k] = Left[i];
      i++;
    }else{
      matrix[k] = Right[j];
      j++;
    }
  }
  
  delete [] Left;
  delete [] Right;

}

void mergeSort(Card matrix[], int left, int right){
  if( left + 1 >= right){
    return;
  }
  
  int mid;
  mid = (int)( (left+right)/2.0 );

  mergeSort(matrix, left, mid);
  mergeSort(matrix, mid, right);
  merge(matrix, left, mid, right);
}

int partition(Card matrix[], int p, int r){
  int i;
  int j;
  i = p-1;

  Card standard = matrix[r];

  Card temp;
  for(j=p;j<r;j++){
    if(matrix[j].value <= standard.value){
      i = i + 1;
      temp = matrix[i];
      matrix[i] = matrix[j];
      matrix[j] = temp; 
    }     
  }  
  
  temp = matrix[i + 1];
  matrix[i+1] = matrix[r];
  matrix[r] = temp;

  return i+1;
}

void quickSort(Card matrix[], int p, int r){
  if(p < r){
    int q = partition(matrix, p, r);
    quickSort(matrix, p, q-1);
    quickSort(matrix, q+1, r);
  }
}

bool isSameMatrix(Card matrix1[], Card matrix2[], int N){
  for(int i=0;i<N;i++){
    if(matrix1[i].suit != matrix2[i].suit ){
      return false;
    }
  }
  return true;
} 

void outputMatrix(Card matrix[], int N){
  for(int i=0;i<N;i++){
    printf("%s %d\n", &(matrix[i].suit), matrix[i].value);
  }
}


int main(void){

  int N;
  scanf("%d", &N);

  Card* matrix1 = new Card [N];
  Card* matrix2 = new Card [N];

  for(int i=0;i<N;i++){
    scanf("%s %d", &(matrix1[i].suit), &(matrix1[i].value));
    matrix2[i] = matrix1[i];
  }

  mergeSort(matrix1, 0, N);
  quickSort(matrix2, 0, N-1);

  if(isSameMatrix(matrix1, matrix2, N)){
    printf("Stable\n");
  }else{
    printf("Not stable\n");
  }

  outputMatrix(matrix2, N);

  delete [] matrix1;
  delete [] matrix2;

  return 0;
}
