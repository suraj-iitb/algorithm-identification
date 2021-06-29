#include <stdio.h>
#include <string.h>
#define INFTY 2000000000

int A[100001];
char B[100001][1];
int partition(int p,int r){
  int x=A[r],i=p-1,j,a;
  char b;
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i=i+1;
      a=A[i];A[i]=A[j];A[j]=a;
      b=B[i][0];B[i][0]=B[j][0];B[j][0]=b;
    }
  }
  a=A[i+1];A[i+1]=A[r];A[r]=a;
  b=B[i+1][0];B[i+1][0]=B[r][0];B[r][0]=b;
  return i+1;
}
void quickSort(int p,int r){
  int q;
  if(p<r){
    q=partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}
void bubbleSort(int C[100001],char D[100001][1],int n){
  int i,j,c;
  char d;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(C[j]<C[j-1]){
	c=C[j];C[j]=C[j-1];C[j-1]=c;
	d=D[j][0];D[j][0]=D[j-1][0];D[j-1][0]=d;
      }
    }
  }
}void merge(int C[100001],char D[100001][1],int left,int mid,int right){
  int n1,n2,i,j,k,L1[100001],R1[100001];
  char L2[100001][1],R2[100001][1];
  n1=mid-left;
  n2=right-mid;

  for(i=0;i<n1;i++){
    L1[i]=C[left+i];
    L2[i][0]=D[left+i][0];
  }
  for(i=0;i<n2;i++){
    R1[i]=C[mid+i];
    R2[i][0]=D[mid+i][0];
  }
  L1[n1]=INFTY;
  R1[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L1[i]<=R1[j]){
      C[k]=L1[i];
      D[k][0]=L2[i][0];
      i=i+1;
    }
    else{
      C[k]=R1[j];
      D[k][0]=R2[j][0];
      j=j+1;
    }
  }
}
void mergeSort(int C[100001],char D[100001][1],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(C,D,left,mid);
    mergeSort(C,D,mid,right);
    merge(C,D,left,mid,right);
  }
}

int main(){
  int n,i,C[100001];
  char D[100001][1],s[20];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",B[i],&A[i]);
    strcpy(D[i],B[i]);
    C[i]=A[i];
  }
  quickSort(0,n-1);
  mergeSort(C,D,0,n);
  strcpy(s,"Stable");
  for(i=0;i<n;i++){
    if(A[i]!=C[i] || B[i][0]!=D[i][0]){
      strcpy(s,"Not stable");
      break;
    }
  }
  printf("%s\n",s);
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i][0],A[i]);
  }
  return 0;
}

