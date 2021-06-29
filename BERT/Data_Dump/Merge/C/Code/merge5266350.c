#include<stdio.h>
#define N 500001
#define INF (1<<30)

int A[N];
int L[500000/2+2],R[500000/2+1];
int n;
int cnt=0;




void merge(int left,int right){

  int mid=(left+right)/2;
  int i,j,k=0;
  if(left+1>=right)return;

  merge(left,mid);
  merge(mid,right);


  for(i=left;i<mid;i++){
    L[k++]=A[i];
  }
  L[k]=INF;
  k=0;
  for(j=mid;j<right;j++){
    R[k++]=A[j];
  }
  R[k]=INF;
  i=j=0;


  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<R[j])A[k]=L[i++];
    else A[k]=R[j++];
  }


}




int main(){



  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  merge(0,n);

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",cnt);





  return 0;
}

