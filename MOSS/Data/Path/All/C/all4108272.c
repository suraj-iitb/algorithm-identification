#include <iostream>
using namespace std;
long long int A[100][100];
long long int maxi=10000000001;
int w,V,E,v,e,i,j,flag=1;
void floid(){
    for(int k=0;k<100;k++){
        for(i=0;i<100;i++){
            if(A[i][k]==maxi) continue;
            for(j=0;j<100;j++){
            if(A[k][j]==maxi) continue;
            A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
}
int main(){
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            if(i==j) A[i][j]=0;
            else A[i][j]=maxi;
        }
    }
    cin>>V>>E;
    for(i=0;i<E;i++){
        cin>>v>>e>>w;
        A[v][e]=w;
    }
    floid();
    for(i=0;i<V;i++){
        if(A[i][i]<0) flag=0;
    }
    if(flag){
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(j) cout<<" ";
            if(A[i][j]==maxi) cout<<"INF";
            else cout<<A[i][j];
        }
        cout<<endl;
    }
    }
    else cout<<"NEGATIVE CYCLE"<<endl;
}
