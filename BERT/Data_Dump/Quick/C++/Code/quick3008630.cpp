#include "bits/stdc++.h"
using namespace std;

int q=0;

struct tranp{
  char gara;
  int atai;
};

int partition(struct tranp CC[],int N,int p,int r){
  int i=0,j=0;
  struct tranp x;
  struct tranp tmp;
  x=CC[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(CC[j].atai<=x.atai){
      i=i+1;
      tmp=CC[i];
      CC[i]=CC[j];
      CC[j]=tmp;
    }
  }
  tmp=CC[i+1];
  CC[i+1]=CC[r];
  CC[r]=tmp;
  return i+1;
}

void quicksort(struct tranp CC[], int N, int p, int r){
  int q;
  if(p<r){
    q=partition(CC,N,p,r);
    quicksort(CC,N,p,q-1);
    quicksort(CC,N,q+1,r);
  }
}
void marge(struct tranp C[],int N, int left, int mid, int right){
  int i,j,k;
  int n1=0,n2=0;
  struct tranp L[500010];
  struct tranp R[500010];
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=C[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=C[mid+i];
  }
  L[n1].atai=2000000000;
  R[n2].atai=2000000000;
  j=0;
  i=0;
  for(k=left;k<right;k++){
    if(L[i].atai<=R[j].atai){
      C[k]=L[i++];
      
    }
    else {
      C[k]=R[j++];
    }
  }
}

void margesort(struct tranp C[],int N, int left, int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    margesort(C,N,left,mid);
    margesort(C,N,mid,right);
    marge(C,N,left,mid,right);
  }
}

int main(){
  struct tranp C[100000];
  struct tranp CC[100000];
  int n=0,i=0;
  int N=0;
  int left=0,right=0;
  char gara1[10];
  int atai1;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%s %d",gara1,&atai1);
    C[i].gara=CC[i].gara=gara1[0];
    C[i].atai=CC[i].atai=atai1;
  }
  margesort(C,N,0,N);
  quicksort(CC,N,0,N-1);
  for(i=0;i<N;i++){
    if(C[i].gara!=CC[i].gara){
      printf("Not stable\n");
      break;
    }
  }
  if(i==N)printf("Stable\n");
  for(i=0;i<N;i++){
    cout<<CC[i].gara<<" "<<CC[i].atai<<endl;
    
  }
  return 0;
}

