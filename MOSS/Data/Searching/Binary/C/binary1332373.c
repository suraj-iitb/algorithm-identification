#include<stdio.h>
int main(){
  int n1,n2,S[100000],T[1000000];
  int i,count=0;
  int left,right,mid;
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&S[i]);

  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<n2;i++){
    left = 0;
    right = n1;
  while(left < right){

      mid = (left + right)/2;
      if(S[mid] == T[i]) {count++;break;}
      else if(T[i] < S[mid]){right=mid;}
      else {left = (mid+1);}

    }

  }
  printf("%d\n",count);
  return 0;

}
