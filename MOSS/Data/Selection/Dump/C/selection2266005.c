#include <stdio.h>
int main(){
  int i,j,n,cnt=0,min,hozon,flag=0;
  scanf("%d",&n);
  int hai[n];

  for(i=0;i<n;i++)
    scanf("%d",&hai[i]);

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(hai[j]<hai[min]){
	min=j;
	flag=1;
      }
    }
    if(flag==1){
      hozon=hai[i];
      hai[i]=hai[min];
      hai[min]=hozon;
      cnt++;
      flag=0;
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
