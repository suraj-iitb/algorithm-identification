#include<stdio.h>

int main(){

  int i, n, m[100], flag = 1, tmp, c = 0;

  scanf("%d",&n);

  for( i = 0; i < n; i++){
    scanf("%d",&m[i]);
  }

  while(flag){
    flag = 0;
      for( i = n-1; i >= 1; i--){
	if( m[i] < m[i-1]){
	  tmp = m[i];
	  m[i] = m[i-1];
	  m[i-1] = tmp;
	  flag = 1;
	  c++;
	}
      }
  }
  for(i = 0; i < n; i++){
    printf("%d",m[i]);
    if(i < n-1)
      printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}
