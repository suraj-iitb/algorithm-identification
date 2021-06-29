#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000

void mergesort(int *,int,int);
void merge(int *,int,int,int);

int L[MAX/2+2],R[MAX/2+2];
int count;
int array[MAX];

int main()
{

  int n,i;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  mergesort(array,0,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}



void mergesort(int array[],int left,int right)
{
  int mdl;
  if(left+1<right){
    mdl=(left+right)/2;
    mergesort(array,left,mdl);
    mergesort(array,mdl,right);
    merge(array,left,mdl,right);
  }
}

void merge(int array[],int left,int mdl,int right)
{
  int i,j,k,n1,n2;
  n1=mdl-left;
  n2=right-mdl;
  for(i=0;i<n1;i++) L[i]=array[left+i];
  for(i=0;i<n2;i++) R[i]=array[mdl+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      array[k]=L[i];
      i=i+1;
    }
    else {
      array[k]=R[j];
      j=j+1;
    }
  }
}
