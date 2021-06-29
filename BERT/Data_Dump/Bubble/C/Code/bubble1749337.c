#include<stdio.h>

int bubbleSort(int *,int);

int main() {
  
  int n,a[100],i,b[100],cnt=0;
  
  // input data
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  // sort
  cnt = bubbleSort(a,n);
  
  // output sorted data
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",cnt);
  
  return 0;
}

// Sort by bubble sort and asc.
int bubbleSort(int *a, int n) {
  
  int tmp,j,cnt=0,flag=1;
  
  while(flag) {
    flag = 0 ;
    for(j=n-1;j>=1;j--) {
      if(a[j] < a[j-1]) {
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	flag = 1;
	cnt++;
      }
    }
  }
  
  
  return cnt;
}
