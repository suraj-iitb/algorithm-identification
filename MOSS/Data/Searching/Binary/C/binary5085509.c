#include<stdio.h>


int main(){
  int a,b,i,j,cnt=0,n=0,m,l;
  int s[100005],k[50005];
  
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&b);
  for(j=0;j<b;j++){
    scanf("%d",&k[j]);
  }
  
  for(j=0;j<b;j++){
    n=0;
    l=a;
    while(1){
      m=(l+n)/2;
      if(s[m]==k[j]){
	cnt++;
	break;
      }
      else if(l==n+1)break;
      else if(s[m]>k[j]){
	l=m;
      }
      else if(s[m]<k[j]){
	n=m;
      }
    }
  }

  
  printf("%d\n",cnt);
  return 0;
}

