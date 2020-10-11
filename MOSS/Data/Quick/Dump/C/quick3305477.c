#include <stdio.h>
#include <string.h>
#define N 100001
#define INFTY 1000000000
#define true 1
#define false 0



typedef struct{
  char c;
  int num;
}C;

int n; //外部変数
C l[N],r[N];

int partition(C a[],int p,int r){
  int x,i,j;
  C temp;
  x=a[r].num;
  i=p-1;

  for(j=p;j<r;j++){
    if(a[j].num<=x){
      i++;
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  temp=a[i+1];
  a[i+1]=a[r];
  a[r]=temp;  
  return i+1;
}

void quicksort(C a[],int p,int r){
  int q;
  if(p>r)return;
  q=partition(a,p,r);
  quicksort(a,p,q-1);
  quicksort(a,q+1,r);
}

void merge(C A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)l[i]=A[left+i];
  for(i=0;i<n2;i++)r[i]=A[mid+i];
  
  l[n1].num=INFTY;
  r[n2].num=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(l[i].num<=r[j].num){
      A[k]=l[i];
      i++;
    }
    else {
      A[k]=r[j];
      j++;
    }
  }
}

void mergesort(C A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int isStable(C a[],C b[]){
  int i,flag=1;
  for(i=0;i<n;i++){
  if(memcmp(&a[i],&b[i],sizeof(a[i]))!=0)flag=0;
  }
  if(flag)return true;
  else return false;
}

int main(){
  int i,x;
  C A[N],B[N];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c %d",&A[i].c,&A[i].num);
    B[i]=A[i];
  }
  mergesort(B,0,n);
  quicksort(A,0,n-1);
  if(isStable(A,B))printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].c,A[i].num);


  }



  return 0;
}


