#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int ar[n],Max=0;

    for(int i=0; i<n; i++){
        scanf("%d",&ar[i]);
        if(Max<ar[i]) Max=ar[i];
    }

    Max+=1;
    int cnt[Max]={0};
    for(int i=0; i<n; i++){
        ++cnt[ar[i]];
    }
    for(int i=1; i<Max; i++){
        cnt[i]=cnt[i]+cnt[i-1];
    }

    int br[n];
    for(int i=n-1; i>=0; i--){
        br[--cnt[ar[i]]]=ar[i];
    }

    printf("%d",br[0]);
    for(int i=1; i<n; i++) printf(" %d",br[i]);
    printf("\n");
    return 0;
}

