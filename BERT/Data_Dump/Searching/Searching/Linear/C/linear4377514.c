#include<stdio.h>
#include<stdlib.h>
int linearSearch(int n,int *s, int q, int *t){
    int i,j;
    for(i=0;i<n;i++){
        if(*(s+i)==*t) return 1;
    }
    return 0;
}
int main(void){
    int n,q,j,B,count=0;
    int *s,*t;
    scanf("%d\n",&n);
    s=malloc(sizeof(int)*(n));
    for(j=0;j<n;j++){
        scanf("%d",(s+j));
    }
    scanf("%d\n",&q);
    t=malloc(sizeof(int)*(q));
    for(j=0;j<q;j++){
        scanf("%d",(t+j));
    }

    for(j=0;j<q;j++){
        B=linearSearch(n,s,q,t+j);
        if(B==1) count++;
    }
   printf("%d\n",count);

    free(s);
    free(t);
    return 0;
}
