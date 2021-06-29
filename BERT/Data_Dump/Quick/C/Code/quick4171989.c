#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define N 10001

#define MAX 100000
#define SE 98765432

struct Node{
  char suit;
  int value;
};

struct Node L[MAX /2+2],R[MAX /2+2];

void merge(struct Node A[],int n,int left, int mid,int right);
void mergeSort(struct Node A[],int n,int left,int right);
int partition(struct Node A[],int n,int p,int r);
void quickSort(struct Node A[],int n,int p,int r);

int main(){
  int n,i,x,y=1;
  struct Node A[MAX], B[MAX];
  char c[10];
 

  scanf("%d",&n);

  for(i=0;i<n;i++){
    
    scanf("%s%d",c,&x);
    
    A[i].suit=B[i].suit=c[0];
    
    A[i].value=B[i].value=x;
    
  }

  mergeSort(A,n,0,n);
  
  quickSort(B,n,0,n-1);

  for(i=0;i<n;i++){
    
    if(A[i].suit!=B[i].suit)y=0;
    
  }

  if(y==1){
    
    printf("Stable");
    
  printf("\n");}
  
  else printf("Not stable\n");
  
  for(i=0;i<n;i++){
    
    printf("%c %d\n",B[i].suit,B[i].value);
    
  }
  return 0;
}

void merge(struct Node A[],int n,int left, int mid,int right){
  
  int i,j,k;
  
  int o = mid-left;
  
  int r = right-mid;
  
  for(i=0;i<o;i++)L[i]=A[left+i];
  
  for(i=0;i<r;i++)R[i]=A[mid+i];
  
  L[o].value =R[r].value=SE;
  
  i=j=0;
  
  for(k=left;k<right;k++){
    
    if(L[i].value<=R[j].value){
      
      A[k]=L[i++];

    }
    
    else{
      A[k]=R[j++];
      
    }
  }
}
void mergeSort(struct Node A[],int n,int left,int right){
  int mid;
  
  if(left+1<right){
    
    mid=(left+right)/2;
    
    mergeSort(A,n,left,mid);
    
    mergeSort(A,n,mid,right);
    
    merge(A,n,left,mid,right);
  }
}

int partition(struct Node A[],int n,int p,int r){
  int i,j;
  
  struct Node t,x;
  
  x=A[r];
  
  
  i=p-1;
  
  for(j=p;j<r;j++){
    
    if(A[j].value<=x.value){
      
      i++;
      
      t=A[i];A[i]=A[j];A[j]=t;
    }
  }
  t= A[i+1];A[i+1]=A[r];A[r]=t;
  
  return i+1;
}

void quickSort(struct Node A[],int n,int p,int r){
  int q;
  
  if(p<r){
    
    q=partition(A,n,p,r);
    
    quickSort(A,n,p,q-1);
    
    quickSort(A,n,q+1,r);
  }
}
