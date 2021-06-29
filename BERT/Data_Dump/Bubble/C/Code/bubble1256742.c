#include <stdio.h>
int main()
{
    int n, a[100], i, j, cnt=0, c;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        for(j = (n - 1); j >= (i + 1); j--){
            if(a[j] < a[j - 1]){
                c = a[j];
                a[j] = a[j - 1];
                a[j - 1] = c;
                cnt++;
            }
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
