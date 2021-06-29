#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int a,b[100]={},c,d,e,f=0;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b[i];
    }
    for(int i=0;i<a;i++){
        c=i;
        d=i-1;
        for(int j=i;j>0;j--){
            if(c==0){
                break;
            }else if(b[c]<b[d]){
                    e=b[c];
                    b[c]=b[d];
                    b[d]=e;
                    f++;
                    c--;
                    d--;
            }
        }
    }
    for(int i=0;i<a-1;i++){
        cout <<b[i]<<" ";
    }
    cout <<b[a-1]<<"\n"<<f<<endl;
    return 0;
}
