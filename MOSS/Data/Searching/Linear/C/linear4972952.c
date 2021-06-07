#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n;
    int cnt=0;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++)scanf("%d",&s[i]);
    int q;
    scanf("%d",&q);
    int t[q];
    for(int i=0;i<q;i++)scanf("%d",&t[i]);

    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(t[i]==s[j]){
                cnt++;
                break;
        }
    }
    }
    printf("%d\n",cnt);
    return 0;
}
