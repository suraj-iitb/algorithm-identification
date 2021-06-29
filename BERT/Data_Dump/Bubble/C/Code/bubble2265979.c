#include <stdio.h>
int main(){
  int i,j,n,flag=1,hozon,cnt=0;
  scanf("%d",&n);
  int hai[n];
  for(i=0;i<n;i++)
    scanf("%d",&hai[i]);
  
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(hai[j]<hai[j-1]){
	hozon=hai[j-1];
	hai[j-1]=hai[j];
	hai[j]=hozon;
	flag=1;
	cnt+=1;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",hai[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",cnt);

  return 0;
}
