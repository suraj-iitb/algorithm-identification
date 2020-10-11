#include<stdio.h>
#define N 100
int main(){
  int i,j,k[N],temp,l,flag=0;
  scanf("%d",&j);
  for(i=0;i<j;i++)
    scanf("%d",&k[i]);
  
  for(i=0;i<j;i++){
    for(l=j-1;l>i;--l){
      if(k[l-1]>k[l]){
	temp = k[l-1];
	k[l-1] = k[l];
	k[l] = temp;
	flag++;
      }
    }
  }
  for(i=0;i<j;++i){
    if(i>0)printf(" ");
    printf("%d",k[i]);
  }
      
  printf("\n");
  printf("%d\n",flag);
  return 0;
}
	  
