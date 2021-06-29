#include<stdio.h>

int main(){
  int n,m,i,j,a,cnt=0;
  int num[10000];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&num[i]);
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&a);
    for(j=0;j<n;j++){
      if(a==num[j]){
	cnt++;
	break;
      }
    }
  }
  printf("%d\n",cnt);
  return 0;
}
  
    

