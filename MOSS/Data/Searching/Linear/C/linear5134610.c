#include <stdio.h>
int main()
{
    int a, b;
    int g = 0;
    scanf("%d", &a);
    int c[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &c[i]);
    }
    scanf("%d", &b);
    int d[b];
    for (int j = 0; j < b; j++)
    {
        scanf("%d", &d[j]);
        for (int i = 0; i < a; i++)
        {
            if (c[i] == d[j]){
                g++;
            break;}
            
        }
    }

    printf("%d\n", g);

    return 0;
}
