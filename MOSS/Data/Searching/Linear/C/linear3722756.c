#include<stdio.h>

int main(){
    int n, q;
    int s[11000], t[1000];
    int i, j;
    int ans=0;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &s[i]);
    }

    scanf("%d", &q);
    for(i=0; i<q; i++){
        scanf("%d", &t[i]);
    }

    for(i=0; i<q; i++){
        for(j=0; j<n; j++){
            if(s[j]==t[i]){
                ans++;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
