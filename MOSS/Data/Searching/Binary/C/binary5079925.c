#include <stdio.h>
#include <stdlib.h>
int n, *s;

int binarySearch(int x){
  int left=0, right=n, mid;
  while(left<right){
    mid=(left+right)/2;
    if(s[mid]==x){
      return 1;
    }else if(x<s[mid]){
      right=mid;
    }else{
      left=mid+1;
    }
  }
  return 0;
}
int main(void){

  int  i, q, *t, count=0;

  scanf("%d", &n);
  s=(int *)malloc((n+1)*sizeof(int));
  for(i=0; i<n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  t=(int *)malloc(q*sizeof(int));
  for(i=0; i<q; i++){
    scanf("%d", &t[i]);
  }

  for(i=0; i<q; i++){
    if(binarySearch(t[i])==1){
      count++;
    }else if(binarySearch(t[i])==0){
      continue;
    }
  }

  printf("%d\n", count);

  return 0;
}

