#include<stdio.h>

#define MAX 100000
#define INFTY 2000000000

struct Card{
  char suit;
  int value;
};

struct Card L[MAX/2 + 2],R[MAX/2 + 2];

void merge(struct Card S[],int n,int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0;i<=n1-1;i++){
    L[i] = S[left + i];
    
  }
  for(i = 0;i<=n2 - 1;i++){
    R[i] = S[mid + i];
  }
  L[n1].value = INFTY;
  R[n2].value = INFTY;
  i = 0;
  j = 0;
  for(k = left;k<=right-1;k++){
    if(L[i].value <= R[j].value){
      S[k] = L[i];
      i = i+1;
    
    }
    else{
      S[k] = R[j];
      j = j+1;
     
    }
  }

}
void mergeSort(struct Card S[],int n, int left,int right){
  int mid;
  if((left+1) < right){
    mid = (left+right)/2;
    mergeSort(S,n,left,mid);
    mergeSort(S,n,mid,right);
    merge(S,n,left,mid,right);
   
  }
}



int partition(struct Card S[],int n,int p,int r){
  int i,j;
  struct Card temp,x;
  x = S[r];
  i = p-1;
  for(j = p;j<=r-1;j++){
    if(S[j].value<= x.value){
      i = i+1;
      temp = S[i];
      S[i] = S[j];
      S[j] = temp;
    }
  }

  temp = S[i+1];
  S[i+1]=S[r];
  S[r] = temp;
    
   
  
  return i+1;
}

void quickSort(struct Card S[],int n,int p,int r){
  int q;
  if(p < r){
    q = partition(S,n,p,r);
    quickSort(S,n,p,q-1);
    quickSort(S,n,q+1,r);
  }
}

int main(){
  int i,n,v;
  struct Card S[MAX],B[MAX];
  char A[10];

  int stable = 1;

  scanf("%d",&n);

  for(i = 0;i<n;i++){
    scanf("%s %d",A,&v);
    S[i].suit = B[i].suit = A[0];
    S[i].value = B[i].value = v;
  }

  mergeSort(S,n,0,n);
  quickSort(B,n,0,n-1);


  for(i = 0;i<n;i++){
    if(S[i].suit != B[i].suit) stable = 0;
    

  }
  if(stable == 1)printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0;i<n;i++){
    printf("%c %d\n",B[i].suit,B[i].value);
  }
  return 0;
}

