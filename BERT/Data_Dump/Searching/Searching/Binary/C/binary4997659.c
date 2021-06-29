#include <stdio.h>

int main(){
    int n, q, a[100001], t, cnt=0, found=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d", &t);
        int l=0, u=n-1, m=0;
        while(!found&&l<=u){
            m=(l+u)/2;
            if(a[m]<t){
                l=m+1;
            }
            else if(a[m]>t){
                u=m-1;
            }
            else found=1;
        }
        if(found)cnt++;
        found=0;
    }
    printf("%d\n", cnt);
}

