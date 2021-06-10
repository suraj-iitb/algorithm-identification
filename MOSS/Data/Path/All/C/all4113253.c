#include<iostream>
#include<algorithm>

using namespace std;
#define INFTY 2000000000
#define N 9900
#define MAX 9900

int v,e,D[N][N],s[N],t[N],d[MAX],minv = INFTY,r[N][N];

int main(){
    
    cin >> v >> e;

    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            if(i != j)D[i][j] = INFTY;
            else D[i][j] = 0;
        }
    }
    
    for(int i = 0;i < e;i++){
        cin >> s[i] >> t[i] >> d[i];
        D[s[i]][t[i]] = d[i];
    }
        
    
    for(int k  = 0;k < v;k++){
        for(int i = 0;i < v;i++){
            if(D[i][k] == INFTY)continue;
            for(int j = 0;j < v;j++){
                if(D[k][j] == INFTY)continue;
                D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
            }
        }
    }
    
	bool a = true;

	for(int i = 0; i < v; i++){
		    if(D[i][i] < 0){
			    a = false;
			    break;
		}
	}
    
    if(!a)cout << "NEGATIVE CYCLE" << endl;
    else{
        for(int i  = 0;i < v;i++){
            if(D[i][0] == INFTY)cout << "INF";
            else cout << D[i][0];
            for(int j = 1;j < v;j++){
                if(D[i][j] == INFTY)cout << " " << "INF";
                else cout << " " << D[i][j];
            }
            cout << endl;
        }
    }
}
