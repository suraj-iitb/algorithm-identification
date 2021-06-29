#include<stdio.h>

#define INFTY 1000000001 

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0,n;


int main(){

  int i;

  int S[500000];

  // printf("%d\n",INFTY);
  
  scanf("%d",&n);

  //printf("wa-i2\n");
  
  for(i=0;i<n;i++){

    scanf("%d",&S[i]);

    // printf("%d ",S[i]);
    
  }

  // printf("\n");
  
  //printf("wa-i\n");
  
  mergeSort(S,0,n);

  //printf("wa-i1\n");

  for(i=0;i<n;i++){
    
    if(i==n-1)printf("%d\n",S[i]);
    else printf("%d ",S[i]);

  }

  printf("%d\n",count);

  return 0;
  
}

void merge(int *A,int left,int mid,int right){

  int n1,n2,i,j,L[500000],R[500000],k;

  
  n1= mid-left;
  n2= right-mid;


  for(i=0;i<n1;i++){

    L[i]=A[left+i];

  }

  for(i=0;i<n2;i++){

    R[i]=A[mid+i];

  }

  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;

  for(k=left;k<right;k++){

    count++;

    if(L[i]<=R[j]){

      A[k]=L[i];
      i=i+1;
    }

    else{
      A[k]=R[j];
      j=j+1;
    }

  }
  
}

void mergeSort(int *A,int left,int right){

  int mid;

  
  /* for(i=0;i<n;i++){

    printf("%d ",A[i]);

  }

  printf("\n");
  printf("left: %d,right: %d\n",left,right);
  */
 
  if(left+1<right){

    mid=(left+right)/2;

    //printf("mid: %d\n",mid);
    
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);

  }

}
    
