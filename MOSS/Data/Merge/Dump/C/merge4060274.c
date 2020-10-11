#include <stdio.h>
#include <math.h>

#define N 500000

void merge();
void mergeSort();
int count=0;

int main(){
  int n, s[N], a;

  scanf("%d",&n);
  for(a = 0; a < n; a++){
    scanf("%d",&s[a]);
  }

  mergeSort(s,0,a);
  for(a = 0; a < n-1; a++) printf("%d ",s[a]);
  printf("%d\n",s[a]);
  printf("%d\n",count);

  return 0;
}

void merge(int *s, int left, int mid, int right){
  int n1 = mid - left;
  int  n2 = right - mid;
  int l[n1], r[n2], a, b, c;
  
  for(a = 0; a < n1; a++) l[a] = s[left+a];
  for(a = 0; a < n2; a++) r[a] = s[mid+a];
  l[n1] = 2147483647;
  r[n2] = 2147483647;

  a = b = 0;
  for(c = left; c < right; c++){
    count++;
    if(l[a] <= r[b]){
      s[c] = l[a];
      a++;
    }
    else{
      s[c] = r[b];
      b++;
    }
  }
}

void mergeSort(int *s, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s,left,mid,right);
  }
}

