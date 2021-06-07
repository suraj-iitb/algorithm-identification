#include<stdio.h>

int main(){

  int n,q;
  int i,j;
  int s[100000],t,c=0;
  int left=0,mid=0,right=0;
  scanf("%d",&n);

  for(i=0; i < n; i++){
    scanf("%d",&s[i]);
  }

  right=n;
  scanf("%d",&q);

for(j=0; j < q; j++){
    scanf("%d",&t);
    while(left < right){
    mid=(left+right)/2;
    if(t==s[mid]){
      c++;
      break;
    }
    else if(t > s[mid]){
      left=mid+1;
    }
    else if(t < s[mid]){
      right=mid;
    }
    }
    left=0;
    right=n;
    mid=0;
}

 printf("%d\n",c);

 return 0;
}
