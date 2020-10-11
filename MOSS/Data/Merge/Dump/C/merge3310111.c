#include<stdio.h>
#include<stdlib.h>
#define O 1000000000
void N(int B[500001],int left,int right);
void M(int C[500001],int left,int mid,int right);
int count;

int main(){
       int A[500001];
       int a,i;
       
       scanf("%d",&a);
       for(i=0;i<a;i++){
             scanf("%d",&A[i]); 
       }
       N(A,0,a);
       for(i=0;i<a;i++){
    printf("%d",A[i]);
    if(i<a-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

void N(int B[],int left,int right){
       int i,mid;
       if(left+1<right){
              mid=(left+right)/2;
              N(B,left,mid);
              N(B,mid,right);
              M(B,left,mid,right);
       }
}

void M(int C[],int left,int mid,int right){
  int a,b,i,j,k;
  int *L,*R;
  a=mid-left;
  b=right-mid;
  L=(int *)malloc(sizeof(int)*(a+1));
  R=(int *)malloc(sizeof(int)*(b+1));
    for(i=0;i<=a-1;i++){
    L[i]=C[left+i];
  }
  for(j=0;j<=b-1;j++){
    R[j]=C[mid+j];
  }
  L[a]=O;
  R[b]=O;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
   if(L[i]<=R[j]){
      C[k]=L[i];
      i++;
      count++;
    }
    else{
      C[k]=R[j];
      j++;
      count++;
    }
  }
  free(L);
  free(R);
}
