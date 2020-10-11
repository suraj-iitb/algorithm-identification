#include<stdio.h>

typedef struct {
  int num;
  char ch;
} Data;


void swap(Data* a,Data* b){
  Data tmp=*a;
  *a=*b;
  *b=tmp;
}

int Partition(Data A[],int p,int r){
  Data x = A[r];
  int i=p-1,j;
  for(j=p;j<r;j++){
    if(A[j].num<=x.num){
      i++;
      swap(&A[i],&A[j]);
    }
  }
  swap(&A[i+1],&A[r]);
  return i+1;
}

void Quicksort(Data A[],int p,int r){
  if(p<r){
    int q = Partition(A,p,r);
    Quicksort(A,p,q-1);
    Quicksort(A,q+1,r);
  }
}

void Merge(Data A[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  Data L[n1+1],R[n2+1];
   
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1].num=1000000001;
  R[n2].num=1000000001;
   
  i=j=0;
  for(k=left;k<right;k++){
    if(L[i].num<=R[j].num){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }
  
}
 
void Merge_Sort(Data A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
 
    Merge_Sort(A,left,mid);
    Merge_Sort(A,mid,right);
    Merge(A,left,mid,right);
     
  }
  
}


int main(){
  int n,i,flg;
  char x;
  Data A[100000];
  Data B[100000];
  scanf("%d",&n);
  scanf("%c",&x);
  for(i=0;i<n;i++){
    scanf("%c %d",&A[i].ch,&A[i].num);
    scanf("%c",&x);
    //printf("%c %d\n",A[i].ch,A[i].num);
    B[i]=A[i];
  }
  
  Quicksort(A,0,n-1);
  Merge_Sort(B,0,n);

  flg=1;
  for(i=0;i<n;i++)if(A[i].num!=B[i].num || A[i].ch!=B[i].ch)flg=0;

  if(flg)printf("Stable\n");
  else printf("Not stable\n");
  
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].ch,A[i].num);
  }
  
  return 0;
}
