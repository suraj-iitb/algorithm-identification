#include <stdio.h>
#define MAX 100000
#define INFTY 1000000000

typedef struct{
  char mark;
  int num;
}Data;

int Partition(Data[], int, int);
void QuickSort(Data[], int, int);
int isStable(Data[] ,Data[],int);
void Merge(Data[], int, int, int);
void MergeSort(Data[], int, int);

int count = 0;
int main(){
  int i, n, judge;
  Data A[MAX],B[MAX];

  scanf("%d%*c",&n);
  for(i=0;i<n;i++){
    scanf("%c %d%*c",&A[i].mark, &A[i].num);
  }
  
  for(i=0;i<n;i++){
    B[i] = A[i];
  }
  /*
  while(flag!=0){ //BubbleSort
    
    flag = 0;
    
    for(j = n-1 ;0 < j ;j--){
      
      if(A[j].num < A[j-1].num){
	tmp = A[j];
	A[j] = A[j-1]; 
	A[j-1] = tmp;

	flag = 1;	
      }
    }
  }
 */
  MergeSort(A, 0, n);
  QuickSort(B,0,n-1);

  judge = isStable(A,B,n);

  if(judge==1)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n", B[i].mark, B[i].num);
  }
  
  return 0;
}

void QuickSort(Data *A, int p, int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    QuickSort(A, p, q-1);
    QuickSort(A, q+1, r);
  }
}
int Partition(Data *A, int p, int r){
  int x, i, j;
  Data tmp;
  
  x = A[r].num;
  i = p - 1;

  for(j=p;j<r;j++){
    if(A[j].num<= x){
      i++;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
  
  return i+1;
}

int isStable(Data A[],Data B[],int n){
  int i;

  for(i=0;i<n;i++){
    if(A[i].mark != B[i].mark) return 0;
  }
  return 1;
}
/*
int isStable(Data in[],Data out[],int n){ //??????????????????isStable
  int i,j,a,b;

  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      for(a=0;a<n;a++){
	for(b=a+1;b<n;b++){
	  if(in[i].num == in[j].num
	     && in[i].mark==out[b].mark && in[i].num==out[b].num
	     && in[j].mark==out[a].mark && in[j].num==out[a].num){
	    return 0; //false
	  }
	}
      }
    }
  }
  return 1; //true
}
*/
void MergeSort(Data *A, int left, int right){
  int mid;

  // printf("left: %d, right: %d\n",left,right);
  
  if(left+1 < right){
    mid = (left + right)/2;
    
    // printf("%d\n\n",mid);
    
    //printf("L-M\n");
    MergeSort(A, left, mid);

    //printf("M-R\n");
    MergeSort(A, mid, right);

    //printf("Merge\n");
    Merge(A, left, mid, right);
  }
}

void Merge(Data *A, int left, int mid, int right){
  int i,j,k;
  int n1, n2;
  Data L[MAX];
  Data R[MAX];
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid+i];
  }

  L[n1].num = INFTY;
  R[n2].num = INFTY;

  i=0;
  j=0;
  
  for(k = left ; k < right ; k++){
    
    count++;
    if(L[i].num <= R[j].num){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}
