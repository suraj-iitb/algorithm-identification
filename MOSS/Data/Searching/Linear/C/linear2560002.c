#include<stdio.h>

int linear_search(int *s, int n, int key)
{
    int i = 0;
    while(s[i] != key){
        i++;
    }
    if(i == n) return 0;
    return 1;
}

int main()
{
    int s[10001], key, i, n, q, cnt = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &key);
        s[n] = key;
        if(linear_search(s, n, key)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
