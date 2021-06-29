#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int sort[100]={};
    int count=0;
    
    for(int i=0;i<N;i++){
        cin>>sort[i];
    }

    int x=0,y=0;

    for(int i=0;i<N;i++){
        x=i;
        for(int j=i;j<N;j++){
            if(sort[j]<sort[x]){
                x=j;
            }
        }
        if(i!=x){
                y=sort[i];
                sort[i]=sort[x];
                sort[x]=y;
                count++;
        }
        
            
        
        
    }
    
  
    for(int k=0;k<N-1;k++){
            cout<<sort[k]<<" ";
        }
    cout<<sort[N-1]<<endl;
    cout<<count<<endl;
        
    
    
    return 0;
}

    


