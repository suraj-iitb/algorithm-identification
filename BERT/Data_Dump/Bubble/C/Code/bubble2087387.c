#include <stdio.h>

int bubbleSort(int *a, int n){
    int flag = 1, j, v, cnt = 0;
    while(flag){
        flag = 0;
        for(j = n - 1;j > 0;j--){
            if(a[j] < a[j-1]){
                v = a[j];
                a[j] = a[j-1];
                a[j-1] = v;
                flag = 1;
                cnt++;
            }
        }
    }
    return cnt;
}


int main(int argc, const char * argv[]) {
    int N = 100;
    int a[N];
    int n, i, cnt;
    scanf("%d", &n);
    for(i = 0;i < n;i++){
        scanf("%d", &a[i]);
    }
    cnt = bubbleSort(a, n);
    for(i = 0;i < n;i++){
        printf("%d", a[i]);
        if(i < n-1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}
