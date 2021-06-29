#include<stdio.h>

#define FOUND 1
#define NOT_FOUND 0

int binarysearch(int *,int ,int );

int main(){
  int i,n,s[100000],q,t[50000],c=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t[i]);
    c = c + binarysearch(s,n,t[i]);
  }

  printf("%d\n",c);

  return 0;
}

int binarysearch(int *a,int n,int key){
  int left,right,mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right) / 2;
    if(a[mid] == key){
      return FOUND;
    }
    else if(key < a[mid]){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return NOT_FOUND;
}
