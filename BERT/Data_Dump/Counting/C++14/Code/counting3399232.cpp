//ALDS1_6_A_CountingSort.cpp
#include<bits/stdc++.h>
using namespace std;
const int INF=2E9;
typedef pair<int,int> Pair;
typedef long long LL;
int cnt=0;


int main(){
    int n;
    cin >> n;
    int C[10010]={};
    int tmp;
    int maxV=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        C[tmp]++;
        maxV=max(maxV,tmp);
    }
    int cnt=0;
    for(int i=0;i<=maxV;i++){
        for(int j=0;j<C[i];j++){
            printf("%d",i);
            cnt++;
            if(cnt==n) printf("\n");
            else printf(" ");
        }   
    }
    return 0;
}

