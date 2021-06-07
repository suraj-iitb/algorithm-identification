#include<stdio.h>
#include<string.h>

int n, q,s[100000], t,  c=0;

int serch(int a[], int n, int t){
    int l=0, r=n, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(a[mid] == t) return 1;
        else if(t < a[mid]) r = mid;
        else l = mid + 1;
    }
    return 0;
}


int main(void){
    scanf("%d", &n);
    for(int i=0 ; i<n ; i++)
        scanf("%d",&s[i]);

    scanf("%d",&q);
    for(int i=0 ; i<q ; i++){
        scanf("%d",&t);
        c += serch(s, n, t);
    }

    printf("%d\n", c);

    return 0;
}
