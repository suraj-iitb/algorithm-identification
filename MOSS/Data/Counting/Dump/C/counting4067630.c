#include <stdio.h>

#define MAX 2000001
#define VMAX 10000

void CountingSort();

int MAX1[MAX],MAX2[MAX];
int MAX3[VMAX+1];


int main()
{
  int a,i;

  scanf("%d", &a);

  for (i=1;i<=a;i++){
    scanf("%d",&MAX1[i]);
  }
    CountingSort(VMAX,a);

    for(i = 1; i<=a; i++){
    if ( i > 1 ) printf(" ");
    printf("%d", MAX2[i]);
  }
    printf("\n");

    return 0;
}


void CountingSort(int a,int b)
{
  int i,j;

  for (i=0;i<=a;i++){
    MAX3[i] = 0;
  }
  
  //C[i]に iの出現数を記録する
  for (j=1;j<=b;j++){
    MAX3[MAX1[j]]++;
  }

  //C[i]に i以下の数の出現数を記録する
  for (i=1;i<=a;i++){
    MAX3[i]=MAX3[i]+MAX3[i-1];
  }
  
  for (j=b;j>0;j--){
    MAX2[MAX3[MAX1[j]]] = MAX1[j];
    MAX3[MAX1[j]]--;
  }
}

