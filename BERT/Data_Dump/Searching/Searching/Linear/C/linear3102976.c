#include <stdio.h>
int main(void){
    int n, s;
    scanf("%d", &n);
    int ns[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &ns[i]);
    }
    
    scanf("%d", &s);
    int ss[s];
    for (int i=0; i<s; i++) {
        scanf("%d", &ss[i]);
    }
    
    int c = 0;
    
    for (int i=0; i<s; i++) {
        for (int j=0; j<n; j++) {
            if (ss[i] == ns[j]) {
                c++;
                break;
            }
        }
    }
    
    printf("%d\n", c);
}

