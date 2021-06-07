#include<stdio.h>
#define S 100000
#define T 100000
int main(){
  int i,j,n,q,count=0;
  int s[S];
  int t[T];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&t[i]);
  }
  for(j = 0; j < q; j++){
    for(i = 0; i < n; i++){
      if(t[j] == s[i]){
	count++;  
	break; 
      }
    }
  }
  if(count == 0){
    printf("0\n");
  }
  else printf("%d\n",count);
  return 0;
}
