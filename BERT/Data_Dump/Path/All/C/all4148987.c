#include<iostream>
#define MAX 100
#define MINVAL (1LL<<32)
using namespace std;
typedef long long llong;

int V,E;
llong M[MAX+1][MAX+1];

void deal(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(M[i][k]==MINVAL) continue;
            for(int j=0;j<V;j++){
                if(M[k][j]==MINVAL) continue;
                M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
            }
        }
    }
}

int main(){
    cin>>V>>E;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            M[i][j]= i==j?0:MINVAL;
        }
    }
    for(int i=0;i<E;i++){
        int s,t,d;
        cin>>s>>t>>d;
        M[s][t]=d;
    }

    deal();

    bool flag=false;
    for(int i=0;i<V;i++){
        if(M[i][i]<0){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"NEGATIVE CYCLE"<<endl;
    }else{
        for (int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(j) cout<<" ";
                if(M[i][j]==MINVAL) cout<<"INF";
                else cout<<M[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

