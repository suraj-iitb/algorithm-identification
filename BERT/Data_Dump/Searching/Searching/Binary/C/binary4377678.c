#include<stdio.h>
#include<stdlib.h>
int binarySearch(int n,int *s, int q, int *t){
    int left=0,right=n,i,mid;
     while(left<right){
         mid=(left+right)/2;
         if(*(s+mid) == *t) return 1;
         else if(*t<*(s+mid)) right=mid;
         else left=mid+1;
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
        B=binarySearch(n,s,q,t+j);
        if(B==1) count++;
    }
    printf("%d\n",count);
    free(s);
    free(t);
    return 0;
}
