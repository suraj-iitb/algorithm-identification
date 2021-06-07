#include <stdio.h>

int S[10001], T[501];
int n, q;

int search(int key){

    int i = 0;

    // 番兵追加
    S[n] = key;

    // 探索　見つかれば脱
    while(S[i] != key){
        i++;
    }

    if(i == n) return 0;
    else return 1;
}

int main() {

    int i;
    int cnt = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T[i]);
    }


    i = 0;

    while(i < q){
        if(search(T[i])){
            cnt++;
        }
        i++;
    }
    printf("%d\n", cnt);

    return 0;
}
