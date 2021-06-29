#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
typedef long long ll;
using namespace std;

struct Card{
  char c;
  int n;
};

void marge(Card a[],int left,int mid,int right){
  int n1=mid-left,n2=right-mid;
  Card* l=(Card*)malloc(sizeof(Card)*(n1+1));
  Card* r=(Card*)malloc(sizeof(Card)*(n2+1));
  int i,j,k;
  for(i=0;i<n1;i++){
    l[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
  }
  l[n1].n=r[n2].n=1000000001;
  i=j=0;
  for(k=left;k<right;k++){
    if(l[i].n<=r[j].n){
      a[k]=l[i];
      i++;
    }
    else{
      a[k]=r[j];
      j++;
    }
  }
  return;
}

void margeSort(Card a[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    margeSort(a,left,mid);
    margeSort(a,mid,right);
    marge(a,left,mid,right);
  }
}

int partition(Card a[],int p,int r){
  int x=a[r].n,i,j=p;
  Card tmp;
  for(i=p;i<r;i++){
    if(a[i].n<=x){
      tmp=a[i];
      a[i]=a[j];
      a[j]=tmp;
      j++;
    }
  }
  tmp=a[r];
  a[r]=a[j];
  a[j]=tmp;
  return j;
}

void quickSort(Card a[],int p,int r){
  if(p<r){
    int q=partition(a,p,r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
  }
  return;
}

int main(void){
  int i,n;
  bool isStable=1;
  Card a[100000],b[100000];
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a[i].c;
    cin>>a[i].n;
  }

  memcpy(b,a,sizeof(a));

  margeSort(a,0,n);
  quickSort(b,0,n-1);

  for(i=0;i<n;i++){
    if(a[i].c!=b[i].c){
      isStable=0;
      break;
    }
  }

  if(isStable){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }

  for(i=0;i<n;i++){
    printf("%c %d\n",b[i].c,b[i].n);
  }

	return 0;
}
