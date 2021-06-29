#include<stdio.h>
#include<stdlib.h>

main(){

  int n,i,j,v,k,h;
  int *m;

  scanf("%d",&n);
  m = malloc(sizeof(int) * n);
  
  for(i = 0 ; i <= n-1 ; i++){
    scanf("%d",&m[i]);
  }
  
  for( i = 0 ; i <= n - 1 ; i++){
    
    v = m[i];
    j = i - 1;
    while(j >= 0 && m[j] > v){
      m[j+1] = m[j];
      j--;
    }
    m[j+1] = v;

    for(h = 0 ; h < n-1 ; h++){
      printf("%d ",m[h]);
    }
    printf("%d\n",m[h]);
  } 
    return 0;
}
