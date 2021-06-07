#include<stdio.h>

int main(){
    int i, j, cnt=0;
    int n, q;
    int S[10000], T[500];

    scanf("%d", &n);
    for(i=0;i<n;i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for(i=0;i<q;i++) scanf("%d", &T[i]);

    for(i=0;i<q;i++){
        for(j=0;j<n;j++){
            if(S[j]==T[i]){
                cnt++;
                break;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
