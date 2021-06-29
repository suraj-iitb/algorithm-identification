#include <stdio.h>
void output(int *,int );
int main(){
  int i,j,n,han=1,hozon,cnt=0;
  scanf("%d",&n);
  int hai[n];
  for(i=0;i<n;i++)
    scanf("%d",&hai[i]);
  
  while(han){
    han=0;
    for(j=n-1;j>0;j--){
      if(hai[j]<hai[j-1]){
	hozon=hai[j-1];
	hai[j-1]=hai[j];
	hai[j]=hozon;
	han=1;
	cnt+=1;
      }
    }
  }
  output(hai,n);
  printf("%d\n",cnt);
  return 0;
}
void output(int *hai,int n){
  int i,j;
  for(i=0;i<n;i++){
    printf("%d",hai[i]);
    if(i==n-1) printf("\n");
    else printf(" ");
  }
  
}
