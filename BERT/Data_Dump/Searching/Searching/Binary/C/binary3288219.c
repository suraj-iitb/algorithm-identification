#include<stdio.h>
#define N 100000

int main(){
  int n,i,m,a,cnt=0;
  int num[N];
  int l,mid,r;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&num[i]);
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&a);
    r=n;
    l=0;
    while(l<r){
      mid=(l+r)/2;
      if(a==num[mid]){
	cnt++;
	break;
      }
      if(a>num[mid])l=mid+1;
      else if(a<num[mid])r=mid;
    }
  }
    printf("%d\n",cnt);
    return 0;
  }
      
    

