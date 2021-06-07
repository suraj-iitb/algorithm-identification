#include <stdio.h>

int Ans[1000];
int l = 0;

int hantei(int num){
    for(int i = 0; i < l; i++){
        if(num == Ans[i]){
            return -1;
        }
    }
    return 1;
}

int main(){
    int i, j, k, m, n, b;
    int A[10000];

    scanf("%d", &m);

    for(i = 0; i < m; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &b);
        for(j = 0; j < m; j++){
            if(b == A[j] && hantei(b) != -1){
                Ans[l] = b;
                l++;
            }
        }
    }

    printf("%d\n", l);

    return 0;

}
