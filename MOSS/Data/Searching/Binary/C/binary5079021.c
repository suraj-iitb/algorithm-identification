#include<stdio.h>

int main(){

  int n,q,i,j,count=0;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++)scanf("%d",&T[i]);

  int left,right,mid,key;


  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      key=T[i];
      mid=(left+right)/2;
      if(S[mid]==key){
        count++;
        //printf("count=%d\n",key);
        break;
      }
      else if(key<S[mid]){
        right=mid;
        //printf("key<T[mid]\n");
      }else{
        left=mid+1;
        //printf("key<T[]\n");
      }

    }
  }
  printf("%d\n",count);
  return 0;
}

