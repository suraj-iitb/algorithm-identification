#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(a[j] < a[j-1]){
                c++;
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i == n-1){
            printf("%d\n", a[i]);
        } else {
            printf("%d ", a[i]);
        }
    }
    printf("%d\n", c);
    return 0;
}
