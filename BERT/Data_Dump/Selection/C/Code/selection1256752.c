#include <stdio.h>
int main()
{
    int n, a[100], i, j, cnt=0, c, mini;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        mini = i;
        for(j = i; j < n; j++){
            if(a[j] < a[mini]){
                mini = j;
            }
        }
        if(i != mini){
            cnt++;
            c = a[mini];
            a[mini] = a[i];
            a[i] = c;
        }
    }
    for(i = 0; i < n; i++){
        if(i == (n - 1)){
            printf("%d\n", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
