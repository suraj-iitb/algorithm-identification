#include<stdio.h>
int main(){
  int i,j,k;
  int a[100];
  int flag=1;
  int swap;
  int con=0;
  scanf("%d",&i);
  for(j=0;j<i;j++){
    scanf("%d",&a[j]);
  }
  while(flag){
    flag=0;
    for(j=i-1;0<j;j--){
      if(a[j]<a[j-1]){
	swap=a[j];
	a[j]=a[j-1];
	a[j-1]=swap;
	flag=1;
	  con+=1;
      }
    }
  }
    for(j=0;j<i;j++){
       if(j==0) printf("%d",a[j]);
       else printf(" %d",a[j]);
    }
      printf("\n");
    printf("%d\n",con);
  }

