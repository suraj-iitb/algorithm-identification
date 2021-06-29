#include<stdio.h>

#define N 100000
#define S 2000000000

typedef struct Card {
  int value;
  char suit;
} card;

card L[N/2 + 2];
card R[N/2 + 2];

int partition(card A[],int n,int p,int r);
void merge(card A[],int n,int l,int mid,int r);
void mergeSort(card A[],int n,int l,int r);
void quickSort(card A[],int n,int p,int r);



int main(void){
  int i,n;
  int x;
  card A[N],B[N];
  char s[100];
  int st = 1;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%s %d",s,&x);
    
    B[i].suit = s[0];
    A[i].suit = B[i].suit;
    
    B[i].value = x;
    A[i].value = B[i].value;
  }

  mergeSort(A,n,0,n);
  quickSort(B,n,0,n-1);

  for(i = 0;i < n;i++){
    if(A[i].suit != B[i].suit){
      st = 0;
    }
  }

  if(st == 1){
    puts("Stable");
  } else {
    puts("Not stable");
  }

  for(i = 0;i < n;i++){
    printf("%c %d\n",B[i].suit,B[i].value);
  }

  return 0;
}
    
    






void merge(card A[],int n,int l,int mid,int r){
  int i,j,k;
  int n1,n2;

  n1 = mid - l;
  n2 = r - mid;
  
  for(i = 0;i < n1;i++){
    L[i] = A[l+i];
  }
  
  for(i = 0;i < n2;i++){
    R[i] = A[mid+i];
  }

  R[n2].value = S;
  L[n1].value = R[n2].value;
  
  i = 0;
  j = 0;

  for(k = l;k < r;k++){
    if(L[i].value <= R[j].value){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
  
}


void mergeSort(card A[],int n,int l,int r){
  int mid;

  if(l+1 < r){
    mid = (l+r)/2;
    mergeSort(A,n,l,mid);
    mergeSort(A,n,mid,r);
    merge(A,n,l,mid,r);
  }
}

int partition(card A[],int n,int p,int r){
  int i,j;
  card x;
  card temp;

  x = A[r];
  i = p-1;

  for(j = p;j < r;j++){
    if(x.value >= A[j].value){
      i++;
      
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }

  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return (i+1);
}

void quickSort(card A[],int n,int p,int r){
  int q;
  
  if(p < r){
    q = partition(A,n,p,r);
    
    quickSort(A,n,p,q-1);
    quickSort(A,n,q+1,r);
  }
}



