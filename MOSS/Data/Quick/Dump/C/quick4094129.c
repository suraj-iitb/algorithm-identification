#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 1e9
#define SIZE 100000

typedef struct{
  char mark;
  int num;
}card;

/*マージソートを用いて安定かどうかを判断する*/

void QuickSort(card *,int,int);
void merge(card *,int,int,int);
void MergeSort(card *,int,int);
int Partition(card *,int,int);
void swap(card *,card *); 


int main(){
  int n,i,check=1;
  card A[SIZE],B[SIZE]; /*BはAと比較するための配列*/
  scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf(" %c%d",&A[i].mark,&A[i].num);
    B[i] = A[i];
  }
  
  QuickSort(A,0,n-1);
  MergeSort(B,0,n);

  /*比較をした結果安定でないならcheckを0にする*/
  for(i=0; i<n; i++){
    if(A[i].num != B[i].num || A[i].mark != B[i].mark){
      check = 0;
      break;
    }
  }

  if(check) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0; i<n; i++){
    printf("%c %d\n",A[i].mark,A[i].num);
  }

  return 0;
}



void QuickSort(card A[],int p,int r){
  if(p < r){
    int q = Partition(A,p,r);
    QuickSort(A,p,q-1);
    QuickSort(A,q+1,r);
  }
}

void merge(card B[],int left,int mid,int right){
   int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  card *l,*r;
  l = (card *)malloc((n1+2)*sizeof(card));
  r = (card *)malloc((n2+2)*sizeof(card));
  
  for(i=0; i<n1; i++) l[i] = B[left+i];
  for(i=0; i<n2; i++) r[i] = B[mid+i];
  l[n1].num = r[n2].num = INF;
  
  i=j=0;
  for(k=left; k<right; k++){
    if(l[i].num <= r[j].num){
      B[k] = l[i];
      i++;
    }else{
      B[k] = r[j];
      j++;
    }
  }
  
  free(l);
  free(r);
}

void MergeSort(card * B,int left,int right){
  int mid;
  
  if(left+1 < right ){
    mid = (left + right) / 2;
    MergeSort(B,left,mid);
    MergeSort(B,mid,right);
    merge(B,left,mid,right);
  }
  
}


int Partition(card A[],int p,int r){
  int x,i,j,tmp;
  x = A[r].num;
  i = p-1;
  for(j=p; j<=r-1; j++){
    if(A[j].num <= x){
      i++;
      swap(&A[i],&A[j]);
    }
  }

  swap(&A[i+1],&A[r]);

  return i+1;
}


void swap(card *a,card *b){
  card tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

