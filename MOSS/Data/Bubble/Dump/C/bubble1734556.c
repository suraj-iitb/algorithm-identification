#include <stdio.h>

#define N 100
#define A 100

/*int swap(int num[],int n)
{
  int i;
  for(i=0;i<=n;i++){
    if(num[i]<num[i-1]){



    return num;
}
*/

int main(){
  int flag,i,j,num[N],count=0,in,key;

  scanf("%d",&in);

  for(i=0;i<in;i++){

    scanf("%d",&num[i]);

  }
  for(j=in-1;j>0;j--){
  for(i=in-1;i>0;i--){

      if(num[i-1]>num[i]){

	key=num[i-1];
	num[i-1]=num[i];
	num[i]=key;

    count++;
      }
  }
  }

  for(i=0;i<in-1;i++){

    printf("%d ",num[i]);

  }
  printf("%d",num[i]);
  printf("\n");
  printf("%d\n",count);

  return 0;
}
