#include<stdio.h>

void merge(int[],int,int,int);
void mergesort(int[],int,int);

int count=0;

int main(void){
  int n,s[500000];
  int left = 0;
  int i;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&s[i]);
  }
 
  mergesort(s,left,n);
  
  for(i=0; i < n; i++){    
    printf("%d",s[i]);  
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

void merge(int a[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;

  int l[n1+1],r[n2+1];
  
  for(i = 0; i < n1; i++){
    l[i] = a[left + i];
  }


  for(i = 0; i < n2; i++){
    r[i] = a[mid + i];
  }
  l[n1] = 1000000000;
  r[n2] = 1000000000;

  i = 0;
  j = 0;
  
  for(k = left; k < right; k++){
    if(l[i] <= r[j]){
      a[k] = l[i];
      i += 1;
      count++;
    }
    else{
      a[k] = r[j];
      j += 1;
      count++;
    }
  }
}

void mergesort(int a[],int left,int right){
  int mid,i;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}
