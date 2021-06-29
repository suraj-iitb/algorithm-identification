#include <stdio.h>
int main(){int n,i,j,v,cnt,frag=0;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++){scanf("%d",&A[i]);}
    frag=1;
    i=0;
    cnt=0;
    while(frag){frag=0;
        for(j=n-1;j>i;j--){if(A[j]<A[j-1]) {v=A[j-1];
             A[j-1]=A[j];
             A[j]=v;
           frag=1;
               cnt=cnt+1;}
        }i++;}
    for(i=0;i<n;i++){printf("%d",A[i]);
        if(i==n-1)printf("\n");
        else printf(" ");}
    printf("%d\n",cnt);
    return 0;}

