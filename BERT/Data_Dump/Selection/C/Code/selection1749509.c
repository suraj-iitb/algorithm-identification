#include<stdio.h>

int main(){

  int n, m[100], i, j, tmp, c = 0, min;

  scanf("%d",&n);

  for( i = 0; i < n; i++)
    scanf("%d",&m[i]);

  for( i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(m[j] < m[min]){
	min = j;
      }
    }
    if( i != min){
      tmp = m[i];
      m[i] = m[min];
      m[min] = tmp;
      c++;
    }
}

  for( i = 0; i < n; i++){
    printf("%d",m[i]);
    if(i < n - 1)
      printf(" ");
  }
  printf("\n%d\n",c);

  return 0;
}
