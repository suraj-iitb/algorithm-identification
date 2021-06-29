#include<stdio.h>
#include<string.h>
int main(){
    int flag = 1, i, j, n, count = 0, s[200], key;
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &s[i]);
    for ( i = 0; i < n - 1; i++ ) {
        flag = i;
        for ( j = i; j < n; j++ ) {
            if ( s[j] < s[flag]) flag = j;
        }
        key = s[i];
        s[i] = s[flag];
        s[flag] = key; 
        if ( i != flag ) count++;
    }
    printf("%d", s[0]);
    for ( i = 1; i < n; i++ ) {
        printf(" %d", s[i]);
    }
    printf("\n%d\n", count);
    return 0;
}
