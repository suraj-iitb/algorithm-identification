#include <stdio.h>
#define M 500000

int con = 0;
int l[M/2+2],r[M/2+2];

void merge(int*,int,int,int,int);
void mergesort(int*,int,int,int);

int main(){
  int n,i;
  int a[M];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
}
  mergesort(a, n, 0, n);

  for(i = 0;i < n;i++){
    if(i != 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",con);
}

void merge(int *a,int n,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++){
    l[i] = a[left + i];
  }
  for(i = 0;i < n2;i++){
    r[i] = a[mid + i];
  }
  l[n1] = 1000000000;
  r[n2] = 1000000000;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    con++;
    if(l[i] <= r[j]){
      a[k] = l[i];
      i += 1;
    }
    else{
      a[k] = r[j];
      j += 1;
    }
  }
}


void mergesort(int *a,int n,int left,int right){
  int mid,i,c=0;
  if(left + 1 < right){
    mid = (left + right)/ 2;
    mergesort(a, n, left, mid);
    mergesort(a, n, mid, right);
    merge(a, n, left, mid, right);
    c++;
  }
}

