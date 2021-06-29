#include<stdio.h>
#include<stdlib.h>

#define MAX 10000

main(){
unsigned short *x, *y;/*0~255 */

  int n,i,count[MAX+1];
  scanf("%d", &n);

  x = malloc(sizeof(short)* n+1);
  y = malloc(sizeof(short)* n+1);

  for (i=0; i<=MAX; i++)
    count[i]=0;


  for (i=0; i<n; i++){

    scanf("%d",&x[i+1]);
    count[x[i+1]]++;
  }

  for (i=1; i<=MAX; i++)
    count[i]=count[i]+count[i-1];

  for (i=1; i<=n; i++){
    y[count[x[i]]] = x[i];
    count[x[i]]--;
  }

  for (i=1; i<=n; i++){

    if(i>1) printf(" ");

    printf("%d",y[i]);
  }

  printf("\n");
  return 0;
}

