#include<bits/stdc++.h>
using namespace std;
int main(){
    int V,E;scanf("%d%d",&V,&E);
    vector<vector<int>> G(V,vector<int>(V,2e9+10));
    for(int i=0;i<V;i++)G[i][i]=0;
    for(int i=0;i<E;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        G[a][b]=c;
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(G[i][k]==2e9+10 or G[k][j]==2e9+10)continue;
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    for(int i=0;i<V;i++){
        if(G[i][i]<0){
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(j)printf("%s"," ");
            if(G[i][j]==2e9+10)printf("%s","INF");
            else printf("%d",G[i][j]);
        }
        printf("\n");
    }
}
