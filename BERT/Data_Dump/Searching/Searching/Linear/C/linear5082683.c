#include <stdio.h>

int main(){
    int n,s[10000],q,t[500],c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&t[i]);
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(t[i] == s[j]){
                c++;
                break;
            }
        }
    }
    printf("%d\n",c);
}

