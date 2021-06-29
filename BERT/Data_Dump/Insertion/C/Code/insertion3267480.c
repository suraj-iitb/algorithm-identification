#include<stdio.h>
int main(){
  int n,x,a;
  int i,j,k;
  scanf("%d", &n);
  int hairetu[n];
  for(i = 0; i < n; i++){
    scanf("%d", &x);
    hairetu[i] = x;
  }

  for(k = 0; k < n; k++){
    if( k > 0)
      printf(" ");
    printf("%d",hairetu[k]);
  }
  printf("\n");
  
  for(i = 1; i < n; i++){
  
    a = hairetu[i];
    j = i - 1;

    while(1){
      if( !(j >= 0 && hairetu[j] > a) ) break;
      hairetu[j+1] = hairetu[j];
      j--;
    }   


    hairetu[j+1] = a;
    for(k = 0; k < n; k++){
      if( k > 0)
	printf(" ");
      printf("%d", hairetu[k]);
    }
    printf("\n");
  }
  return 0;
}





