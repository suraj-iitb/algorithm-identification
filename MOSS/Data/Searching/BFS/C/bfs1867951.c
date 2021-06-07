#include <stdio.h>
#define MAX 100

int Hira[MAX][MAX], size[MAX], high[MAX];
 
void visit(int k, int t){
    int i;
    high[k] = t;
    for (i = 1; i <= size[k]; i++){
        if (high[Hira[k][i]] > t)visit(Hira[k][i], t + 1);
    }
}
 
int main()
{
  int i, j, n,k;
 
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        high[i] = 10000;
        for (j = 1; j <= n; j++)Hira[i][j] = 0;
    }
 
    for (i = 1; i <= n; i++){
        scanf("%d", &k);
        scanf("%d", &size[k]);
        for (j = 1; j <= size[k]; j++)scanf("%d", &Hira[k][j]);
    }
 
    visit(1, 0);
 
    for (i = 1; i <= n; i++){
        if (high[i] == 10000)high[i] = -1;
        printf("%d %d\n", i, high[i]);
    }
    return 0;
}
