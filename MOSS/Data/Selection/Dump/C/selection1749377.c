#include<stdio.h>

int selectionSort(int *,int);

int main() {
  
  int n,a[100],i,b[100],cnt=0;
  
  // input data
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  // sort
  cnt = selectionSort(a,n);
  
  // output sorted data
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",cnt);
  
  return 0;
}

// Sort by selection sort and asc.
int selectionSort(int *a, int n) {
  
  int tmp,i,j,cnt=0,minj,bef;
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++) {
      if(a[j] < a[minj]) {
	minj = j;
      }
    }
    if(a[i] != a[minj]){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      cnt++;
    }
  }
  
  
  return cnt;
}
