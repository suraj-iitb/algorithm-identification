#include <stdio.h>
#include <stdlib.h>
#define MAX 2000005
#define VMAX 10005

int A[MAX], B[MAX];
int C[VMAX + 1];

int main()
{

    //unsigned short *A, *B;

    int n, i, j;

    scanf("%d", &n);

    //A = malloc(sizeof(short)*n+1);
    //B = malloc(sizeof(short)*n+1);

    for (i = 1; i <= n; i++)
    {
        //    scanf("%d",A+i);
        scanf("%d", &A[i]);
        // printf("%d ",*(A+i));
        //    C[i]=0;
    }
    //C[n]=0;

    //printf("\n");
    for (j = 1; j <= n; j++)
    {
        C[A[j]]++;
    }
    /*
  for(j=0;j<=n;j++){
    printf("%d ",j);
  }   
  printf("\n");
  
  for(j=0;j<=n;j++){
    printf("%d ",C[j]);
  }   
  printf("\n");
  */

    for (i = 1; i <= VMAX; i++)
    {
        C[i] += C[i - 1];
    }

    /*

  for(j=0;j<=n;j++){
    printf("%d ",C[j]);
  }
  printf("\n");
  */

    for (j = n; j > 0; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }

    for (j = 1; j <= n; j++)
    {
        printf("%d", B[j]);
        if (j != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}

