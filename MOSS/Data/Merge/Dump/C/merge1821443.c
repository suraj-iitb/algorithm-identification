#include<stdio.h>
#define INF 1000000005

int cnt;

int merge(int A[],int l,int m,int r){
  int R[250010],L[250010];
  int i,j,k;
  int n1,n2;
  n1 = m - l;
  n2 = r - m;

  for(i=0;i<n1;i++){
    L[i] = A[l+i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[m+i];
  }
  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;

  for(k=l;k<r;k++){
    cnt++;
    if(L[i] <= R[j]){
       A[k] = L[i];
       i += 1;
    }else{
      A[k] = R[j];
      j += 1;
    }
  }
}

void  mergesort(int A[],int l,int r){
  int m;
  if(l + 1 < r){
    m = (l+r)/2;
    mergesort(A,l,m);
    mergesort(A,m,r);
    merge(A,l,m,r);
  }
}


int main(){
  int n;
  int S[500005];
  int i;
  cnt = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
    mergesort(S,0,i);

    for(i=0;i<n;i++){
      printf("%d",S[i]);
      if(i<n-1){
        printf(" ");
      }
    }
    puts("");
    printf("%d\n",cnt);
    return 0;
}
