#include<iostream>
using namespace std;

int v,e,r,s[500010],t[500010],d[500010],c[100010];
const int inf=1000000000;

int main(){
    cin>>v>>e>>r;
    for(int i=0;i<e;i++){
        cin>>s[i]>>t[i]>>d[i];
    }
    for(int i=0;i<100010;i++){c[i]=inf;}
    c[r]=0;
    for(int i=0;i<v;i++){
        int a=0;
        for(int j=0;j<e;j++){
            int s1=s[j],t1=t[j],d1=d[j];
            if(c[s1]<inf && c[t1]>c[s1]+d1){
                c[t1]=c[s1]+d1;
                a=1;
            }
        }
        if(!a){break;}
    }
    for(int i=0;i<v;i++){
        if(c[i]==inf){cout<<"INF"<<endl;}
        else{cout<<c[i]<<endl;}
    }
}
