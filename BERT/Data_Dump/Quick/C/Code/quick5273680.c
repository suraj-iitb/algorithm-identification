#include<stdio.h>
#define N 100001
#define INF (1<<30)

typedef struct{
  int val;
  char mark;
}Node;

Node A[N],B[N],L[N/2+2],R[N/2+2];
int n;



int  partition(int left,int right){

  int i,j,x;
  Node t;
  x=A[right].val;
  i=left-1;

  for(j=left;j<right;j++){
    if(x>=A[j].val){
      i++;
      t=A[i];
      A[i]=A[j];
      A[j]=t;
    }
  }

  i++;
  t=A[i];
  A[i]=A[j];
  A[j]=t;

  return i;

}




void quick(int left,int right){


  int q;

  if(left>=right)return;


  q=partition(left,right);

  quick(left,q-1);
  quick(q+1,right);



}



void merge(int left,int right){

  int i,j,k=0;
  int mid;
  Node t;

  if(left+1>=right)return;

  mid=(left+right)/2;
  merge(left,mid);
  merge(mid,right);


  for(i=left;i<mid;i++){
    L[k++]=B[i];
  }
  L[k].val=INF;
  k=0;

  for(j=mid;j<right;j++){
    R[k++]=B[j];
  }
  R[k].val=INF;

  i=j=0;

  for(k=left;k<right;k++){
    if(L[i].val<=R[j].val)B[k]=L[i++];
    else B[k]=R[j++];
  }
}









int main(){


  int i,j;
  int num;
  char mark[10];
  int flag=0;


  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%d\n",mark,&num);
    A[i].val=B[i].val=num;
    A[i].mark=B[i].mark=mark[0];
  }


  quick(0,n-1);
  merge(0,n);


  for(i=0;i<n;i++){
    if(A[i].mark!=B[i].mark){
      flag=1;
      break;
    }
  }

  if(flag)printf("Not stable\n");
  else printf("Stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].mark,A[i].val);
  }



  return 0;
}

