#include <stdio.h>

int main(){
    int n, p, a[10001], cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &p);
    int t;
    for(int i=0; i< p; i++){
        scanf("%d", &t);
        for(int j=0; j<n; j++){
            if(t==a[j]){
                cnt++;
                break;
            }
        }
    }
    printf("%d\n", cnt);
}
