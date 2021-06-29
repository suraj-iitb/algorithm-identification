#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

static const long long INFTY=(1LL<<32);
long long A[100][100];
int E,V;
void count(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(A[i][k]==INFTY) continue;
            for(int j=0;j<V;j++){
                if(A[k][j]==INFTY) continue;
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
}

int main(){
    int s,t,d;
    cin>>V>>E;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j) A[i][j]=0;
            else A[i][j]=INFTY;
        }
    }
    for(int i=0;i<E;i++){
        cin>>s>>t>>d;
        A[s][t]=d;
    }
    count();
    bool ngt=false;
    for(int i=0;i<V;i++){
        if(A[i][i]<0){
            ngt=true;
            break;
        }
    }

    if(ngt) cout<<"NEGATIVE CYCLE"<<endl;
    else{
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(j) cout<<" ";
                if(A[i][j]==INFTY) cout<<"INF";
                else cout<<A[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
