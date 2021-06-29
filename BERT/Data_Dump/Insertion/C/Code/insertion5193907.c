#include<stdio.h>

int main(){

  int n,v,j,i,c,x;

  scanf("%d" ,&n);


  int a[1000];
  for( i = 0; i < n; i++){
    scanf("%d" ,&a[i]);
  }
  if(i < 1){
    return 0;
  }
  
  
  for( x = 0; x < n - 1; x++){
  printf("%d ",a[x]);
  }
   printf("%d",a[x]);
     printf("\n");

    for( c = 1; c <= n - 1; c++){
	 v = a[c];
         j = c - 1;
	 while( j >= 0 && a[j] > v ){
	   a[j + 1] = a[j];
	   j--;
	   a[j + 1] = v;
		  }
       
	 for( x = 0; x < n - 1; x++){
	   printf("%d ",a[x]);
	 }
	  printf("%d",a[x]);
	  printf("\n");
    }
     
	 return 0;
    }
    


