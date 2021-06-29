#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 500000
#define SMAX 1000000000

void merge(int*,int,int,int);
void mergeSort(int*,int,int);
void print_array(int*,int,int);

int cnt=0;

int main(){
  int i;

  int n;
  scanf("%d",&n);
  if(n>N)exit(1);
  int s[n];
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
    if(s[i]<0||s[i]>SMAX)exit(2);}

  mergeSort(s,0,n);

  print_array(s,n,cnt);

  return 0;
}


void mergeSort(int a[],int left,int right){
  int mid;
  if(left+1<right){
    mid =(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}

void merge(int a[],int left,int mid,int right){
  int  n1,n2;
  n1 = mid - left;
  n2 = right - mid;

  int i,j,k;
  int l[n1+1],r[n2+1];

  for(i=0;i<n1;i++){
    l[i]=a[left+i];}

  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
  }

  l[n1]=INFINITY;
  r[n2]=INFINITY;

  i=j=0;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      a[k]=l[i];
      i++;
      cnt++;
    }else{
      a[k]=r[j];
      j++;
      cnt++;
    }
  }
}

void print_array(int a[],int n,int cnt){
  int i;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",cnt);
}

