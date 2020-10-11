#include <stdio.h>
main(){
  int a,c=0,d,n[100],i,j;
  scanf("%d",&a);
  for(i = 0; i < a; i++){
    scanf("%d",&n[i]);
  }
  for(i = 0; i <= a-1;i++){
    for(j =  a-1;j >= i+1; j--){
      if(n[j] < n[j-1]){
	d = n[j-1];
	n[j-1] = n[j];
	n[j] = d;
	c++;
      }  
    }
  }
  for(i = 0; i < a; i++){
    printf("%d",n[i]);
    if(i != a-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",c);   
  return 0;
}
