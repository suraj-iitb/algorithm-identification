#include <stdio.h>

int main()
{
    int N, i, j, flag = 0, mini;
    int x[105];
    scanf("%d",&N);
    for(i = 0;i < N;i++)
        scanf("%d",&x[i]);
    for(i = 0;i < N - 1;i++)
    {
        mini = i;
        for(j = i;j < N;j++)
        {
            if(x[j] < x[mini])
                mini = j;
        }
        int t = x[i];
        x[i] = x[mini];
        x[mini] = t;
        if(i != mini)
            flag++;
    }
    for(i = 0;i < N;i++)
    {
        if(i > 0) printf(" ");
        printf("%d",x[i]);
    }
    printf("\n%d\n",flag);
    return 0;
}
