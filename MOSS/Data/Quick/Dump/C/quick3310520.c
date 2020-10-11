#include <stdio.h>
#define MAX 100000
#define BIG 1000000000

typedef struct{
  char name;
  int num;
} P;

//安定なソートのマージソートと比較する
void merge(P *,int,int,int);
void mergeSort(P *,int,int);
int parttion(P *,int ,int);
void quicksort(P *,int ,int);


int main(){
   int i,n,t;
   char C[10];
   P A[MAX],B[MAX];
   int s=1;

   scanf("%d",&n);
   for(i=0;i<n;i++){
       scanf("%s %d",C,&t);
       A[i].name=B[i].name=C[0];
       A[i].num=B[i].num=t;

   }

  mergeSort(B,0,n);
  quicksort(A,0,n-1);

  for(i=0;i<n;i++){
      if(A[i].name!=B[i].name) s=0;
  }

   if(s==1) printf("Stable\n");
   else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].name,A[i].num);
  }

  return 0;
}

int partition(P *A,int p,int r){

    int i,j;
    P x,temp1,temp2;

    x=A[r];
    i=p-1;
    for(j=p;j<=r-1;j++){
        if(A[j].num<=x.num){       
            i=i+1;
            temp1=A[i];
            A[i]=A[j];
            A[j]=temp1;
        }
    }
    temp2=A[i+1];
    A[i+1]=A[r];
    A[r]=temp2;

    return i+1;

}

void merge(P *B,int left,int mid,int right){
int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  P L[n1+1];
  P R[n2+1];
  
  for(i=0;i<=n1-1;i++){
    L[i]=B[left+i];
  }
  for(j=0;j<=n2-1;j++){
    R[j]=B[mid+j];
  }
  L[n1].num=BIG;
  R[n2].num=BIG;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
   if(L[i].num<=R[j].num){
      B[k]=L[i];
      i++;
    }
    else{
      B[k]=R[j];
      j++;
    }
  }
}

void mergeSort(P *B,int left,int right){

 int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(B,left,mid);
        mergeSort(B,mid,right);
        merge(B,left,mid,right);
    }
}
void quicksort(P *A,int p,int r){
    int q;
    if(p<r){
        q=partition(A,p,r);
        quicksort(A,p,q-1);
        quicksort(A,q+1,r);
    }

}

