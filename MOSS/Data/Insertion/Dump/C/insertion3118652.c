#include<stdio.h>
int main (){
  int a,b[100],v,j;
  scanf("%d",&a);

  for(int i=0;i<a;i++){
    scanf("%d",&b[i]);
  }
      for(int g=0;g<a;g++){
	if(g==a-1)printf("%d",b[g]);
	else printf("%d ",b[g]);
  }
	printf("\n");

  for(int i=1;i<a;i++){
    
    v = b[i];
    j = i - 1;
   while (j >= 0 && b[j] > v){
     b[j+1] = b[j];
     j--;
     b[j+1] = v;
   }
  

      for(int g=0;g<a;g++){
	if(g==a-1)printf("%d",b[g]);
	else printf("%d ",b[g]);
  }
      printf("\n");
  }

  
  return 0;
}

