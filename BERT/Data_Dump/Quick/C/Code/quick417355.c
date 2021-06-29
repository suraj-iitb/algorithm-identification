#include<stdio.h>
#include<memory.h>
#define N 100001

typedef struct{
  int A;
  char B;
} card;

card array[N], arrayMarge[N];

int Partition(card *,int, int);
void Quicksort(card *, int, int);
void Merge(card *,int,int,int);
void MergeSort(card *, int, int);

int n;

int main(){

  int i;

  scanf("%d\n",&n);

  for(i = 0; i < n; i++){
    scanf("%c %d\n",&array[i].B,&array[i].A);
  }

  memcpy(arrayMarge,array,sizeof(array));
  Quicksort(array, 0, n-1);
  MergeSort(arrayMarge, 0, n);
  
  if (memcmp(arrayMarge,array,sizeof(array)) == 0) printf("Stable\n");
  else printf("Not stable\n");
  
  for(i = 0; i < n; i++){
    printf("%c %d\n",array[i].B,array[i].A);

  }

   return 0;
	
}

int Partition(card *A, int p, int r){

  int i,j,x;
  card T;
 
  x = A[r].A;
  i = p-1;

  for(j = p; j < r; j++){
    
    if(A[j].A <= x){
		i = i + 1;
		T = A[i]; 
		A[i] = A[j];
		A[j] = T;
	}
	  
  }
      T = A[i+1]; 
      A[i+1] = A[r];
	  A[r] = T;
      return i + 1;
	
}


void Quicksort(card *A, int p, int r){
  
  int q;  
  
  if(p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
  
} 
 
void Merge(card *T,int left,int mid,int right){
    
  int i, j = 0, k;
  int n1 = mid - left;
  int n2 = right - mid;
  card L[N], R[N];
   
  for (i = 0; i < n1; i++){
    L[i] = T[left + i];
  }
   
  for(i = 0; i < n2; i++){
    R[i] = T[mid + i];
  }

  L[n1].A=1000000000;
  R[n2].A=1000000000;
  
	i = 0;
	j = 0;
	
  for(k = left; k < right; k++){
    if (L[i].A <= R[j].A){
      T[k] = L[i];
      i = i + 1;
    } else {
      T[k] = R[j];
      j = j + 1;
    }
  }
   
}
 
void MergeSort(card *A, int left, int right){

  int mid = 0;

  if(left + 1 < right){
    mid = (left + right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
   
}
