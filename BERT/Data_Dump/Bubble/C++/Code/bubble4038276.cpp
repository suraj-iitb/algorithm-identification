#include <stdio.h>

#define N 100

int bubbleSort(int *,int);

int main(){
  int s,t[N],i;
  scanf("%d",&s);

  for(i=0;i<s;i++)
    scanf("%d",&t[i]);

  printf("%d\n",bubbleSort(t,s));

  return 0;
}




int bubbleSort(int *t,int s){
  int  flag=1,j,swap,count=0,i;

  while(flag){
    flag=0;
    for(j=s-1;j>0;j--){
      if(t[j]<t[j-1]){
	swap=t[j];
	t[j]=t[j-1];
	t[j-1]=swap;
        flag=1;
	count++;
      }
    
    }
  }
  for(i=0;i<s-1;i++)
    printf("%d ",t[i]);
  printf("%d\n",t[s-1]);

  return count;
}


