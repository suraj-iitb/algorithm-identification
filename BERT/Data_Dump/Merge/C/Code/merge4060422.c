#include <stdio.h>
#define MAX 500000
#define S 1000000000


void merge(int *,int, int,int);
void mergeSort(int *,int,int);
int left[MAX/2+2],right[MAX/2+2];
int count,n;

int main(){
  int a[MAX],i;
  
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]>=S){
      return 1;
  }
  }
  mergeSort(a,0,n);

  for(i=0;i<n;i++){
    printf("%d",a[i]);
   if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}

void merge(int a[],int left2,int mid,int right2){
  int i,j,k,n1,n2;

  n1=mid-left2;
  n2=right2-mid;
  for(i=0;i<n1;i++){
    left[i]=a[left2+i];
  }
  for(i=0;i<n2;i++){
    right[i]=a[mid+i];
  }
  left[n1]=S;
  right[n2]=S;
  i=0;
  j=0;
  for(k=left2;k<right2;k++){
    count++;
    if(left[i]<=right[j]){
      a[k]=left[i];
      i=i+1;
	}
    else{
      a[k]=right[j];
      j=j+1;
    }
  }
}

void mergeSort(int a[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}

