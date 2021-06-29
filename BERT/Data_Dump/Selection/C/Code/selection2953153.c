#include <stdio.h>
  
int main()
{
 
  int i, j, tmp,c=0,minj;
  int number[100];
  int N;
  
  scanf("%d", &N);
 
  

  for (i=0; i<N; i++){
    scanf("%d", &number[i]);
  }
  
  for (i=0; i<N; i++) {
    minj=i;
    for (j=i; j<N; j++) {
      if (number[j] < number[minj]) {
	minj=j;
      }
    }
  if(minj!=i){
	tmp =  number[i];
        number[i] = number[minj];
        number[minj] = tmp;
	c++;
      }
  }


  
 
 
  for (i=0; i<N; i++) {
    if(N-1>i)  printf("%d ", number[i]);
    else printf("%d",number[i]);
  }
  printf("\n%d\n",c);
  return 0;
}

