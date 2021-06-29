#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int minj = i;
        for(int  j = i; j < n; j++){
            if(a[j] < a[minj]){
                minj = j;
            }
        }
        if(minj != i){
            int temp = a[i];
            a[i] = a[minj];
            a[minj] = temp;
            cnt++;
        }
    }

    for(int  i = 0; i < n; i++){
        if(i == n-1) printf("%d\n", a[i]);
        else printf("%d ", a[i]);
    }
    printf("%d\n", cnt);
    return 0;
}
