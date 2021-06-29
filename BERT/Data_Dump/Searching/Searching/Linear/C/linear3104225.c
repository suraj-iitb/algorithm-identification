#include <stdio.h>
#define STR 10000

int n, q, i, j, cnt = 0;
int s[STR];
int t[STR];

int Serch() {
    for(j = 0 ; j < n ; j++) {
        if(s[j] == t[i]) {
            return(cnt++);
        }
    }
}

int main(void){
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++) {
        scanf("%d", &s[i]);
    }
    
    scanf("%d", &q);
    for(i = 0 ; i < q ; i++) {
        scanf("%d", &t[i]);
    }
    
    for(i = 0 ; i < q ; i++) {
      Serch();
    }
    printf("%d\n", cnt);
    return 0;
}

