#include <stdio.h>

int S[100000], n;

int BynarySearcH(int KY)
{

    int LeFt = 0;
    int RiGhT = n;
    int MiD;

    while (LeFt < RiGhT)
    {
        MiD = (LeFt + RiGhT) / 2;
        if (KY == S[MiD])
            return 1;
        if (KY > S[MiD])
            LeFt = MiD + 1;
        else if (KY < S[MiD])
            RiGhT = MiD;
    }

    return 0;
}

int main()
{

    int i, q, k, SuM = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d", &k);
        if (BynarySearcH(k))
            SuM++;
    }

    printf("%d\n", SuM);

    return 0;
}
