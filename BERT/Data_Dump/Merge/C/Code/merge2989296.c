#include<stdio.h>
#define DEF 2000000000
int count=0;
int L[500000];
int R[500000];


void sort(int A[],int n,int left,int right);
void merge(int A[],int n,int left,int mid,int right);



int main(){
  int number;
  scanf("%d",&number);
  int A[1000000];
  int i;
  for(i=0;i<number;i++){
    scanf("%d",&A[i]);
  }

  
  sort(A,number,0,number);

  for(i=0;i<number;i++){
    if(i==number-1){printf("%d",A[i]);}
    else {printf("%d ",A[i]);}
    
  }
  printf("\n");
  printf("%d\n",count);
  
  
  
  return 0;
}




void merge(int A[],int n,int left,int mid,int right){
  int a1=mid-left;
  int a2=right-mid;



  
  int i;
  for(i=0;i<a1;i++){L[i]=A[left+i];}
  for(i=0;i<a2;i++){R[i]=A[mid+i];}



  
  L[a1]=R[a2]=DEF;


  
  i=0;        
  int j=0;
  int k;
  
  
  for(k=left;k<right;k++){
    count++;
    
    if(L[i]>R[j]){
      A[k]=R[j];
      j++;
    }
    
    else{


      A[k]=L[i];
      i++;
    }
    
  }
  
}


void sort(int A[],int n,int l,int r){
  
  if(l+1<r){
    int mid;
    mid=(l+r)/2;
    
    sort(A,n,l,mid);
    sort(A,n,mid,r);
    
    
    merge(A,n,l,mid,r);
  }
  
}

