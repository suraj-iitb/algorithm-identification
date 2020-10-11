#include<stdio.h>
#define N 100000
#define INFTY 2000000000

typedef struct{
  char name;
  int num;

}card;

void mergeSort(card*,int,int);
void merge(card*,int,int,int);
void quickSort(card*,int,int);
int partition(card*,int,int);


card L[N/2],R[N/2];
card Q[N],M[N];

int count;

int main(){
  int n,i,num;
  char Name[10];
  int stable=1;
    
  scanf("%d",&n);
    
  for(i=0;i<n;i++){
    scanf("%s %d",Name,&num);
    Q[i].name=M[i].name=Name[0];
    Q[i].num=M[i].num=num;
  }
    
  mergeSort(M,0,n);
  quickSort(Q,0,n-1);
    
  for(i=0;i<n;i++){
    if(M[i].name!=Q[i].name) stable=0;
  }

  if(stable==1) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",Q[i].name,Q[i].num);
  }
    
  return 0;
    
}

void mergeSort(card *A,int left,int right){

  int mid;

  if(left+1 < right){

    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
    
  }
  
}

void merge(card *A,int left,int mid,int right){

  int n1,n2,i,j,k,lcount=0,rcount=0;
  
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<=n1-1;i++){
    L[i] = A[left+i];
    lcount++;
  }
 
  for(i=0;i<=n2-1;i++){
    R[i] = A[mid+i];
    rcount++;
  }
 

  L[n1].num=INFTY;
  R[n2].num=INFTY;

  i=0;
  j=0;
  
  for(k=left;k<=right-1;k++){

    if(L[i].num<=R[j].num){

      A[k]=L[i];
      lcount--;
      if(lcount>0){
        i++;
      }else{
        L[i].num=INFTY;
      }
      
    }else{

      A[k]=R[j];
      rcount--;
      if(rcount>0){
        j++;
      }else{
        R[j].num=INFTY;

      }
      
    }//if
    
    count++;
    
  }//for

}

int partition(card *A,int p,int r){

  int i,j;
  card x,temp1,temp2;

  x=A[r];
  i=p-1;
  
  for(j=p;j<=r-1;j++){


    if(A[j].num<=x.num){
      i=i+1;
      temp1=A[i];
      A[i]=A[j];
      A[j]=temp1;
      
    }

  }

  temp2=A[i+1];
  A[i+1]=A[r];
  A[r]=temp2;

  return i+1;
    
}


void quickSort(card *A,int p,int r){
  int q;
  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

