#include <stdio.h>
main(){
  int a,b,c=0,d,e,mini,n[100],i,j;

  scanf("%d",&a);
  for(i = 0; i < a; i++){
    scanf("%d",&n[i]);
}
  for(i = 1; i <= a; i++){
    mini = n[i-1];
    for(j = i; j <= a-1; j++){
     if(mini > n[j]){
	mini = n[j];
	d = j;
      }
    }
    if(n[i-1] != mini){
      e = n[i-1];
      n[i-1] = mini;
      n[d] = e;
    c++;
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
