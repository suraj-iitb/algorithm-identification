#include<stdio.h>

int main(){
  int i,j,n,q,key,c=0;
  int left=0,right=n,mid;
  scanf("%d",&n);
  int s[n];
  for(i=0;i<n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(j=0;j<q;j++){
    int left=0,right=n,mid;
    scanf("%d",&key);
    
    while(left<right){
      mid=(left+right)/2;
      if(s[mid]==key){c++;break;}
      else if (key<s[mid])right=mid;
      else left=mid+1;
    }
  }
  printf("%d\n",c);
    return 0;
}

