#include <stdio.h>

struct Card{
  char suit;
  int value;
};
struct Card S[100000/2+2],T[100000/2+2];
void quicksort(struct Card *,int,int);
int partition(struct Card *,int,int);
void merge(struct Card *,int,int,int);
void mergesort(struct Card *,int,int);
int n;

int partition(struct Card *R,int s,int t){
  int i,j;
  struct Card x,k,m;
  x=R[t];
  i=s-1;
  for(j=s;j<t;j++){
    if(R[j].value<=x.value){
      i++;
      k= R[i];
      R[i]=R[j];
      R[j]=k;
    }
  }
  m=R[i+1];
  R[i+1]=R[t];
  R[t]=m;
  return i+1;
}
void quicksort(struct Card *R,int s,int t){
  int r;
  if(s<t){
    r=partition(R,s,t);
    quicksort(R,s,r-1);
    quicksort(R,r+1,t);
  }
}
void merge(struct Card *R,int left,int mid,int right){
  int i,j,m,l,s;
  l=mid-left;
  s=right-mid;
  for(i=0;i<l;i++){
    S[i]=R[left+i];
  }
  for(i=0;i<s;i++){
    T[i]=R[mid+i];
  }
    S[l].value=T[s].value=1000000000;
    i=j=0;
    for(m=left;m<right;m++){
      if(S[i].value<=T[j].value){
	R[m]=S[i++];
      }
      else {
	R[m]=T[j++];
	  }
    }
}

void mergesort(struct Card *R,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(R,left,mid);
    mergesort(R,mid,right);
    merge(R,left,mid,right);
  }
}
int main(){
  int i,e,le=1;
  struct Card R[100000],K[100000];
  char D[20];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",D,&e);
    R[i].suit=K[i].suit=D[0];
    R[i].value=K[i].value=e;
  }
  mergesort(R,0,n);
  quicksort(K,0,n-1);
  for(i=0;i<n;i++){
    //マージとクイックの結果を比較
    if(R[i].suit!=K[i].suit)
      le=0;//le==stable;
       }
    if(le==1)
      printf("Stable\n");
    else 
      printf("Not stable\n");
    for(i=0;i<n;i++){
      printf("%c %d\n",K[i].suit,K[i].value);
    }
    return 0;
  }


