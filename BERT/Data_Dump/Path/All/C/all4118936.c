#include <iostream>
using namespace std;
int V,E,s,t,d,A[100][100]={};
int INF=2000000000;
void WarshallFloyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(A[i][k] == INF)continue;
            for(int j=0;j<V;j++){
            if(A[k][j] == INF)continue;
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
}
int main(){

    cin>>V>>E;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                A[i][j]=0;
            }
            else{
                A[i][j]=INF;
            }
        }
    }
    for(int i=0;i<E;i++){
        for(int j=0;j<V;j++){
            cin>>s>>t>>d;
            A[s][t]=d;
            //A[t][s]=d;
        }
    }
    WarshallFloyd();
    for(int i=0;i<V;i++){
        if(A[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(j==V-1){
                if(A[i][j]==INF){
                   cout<<"INF";
                }
                else{
                    cout<<A[i][j];
                }
           }
           else{
               if(A[i][j]==INF){
                  cout<<"INF"<<" ";
                }
                else{
                   cout<<A[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

