#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100
#define NMAX 10000000

int num, T[MAX + 1][MAX + 1], S[MAX + 1], G[MAX + 1];

void bahn(int, int);

int main()
{
    int num1, num2, i = 1, j;
    scanf("%d", &num);
    while(i <= num){
        G[i] = 10000000;
        scanf("%d", &num1);
        scanf("%d", &S[num1]);
        for(j = 1; j <= S[num1]; j++){
            scanf("%d", &T[num1][j]);
        }
        i++;
    }
    bahn(1, 0);
    i = 1;
    while(i <= num){
     printf("%d %d\n", i, (G[i] == NMAX) ? (-1) : G[i]);
    i++;
    }

    for(i=0;i<10000;i++)
    {
        printf("");
    }
    return 0;

}

void bahn(int x, int y){
    int i;
    G[x] = y;
    for(i = 1; i <= S[x]; i++){
      if(y+1 < G[T[x][i]]) bahn(T[x][i], y+1);
    }
}
