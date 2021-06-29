#include <stdio.h>
 
int main(){
    int t,i=0,j,d[100],n,c,m;
    scanf("%d",&n);
    while(i!=n){
        scanf("%d",&d[i]);
        i++;
    }
 
    for(i=0,c=0;i<=n-1;i++){
        m = i;
        for(j=i;j<=n-1;j++){
            if(d[j] < d[m]){
                m = j;
            }
        }
        if(d[i] != d[m])c++;
        t = d[i];
        d[i] = d[m];
        d[m] = t;
    }
    for(i=0;i<=n-1;i++){
        i <n-1 ? printf("%d ",d[i]):printf("%d\n",d[i]);
    }
    printf("%d\n",c);
    return 0;
}
