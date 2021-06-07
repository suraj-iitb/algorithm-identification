#include<stdio.h>
#define N 10000
#define Q 500
int main(){
    
    int n,q,i,j,k,u = 0,cnt = 0,flg = 0;
    int a[N],b[Q],c[Q];

    scanf("%d",&n);
    for( i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for( i = 0; i < q; i++){
        scanf("%d",&b[i]);
    }
    for(k = 0; k < q; k++){
        c[k] = -1;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
            flg = 0;
            for(k = 0; k < u; k++){
                if(c[k] == a[i]) flg++;
            }
            if( a[i] == b[j] && flg == 0 ){
                cnt++;
                c[u++] = b[j];
            }
        }
    }
    printf("%d\n",cnt);
    
    return 0;
}
