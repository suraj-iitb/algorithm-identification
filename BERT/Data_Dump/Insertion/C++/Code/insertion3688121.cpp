#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int sort[100]={};
    for (int i=0;i<N;i++){
        cin>>sort[i];
    }
    int v,j=0;
    for(int i=0;i<N;i++){
        v = sort[i];
        j = i - 1;
        while(j >= 0 && sort[j] > v){
           sort[j+1] = sort[j];
           j--;
           sort[j+1] = v;
        }
        for(int k=0;k<N-1;k++){
            cout<<sort[k]<<" ";
        }
        cout<<sort[N-1];
        cout<<endl;
    }
    
    return 0;
}

