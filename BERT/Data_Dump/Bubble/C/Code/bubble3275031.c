#include <stdio.h>


int main(){

  int n,i,j,num[100],cnt=0,tmp;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&num[i]);
  }

   
  for(i=0;i<n;i++){
 
      for(j=n-1;j >= i+1;j--){     
	if(num[j-1] > num[j]){
	  tmp = num[j-1];
	  num[j-1]=num[j];
	  num[j]=tmp;
	  cnt++;
	}
      }
  
    }

   for(i=0;i<n;i++){
    printf("%d",num[i]);
    if(i !=n-1)printf(" ");
  }
   printf("\n%d\n",cnt);

  return 0;
}


