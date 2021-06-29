#include<iostream>
#include<vector>
#define INF 1e12

void Warshall_Floyd(std::vector<std::vector<long> > &d, int V){
    for(int k=0; k<V; ++k){
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j){
                if(d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main(){
    int V,E; std::cin >> V >> E;
    std::vector<std::vector<long> > d(V, std::vector<long>(V,INF));
    for(int i=0; i<V; ++i) d[i][i] = 0;
    for(int i=0; i<E; ++i){
        int s,t;
        std::cin >> s >> t;
        std::cin >> d[s][t];
    }
    Warshall_Floyd(d, V);
    bool negative_loop_exist = false;
    for(int i=0; i<V; ++i){
        if(d[i][i] < 0){
            negative_loop_exist = true;
            break;
        }
    }
    if(negative_loop_exist){
        std::cout << "NEGATIVE CYCLE" << std::endl;
    }else{
        for(int i=0; i<V; ++i){
            for(int j=0; j<V; ++j){
                if(d[i][j] == INF)
                    std::cout << "INF";
                else
                    std::cout << d[i][j];
                if(j != V-1)
                    std::cout << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}
