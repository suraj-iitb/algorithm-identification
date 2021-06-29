 #include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int sort[100]={};
    int count=0,flag=0;
    
    for(int i=0;i<N;i++){
        cin>>sort[i];
    }

    int x=0;
    for(int i=N-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(sort[j+1]<sort[j]){
                x=sort[j+1];
                sort[j+1]=sort[j];
                sort[j]=x;
                count++;
            }
            flag=1;
        }
    }
  
    for(int k=0;k<N-1;k++){
            cout<<sort[k]<<" ";
        }
    cout<<sort[N-1]<<endl;
    cout<<count<<endl;
        
    
    
    return 0;
}
