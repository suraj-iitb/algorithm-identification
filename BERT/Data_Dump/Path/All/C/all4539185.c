#include<bits/stdc++.h>

const static long long int INF = (1LL<<32);

void warshallFloyd(int v, std::vector<std::vector<long long int>>& darray){
    for(int k = 0; k < v; k++){
        for(int i = 0; i < v; i++){
            if(darray[i][k] == INF) continue;

            for(int j = 0; j < v; j++){
                if(darray[k][j] == INF) continue;
                darray[i][j] = std::min(darray[i][j], darray[i][k] + darray[k][j]);
            }
        }
    }
}


int main(void){
    int v, e;
    std::cin >> v >> e;
    int s, t;
    long long int d;

    std::vector<std::vector<long long int>> darray;
    darray.resize(v);

    for(int i = 0; i < v; i++){
        darray[i].resize(v);
        for(int j = 0; j < v; j++){
            darray[i][j] = ( (i == j) ? 0 : INF );
        }
    }

    for(int i = 0; i < e; i++){
        std::cin >> s >> t >> d; 
        darray[s][t] = d;
    }

    warshallFloyd(v, darray);
    bool neg = false;

    for(int i = 0; i < v; i++){
        if(darray[i][i] < 0){
            std::cout << "NEGATIVE CYCLE" << std::endl;
            neg = true;
            break;
        }
    }
    if(!neg){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(j != 0){
                    std::cout << " ";
                }
                if(darray[i][j] == INF){
                    std::cout << "INF";
                }else{
                    std::cout << darray[i][j];
                }
            }
            std::cout << std::endl;
        }
    }

    return 0;

    
}
