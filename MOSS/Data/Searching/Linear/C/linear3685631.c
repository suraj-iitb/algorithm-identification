#include <stdio.h>

int main()
{
    int n, q, i, j, save, temp;
    int countn = 0, countq = 0;
    int s[10001];
    int t[501];
    
    scanf("%d", &n);
    for (i = 0;i < n; i++){
        save = 1;
        scanf("%d", &temp);
        for(j = 0; j < countn; j++) {
            if (temp == s[j]) {
                save = 0;
                break;
            }
        }
        if (save){
            s[countn] = temp;
            countn++;
        }
    }
    
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        save = 1;
        scanf("%d", &temp);
        for(j = 0; j < countq; j++) {
            if (temp == t[j]) {
                save = 0;
                break;
            }
        }
        if (save){
            t[countq] = temp;
            countq++;
        }
    }
    
    int count = 0;
    for (i = 0; i < countn; i++){
        for (j = 0; j < countq; j++){
            if (s[i] == t[j]) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
