#include<stdio.h>
#define NUM 10000

int main(){
  int i,j,n1,n2,count=0,temp;
  int a[NUM];

  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }


  scanf("%d",&n2);
  for(j=0;j<n2;j++){
    scanf("%d",&temp);
    for(i=0;i<n1;i++){
      if(a[i]==temp){
	count++;
	break;
      }
    }
	
  }

  

  printf("%d\n",count);

return 0;
}

