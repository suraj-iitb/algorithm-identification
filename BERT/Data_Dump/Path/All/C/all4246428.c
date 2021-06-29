#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> hen(n,vector<ll>(n,1e12));

    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        hen[a][b] = c;
    }

    for(int i = 0; i < n; i++)hen[i][i] = 0;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                hen[i][j] = min(hen[i][j], hen[i][k] + hen[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++)if(hen[i][i] < 0){cout << "NEGATIVE CYCLE" << endl;return 0;}

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cout << (hen[i][j] >= 1e11 ? "INF" : to_string(hen[i][j])) << (j == n - 1 ? '\n' : ' '); 
    }
}
