#include<stdio.h>
int main(){
 int n,q,i,j;
 int c=0;
 scanf("%d",&n);
 int S[n];
 for(i=0;i<n;i++) scanf("%d",&S[i]);
 scanf("%d",&q);
 int T[q];
 for(i=0;i<q;i++){ 
 scanf("%d",&T[i]);
    for(j=0;j<n;j++){
        if(S[j]==T[i]){
            c++;
            break;
        }
    }
 }
 printf("%d\n",c);
 return 0;
}
