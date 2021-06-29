#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2],R[MAX/2+2];
int count=0;

void MErge(int*,int,int,int,int);
void MErgeSort(int*,int,int,int);

int main(){
  int h,i,H[MAX];
  
  scanf("%d",&h);
  for( i = 0 ; i < h ; i++ ){
  scanf("%d",&H[i]);
  }

  MErgeSort(H,h,0,h);

  for( i = 0 ; i < h ; i++ ){
    if( i > 0 )printf(" ");
    printf("%d",H[i]);
  }

  printf("\n");
  printf("%d\n",count );

  return 0;
}
void MErge(int H[],int h,int l,int m,int r){
  int x1,x2,i,j,k;

  x1=m-l;
  x2=r-m;
  for(i=0;i<x1;i++){
    L[i]=H[l+i];
  }
  for(i=0;i<x2;i++){
    R[i]=H[m+i];
  }
  L[x1]=R[x2]=SENTINEL;

  i=0;
  j=0;
  for( k = l ; k < r ; k++ ){
    count++;
    if(L[i]<=R[j]){
      H[k]=L[i++];
    }
    else{
      H[k]= R[j++];
    }
  }
}

void MErgeSort(int H[],int h,int l,int r){
  int x;
  if(l+1<r){
    x=(l+r)/2;
      MErgeSort(H,h,l,x);
    MErgeSort(H,h,x,r);
    MErge(H,h,l,x,r);
  }
}
      
  

