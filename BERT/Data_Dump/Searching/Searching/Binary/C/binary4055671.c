#include <stdio.h>

int search(int *,int,int);

int main(){
  int i,n,q,c=0,s[100000],t;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  
  for(i=0;i<q;i++){
    scanf("%d",&t);
    c += search(s,t,n);
  }
   printf("%d\n",c);
   return 0;
}

int search(int s[],int t,int n){
  int left=0,right=n,mid;

  while(left < right){
    mid =(left+right)/2;
    if(t == s[mid])return 1;
    if(t > s[mid])left = mid +1;
    else if(t < s[mid])right = mid;
  }
  
  return 0;
}

