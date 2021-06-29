#include <stdio.h>
#define N 100000
#define Q 50000

int main(){
        int i=0,n,q,var[N],var2[Q],f=0,a,b,c;
        scanf("%d",&n);

        while(i<n) {
                scanf("%d",&var[i]);
                i++;
        }

        i=0;
        scanf("%d",&q);
        while(i<q) {
                scanf("%d",&var2[i]);
                i++;
        }

        for(i=0; i<q; i++) {
                a=0;
                b=n;
                while(a<b) {
                        c=(a+b)/2;
                        if(var2[i]==var[c]) {
                                f++;
                                break;
                        }
                        if(var2[i]>var[c])
                                a=c+1;
                        else if(var2[i]<var[c])
                                b=c;
                }
        }
        printf("%d\n",f);


        return 0;
}
