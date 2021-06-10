#include<iostream>
using namespace std;
int V,E,R,S[500010],T[500010],D[500010];
int C[100010];
const int inf=10000*100000+100;
int main() {
    cin>>V>>E>>R;
    for(int i=0;i<E;++i){
        cin>>S[i]>>T[i]>>D[i];
    }
    for(int j=0;j<V;++j){
        if(j==R) C[R]=0;
        else C[j]=inf;
       
    }
    //cout<<C[0]<<C[1]<<endl;
    for(int t=0;t<V;++t){
        bool update=false;
        for(int i=0;i<E;++i){
            int s=S[i],t=T[i],d=D[i];
            if(C[s]<inf&&C[t]>C[s]+d){
                C[t]=C[s]+d;
                update=true;
            }
        }
        if(!update) break;
    }
    for(int j=0;j<V;++j){
        if(C[j]==1000000100){
            cout<<"INF"<<endl;
        }
       else{
        cout<<C[j]<<endl;
        }
    }
}
