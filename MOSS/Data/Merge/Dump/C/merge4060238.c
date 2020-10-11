#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//prototype
void merge(int,int,int);
void mergesort(int,int);

//global
int *data, cnt=0;

int main(){
  int data_n, i;

  //input
  scanf("%d",&data_n);
  data=(int *)malloc(sizeof(int)*data_n);
  for(i=0;i<data_n;i++) scanf("%d",&data[i]);


  //mergesort
  mergesort(0,data_n);


  //output
  for(i=0;i<data_n-1;i++) printf("%d ",data[i]);
  printf("%d\n%d\n",data[i],cnt);

  free(data);  
  return 0;
}


void merge(int left,int mid,int right){
  int n1, n2, *L, *R;
  int i, j, k;

  n1=mid-left;
  n2=right-mid;

  L=(int *)malloc(sizeof(int)*(n1+1));
  R=(int *)malloc(sizeof(int)*(n2+1));

  for(i=0;i<n1;i++) L[i]=data[left+i];
  for(i=0;i<n2;i++) R[i]=data[mid+i];

  L[n1]=R[n2]=INT_MAX;

  i=j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      data[k]=L[i];
      i++;
    }
    else{
      data[k]=R[j];
      j++;
    }
    cnt++;
  }

  free(L);
  free(R);
}


void mergesort(int left,int right){
  int mid;
  
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}

