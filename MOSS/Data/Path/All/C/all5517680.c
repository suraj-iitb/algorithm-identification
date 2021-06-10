#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const long long INF = 1LL << 32;

vector<vector<long long> > pass_weight;

bool warshallFloyd(vector< vector< long long> > &pass_weight);

void printmap(vector< vector<long long> > map);

int main(){

    int v, e, s, t;
    long long d;

    scanf("%d %d", &v, &e);

    // initialize
    pass_weight.assign(v, vector<long long>(v, INF));

    // 自身の頂点へのコストは0
    for(int i = 0; i < v; i++)  pass_weight[i][i] = 0;

    // 入力を読み込む
    for(int i = 0; i < e; i++){

        scanf("%d %d %lld", &s, &t, &d);
        pass_weight[s][t] = d;
    }


    bool is_only_positive_cycle = warshallFloyd(pass_weight);


    if(is_only_positive_cycle){

        printmap(pass_weight);
    }else{

        cout << "NEGATIVE CYCLE" << endl;
    }



    return 0;
}

bool warshallFloyd(vector< vector< long long> > &pass_weight){

    int v = pass_weight.size();

    for(int k = 0; k < v; k++){

        for(int i = 0; i < v; i++){

            if(pass_weight[i][k] == INF)    continue;

            for(int j = 0; j < v; j++){

                if(pass_weight[k][j] == INF)    continue;

                pass_weight[i][j] = min(pass_weight[i][j], pass_weight[i][k] + pass_weight[k][j]);
            }
        }
    }

    for(int i = 0; i < v; i++){

        if(pass_weight[i][i] < 0)   return false;
    }
    return true;
}

void printmap(vector< vector<long long> > map){

    int n_rows = map.size();
    int n_columns = map[0].size();

    for(int i = 0; i < n_rows; i++){

        for(int j = 0; j < n_columns; j++){

            if(j)   printf(" ");
            if(map[i][j] == INF)    printf("INF");
            else    printf("%d", map[i][j]);
        }

        printf("\n");
    }
}
