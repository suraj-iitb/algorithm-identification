#include <stdio.h>

int linerSearch(int n, int *s, int key) {
    int i;
    for(i = 0; i < n; i ++) {
        if(s[i] == key) return 1;
    }
    return 0;
}

int main(){
    int cou = 0;
    int n;
    int i,s[10010];

    scanf("%d",&n);
    for(i = 0;i < n;i++ ) {
        scanf("%d",&s[i]);
    }

    int q;
    int t;

    scanf("%d",&q);
    for(i = 0; i < q; i++) {
        scanf("%d",&t);
        cou += linerSearch(n,s,t);
    }

    printf("%d\n",cou);
    return 0;
}

