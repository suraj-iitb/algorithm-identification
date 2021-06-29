#include<stdio.h>

int binarysearch(int *,int,int);

int binarysearch(int *S,int T,int n)
{
  int right = n,left = 0;
  int mid;

  while(right > left){
    mid = (right+left) / 2;
    if(S[mid] == T){
      return 1;
    }else if(T < S[mid]){
      right = mid;
    }else{
      left = mid + 1;
    }
  }

  return 0;
}
      
    

int main()
{
  int i,n,q,T,num=0;
  int S[100000];

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(binarysearch(S,T,n) == 1){
      num++;
    }
  }

  printf("%d\n",num);

  return 0;
}

