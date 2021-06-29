#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define inf 2000000000
int v,e;
int d[1000][1000];
int f(){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            if(d[i][k]!=inf){
                for(int j=0;j<v;j++){
                    if(d[k][j]!=inf){
                        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                        if(j==k&&d[j][k]<0){
                            cout<<"NEGATIVE CYCLE"<<endl;
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main(void){
    cin >> v>>e;
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j){
                d[i][j]=0;
            }else{
                d[i][j]=inf;
            }
        }
    }
    for(int i=0;i<e;i++){
        int s,t;
        cin>>s>>t;
        cin>>d[s][t];
    }
    if(f()){
        return 0;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(j==v-1){
                if(d[i][j]==inf){
                    cout<<"INF"<<endl;
                }else{
                    cout << d[i][j]<<endl;   
                }
            }else{
                if(d[i][j]==inf){
                    cout << "INF"<<" ";
                }else{
                    cout <<d[i][j]<<" ";
                }
            }
        }
    }
}

