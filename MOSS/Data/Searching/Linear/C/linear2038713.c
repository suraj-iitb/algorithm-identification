#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j = 0, n, s, q, t, cnt = 0;
    int *s_array;

    scanf("%d", &n);
    s_array = malloc(sizeof(int) * (n + 1));
    for(i = 0; i < n; i++){
        scanf("%d", &s);
        s_array[i] = s;
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%d", &t);
        s_array[n] = t;
        while(s_array[j] != t) j++;
        if(j < n) cnt++;
        j = 0;
    }

    printf("%d\n", cnt);

    return 0;
}
