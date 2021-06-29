#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Len 10001 
int main()
{
    int n;
    int cnt[Len];
    for (int i = 0; i < Len; i++){
        cnt[i] = 0;
    }

    scanf("%d", &n);

    int a[n + 1];

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        cnt[a[i]]++;
    }

    int k = 0;

    for (int i = 0; i < Len; i++){
        for (int j = 0; j < cnt[i]; j ++){
            a[k++] = i;
        }
    }

    for (int i = 0; i < n; i++){
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}   
