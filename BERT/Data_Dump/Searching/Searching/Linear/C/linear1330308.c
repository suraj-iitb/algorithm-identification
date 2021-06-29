#include<stdio.h>

int main(void)
{
  int S[10000],S2[5000];
  int n,n2,i,j,cou = 0;
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
  scanf("%d", &S[i]);
  }



  scanf("%d",&n2);

  for(i = 0; i < n2; i++){
  scanf("%d", &S2[i]);
  }

  for(i = 0; i < n2; i++){
    for(j = 0; j < n; j++){
      if(S[j] == S2[i]){
	cou++;
	break;
      }
    }
  }

  printf("%d\n",cou);
  return 0;
}
