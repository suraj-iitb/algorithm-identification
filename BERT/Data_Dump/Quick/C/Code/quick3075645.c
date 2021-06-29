#include<stdio.h>
 
#define MAX 100000
 struct Node{
   char c;
   int n;
 };

struct Node CardA[MAX],CardB[MAX];

void merge(struct Node A[],int n,int left,int mid ,int right){
  int i,j,k;
  int a1,a2;

  a1=mid-left;
  a2=right-mid;

  for(i=0;i<a1;i++){
    CardA[i]=A[left+i];
  }

  
  for(i=0;i<a2;i++){
    CardB[i]=A[mid+i];
  }


  CardA[a1].n=CardB[a2].n=10000;

  i=j=0;

  for(k=left;k<right;k++){
    if(CardA[i].n <= CardB[j].n){
      A[k]=CardA[i++];
    }
    else{A[k]=CardB[j++];}
  }

}


void mergesort(struct Node A[],int n,int left,int right){
  int mid;

  if(left+1 < right){
    mid=(left+right)/2;

    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);

    merge(A,n,left,mid,right);
  }

}

int Partition(struct Node A[],int n,int p,int r){

  int i,j;
  struct Node a,b;
  b=A[r];
  i=p-1;

  for(j=p;j<r;j++){
    if(A[j].n <= b.n){
      i++;
      a=A[i];
      A[i]=A[j];
      A[j]=a;
    }
  }

  a=A[i+1];
  A[i+1]=A[r];
  A[r]=a;


  return i+1;
}


void quick(struct Node A[],int n,int p,int r){
  int n1;
  if(p<r){
    n1=Partition(A,n,p,r);
    quick(A,n,p,n1-1);
    quick(A,n,n1+1,r);
  }
}






int main(){

  int number;
  scanf("%d",&number);

  struct Node A[100000],B[100000];
  
  int i;
  for(i=0;i<number;i++){
    scanf(" %c%d",&A[i].c,&A[i].n);

    B[i].c=A[i].c;
    B[i].n=A[i].n;
    
    //printf("%c %d\n",B[i].c,B[i].n);
  }


  mergesort(A,number,0,number);//正確
  quick(B,number,0,number-1);//クイックそーと


  int stable=1;

  for(i=0;i<number;i++){
    if(A[i].c != B[i].c){stable=0;}//比較
  }


  if(stable ==1){printf("Stable\n");}

  else {printf("Not stable\n");}

  for(i=0;i<number;i++){
    printf("%c %d\n",B[i].c,B[i].n);
    
  }
  
  
  return 0;
}

