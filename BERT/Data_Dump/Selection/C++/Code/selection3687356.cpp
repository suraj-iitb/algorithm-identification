#include<iostream>
using namespace std;
int main(){
    int a,b,count=0;
    cin>>a;
    int select[a];
    for(int i=0;i<a;i++){
        cin>>b;
        select[i]=b;
    }
    for (int i=0;i<a-1;i++){
        int minj = i;
        for (int j= i ;j<a;j++){
            
            if (select[j] <select[minj]){
                minj = j;
            }
        }
        if(i!=minj){
            int n=select[i];
            int m=select[minj];
            select[i]=m;
            select[minj]=n;
            count++;
        }
        
            
        
    } 
    for(int p=0;p<a;p++){
        if(p<a-1){
            cout<<select[p]<<" ";
        }
        else if(p==a-1){
            cout<<select[p]<<endl;
        }
    }
    cout<<count<<endl;
    return 0;
}


