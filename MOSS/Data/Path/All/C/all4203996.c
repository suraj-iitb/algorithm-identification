#include <iostream>
#include <algorithm>
#include <vector>
//#define INF 500000000
using namespace std;
const int Max=100;
const long long INF=(1ll<<32);
int V,E;
long long D[Max][Max];
vector<int>G[Max];

void Floyd(){
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++) {
            if (D[i][k] == INF)continue;
            for (int j = 0; j < V; j++) {
                if(D[k][j]==INF)continue;
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
}

int main()
{
    int s,t,d;
    cin>>V>>E;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
        {
            if(i==j){
                D[i][j]=0;
                continue;
            }
            D[i][j]=INF;
        }

    for(int i=0;i<E;i++)
    {
        cin>>s>>t>>d;
        D[s][t]=d;
    }
    Floyd();
    for(int i=0;i<V;i++)
        if(D[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++){
            if(j)cout<<' ';
            if(D[i][j]==INF){
                cout<<"INF";
                continue;
            }
            cout<<D[i][j];
        }

        cout<<endl;
    }
    return 0;
}
