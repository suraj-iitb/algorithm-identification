#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int a,b[100],B[100],c,d=0;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b[i];
        B[i]=b[i];
    }
    sort(B,B+a);
    for(int i=0;i<a;i++){
        for(int j=i;j<a;j++){
            if(b[j]==B[i]){
                if(i==j){
                    break;
                }else{
                c=b[j];
                b[j]=b[i];
                b[i]=c;
                d++;

                break;
            }
            }
        }
    }
    for(int i=0;i<a-1;i++){
        cout<<b[i]<<" ";
    }
    cout<<b[a-1]<<"\n"<<d<<endl;
    return 0;
}
