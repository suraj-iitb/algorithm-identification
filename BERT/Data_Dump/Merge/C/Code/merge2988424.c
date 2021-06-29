#include<stdio.h>
#include<math.h>
#define INF 1000000000
void merge(int A[],int left,int mid, int right);
void mergesort(int A[],int left,int right);
void list(int A[]);
//int a[500001];

int cnt=0;
int n;
int main()
{
  int i,j;
  scanf("%d",&n);
 
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }


  
  mergesort(a,0,n);
  list(a);
  printf("%d\n",cnt);
  return 0;
}
void merge(int A[n],int left,int mid, int right){
  int n1,n2;
  n1=mid-left;
  n2=right-mid;
  int L[n1],R[n2],i,j,k;
  //printf("a\n");
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  //printf("b\n");
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=INF;
  R[n2]=INF;
  i=0;
  j=0;
  //printf("c\n");
  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
       cnt++;
    }else{
      A[k]=R[j];
      j++;
       cnt++;
    }
  }
}
void mergesort(int A[n],int left,int right){
  //printf("test %d %d\n" ,left,right);
  int mid,i;
  // list(A);
  if(left+1<right){
    //printf("%d %d\n",left,right);
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    // printf("A\n");
    merge(A,left,mid,right);
  }//else
    //printf("!!\n");
}
void list(int A[n]){
  int i;
  //printf("segu\n");
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
}

