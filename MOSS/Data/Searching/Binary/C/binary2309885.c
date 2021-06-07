#include <stdio.h>
int A[100000];
int n;

int bsearch(int x){
  int max=n,min=0,mid;
  mid=max/2;
  while(max>min){
    if(A[mid]==x) return 1;
    else if(x>A[mid]) min=mid+1;
    else max=mid;
    mid=(max+min)/2;
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  /* code */
  int i,n2,x,sum=0;

  scanf("%d\n",&n);
  for (i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d\n",&n2);
  for (i=0;i<n2;i++){
    scanf("%d",&x);
    if(bsearch(x)) sum++;
  }
  printf("%d\n",sum);
  return 0;
}
