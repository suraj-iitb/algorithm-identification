#include<stdio.h>
#define N 100

int main(){

  int a[N],b,c,d,i,j,count=0;

  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<b;i++){
    c = i;
      for(j=i;j<b;j++){
	if(a[j] <a[c]){
	  c = j;
	}
      }
      	if(c!=i){
	  d = a[i];
	  a[i] = a[c];
	  a[c] = d;
	  count++;
  }
}
  for(i=0;;i++){
    printf("%d",a[i]);
    if(i==b-1){break;}
    printf(" ");
    }
  printf("\n");
  printf("%d",count);
  printf("\n");
  

  return 0;
}
	  
