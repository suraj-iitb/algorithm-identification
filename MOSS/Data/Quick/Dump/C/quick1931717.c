#include <stdio.h>
#include <stdlib.h>
int A[100000],A1[1000000],n,flag,cnt;
char C[100000],C1[1000000];
int Partition(int p,int r){
  int i,j,tmpn,x;
  char tmpc;
  x=A[r];
  i=p-1;

  for(j=p;j<=r-1;j++){
    if(A[j]<=x){
      
     
      i=i+1;
      tmpn=A[j];
      A[j]=A[i];
      A[i]=tmpn;

      tmpc=C[j];
      C[j]=C[i];
      C[i]=tmpc;
	
    }
   
  }
  tmpn=A[i+1];
  tmpc=C[i+1];

  A[i+1]=A[r];
  C[i+1]=C[r];

  A[r]=tmpn;
  C[r]=tmpc;
  return i+1;
}
void Quicksort(int p,int r){
  int q;
  if(p<r){
    q=Partition(p,r);
    Quicksort(p,q-1);
    Quicksort(q+1,r);
  }
}

void merge(int left,int mid,int right){
  int n1,n2,i,j,k;
  double *L,*R;
  char *L1,*R1;
  n1=mid-left;
  n2=right-mid;
 
  L=(double*)malloc((sizeof(double))*(n1+1));
  R=(double*)malloc((sizeof(double))*(n2+1));
  L1=(char*)malloc((sizeof(char))*(n1+1));
  R1=(char*)malloc((sizeof(char))*(n2+1));

  for(i=0;i<n1;i++){
    L[i]=A1[left+i];
    L1[i]=C1[left+i];
  }
 
  for(i=0;i<n2;i++){
    R[i]=A1[mid+i];
    R1[i]=C1[mid+i];
  }
  L[n1]=1.0/0.0;
  R[n2]=1.0/0.0;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A1[k]=L[i];
      C1[k]=L1[i];
      i++;
    }
    else {
      A1[k]=R[j];
      C1[k]=R1[j];
      j++;
    }
 
  }
   
  free(L);
  free(R);
 
}


void mergeSort(int left,int right){
  int mid;
   
  if(left+1<right){ mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
 
}



int main(){

  int i,p=0;

   scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c %d",&C[i],&A[i]);
    A1[i]=A[i];
    C1[i]=C[i];
  }

  mergeSort(0,n);
  Quicksort(0,n-1);
  for(i=0;i<n;i++){
    if(A1[i]==A[i] && C1[i]!=C[i]){
      flag=1;
      break;
    }
  }
  if(flag==0) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",C[i],A[i]);
  }


  return 0;
}
