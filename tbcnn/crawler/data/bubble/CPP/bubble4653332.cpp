#include<bits/stdc++.h>
using namespace std;

int main(){
    int d[100],n,num=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(d[j]<d[j-1]){
                swap(d[j],d[j-1]);
                num++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<(i==0?"":" ")<<d[i];
    }
    cout<<endl<<num<<endl;
    
}
