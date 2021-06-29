#include<stdio.h>
#include<string.h>

#define N 1000000

#define INFINITY 2000000001

struct quick{
  char alpha;
  int value;
};
  

struct quick Q[N];
struct quick Merge[N];

struct quick R[N],L[N];

int partition (struct quick *, int ,int);

void quicksort (struct quick *, int ,int);

int merge(struct quick *, int ,int ,int);
void mergeSort (struct quick *,int ,int);

  
int main(){
  int num,i,j;
  int p,r;
  int right,left,mid;
  //printf("1\n");
  scanf("%d",&num);
  for(i=0;i<num;i++) {
    scanf(" %c%d",&Q[i].alpha,&Q[i].value);
    Merge[i] = Q[i];
  }
  //printf("2\n");
  p = 0;
  r = num-1;

  right = num;
  left = 0;
  //mid = (right + left) / 2;


  //printf("3\n");
  mergeSort(Merge,left,right);

  //printf("4\n");

  quicksort(Q,p,r);

  
  for(i=0;i<num;i++){
    if(Merge[i].alpha != Q[i].alpha) break;
  }
  if(i==num) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<num;i++){
    printf("%c %d",Q[i].alpha,Q[i].value);
    //printf("%c %d",Merge[i].alpha,Merge[i].value);
    
    printf("\n");
  }
  

  return 0;
}

int partition (struct quick *par,int p,int r){
  int x,i,j;
  struct quick temp;
  int n;

  x = par[r].value;
  i = p - 1;

  for(j = p;j<=r-1;j++){
    if(par[j].value <= x ){
      i = i+1;
      // A[i] と A[j] を交換
      temp = par[i];
      par[i] = par[j];
      par[j] = temp;
    }
  }
  //A[i+1] と A[r] を交換
  temp = par[i+1];
  par[i+1] = par[r];
  par[r] = temp;

  return i+1;
}


void quicksort (struct quick *A,int p,int r){
  if(p < r){
    int q;
    q = partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}



int merge(struct quick *A,int left,int mid,int right){
  int i,j,k,n1,n2;
  //struct quick R[N],L[N];

  //printf("wa-i\n");
  
  n1 = mid - left;
  n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for (i = 0;i<= n1-1;i++)
    L[i] = A[left + i];
  for (i = 0;i<= n2-1;i++)
    R[i] = A[mid + i];
  // printf("aaaa\n");
  L[n1].value = INFINITY;
  R[n2].value = INFINITY;
  i = 0;
  j = 0;
  for (k = left;k<=right-1;k++){
    if (L[i].value <= R[j].value){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
    
  }
  return 0;
}

void mergeSort(struct quick *A,int left,int right){
  int mid;
  int i;
  //printf("%d  %d\n",left,right);
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    //printf("wa-iwa-i%d  %d\n",left,right);
    mergeSort(A, mid, right);
    //printf("wa-iwa-iwa-i\n");
    merge(A, left, mid, right);
  }
}



