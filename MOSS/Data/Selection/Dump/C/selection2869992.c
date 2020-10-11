#include <stdio.h>
#define INF 1e9

int main(void){
    int i,j,l,b,idx,cnt=0,m=INF;
    scanf("%d", &l);
    int ary[l];
    for(i=0;i<l;i++) scanf("%d", &ary[i]);
    for(i=0;i<l-1;i++,m=INF){
        for(j=i+1;j<l;j++){if (m>ary[j]){m=ary[j],idx=j;}}
        if (ary[i]>m){b=ary[i],ary[i]=ary[idx],ary[idx]=b,cnt++;}
    }
    for(i=0;i<l;i++){(i<l-1)? printf("%d ",ary[i]) : printf("%d\n", ary[i]);}
    printf("%d\n",cnt);
    return 0;
}
