#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
using namespace std;

int main(void){
    long long v,e,a[101][101],INF=1e12;
    cin>>v>>e;
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            a[i][j]=INF;
            if(i==j)a[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int s,t,d;
        cin>>s>>t>>d;
        a[s][t]=d;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(a[j][i]==INF||a[i][k]==INF)continue;
                if(a[j][k]>a[j][i]+a[i][k]){
                    a[j][k]=a[j][i]+a[i][k];
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                if(a[j][i]==INF||a[i][k]==INF)continue;                
                if(a[j][k]>a[j][i]+a[i][k]){
                    cout<<"NEGATIVE CYCLE"<<endl;
                    return 0;
                }
            }
        }
    }    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(a[i][j]==INF)cout<<"INF";
            else cout<<a[i][j];
            if(j<v-1)cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
