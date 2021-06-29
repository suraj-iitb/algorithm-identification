#include<stdio.h>
#include<string.h>
int main(){
    int flag = 1, i, j, n, count = 0, s[200], key;
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &s[i]);
    while ( flag == 1) {
        flag = 0;
        for ( j = n - 1; j >= 1; j-- ) {
            if ( s[j] < s[j - 1] ) {
                key = s[j];
                s[j] = s[j - 1];
                s[j - 1] = key;
                count++;
                flag = 1;
            }
        }
    }
    printf("%d", s[0]);
    for ( i = 1; i < n; i++ ) {
        printf(" %d", s[i]);
    }
    printf("\n%d\n", count);
    return 0;
}
