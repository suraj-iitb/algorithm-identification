#include <stdio.h>

int main(){
    int n, a[1000], v, i, j, k;
    scanf("%d\n",&n);
    for(i=0; i<n; i++) scanf("%d", &a[i]);

    for(k=0; k<n; k++){
        if(k!=n-1) printf("%d ", a[k]);
        else printf("%d\n", a[k]);
    }

    for(i=1; i<n; i++){
        v = a[i];
        j = i - 1;
        while(j>=0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(k=0; k<n; k++){
            if(k!=n-1) printf("%d ", a[k]);
            else printf("%d\n", a[k]);
        }
    }

    return 0;
}

