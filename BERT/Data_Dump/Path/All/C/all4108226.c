#include<iostream>
#include<algorithm>
#define INF 9999999999999999999999

using namespace std;

long A[100][100], tmpA[100][100];
int V, E;

void import(int s, int t, int d){
    A[s][t] = d;
    return;
}

void set(){
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j){
            tmpA[i][j] = A[i][j];
        }
    }
    return;
}

void check(int a){
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            if(tmpA[i][a] == INF || tmpA[a][j] == INF){
             continue;   
            }
            if(tmpA[i][j] > (tmpA[i][a]+tmpA[a][j])){
                A[i][j] = tmpA[i][a]+tmpA[a][j];
            }
        }
    }
    return;
}

int main(){
    for(int i=0;i<100;++i){
        for(int j=0;j<100;++j){
            A[i][j] = INF;
            tmpA[i][j] = A[i][j];
        }
    }
    
    
    int s, t, d;
    
    cin >> V >> E;
    for(int i=0;i<V;++i){
        import(i,i,0);
    }
    for(int i=0;i<E;++i){
        cin >> s >> t >> d;
        import(s,t,d);
    }
    
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            check(j);
            set();
            if(A[j][j]<0){
                cout << "NEGATIVE CYCLE" << endl;
                return 0;
            }
        }
    }
    
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            if(j!=0){
                cout << " ";
            }
            
            if(A[i][j] == INF){
                cout << "INF";
            }else{
                cout << A[i][j];
            }
        }
        cout << endl;
    }
    
    return 0;
}
