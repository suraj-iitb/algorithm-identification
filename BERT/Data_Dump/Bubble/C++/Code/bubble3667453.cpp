#include<iostream>
using namespace std;
int main(){
    int a,b,count=0;
    
    cin>>a;
    int bubble[a];
    for(int i=0;i<a;i++){
        cin>>b;
        bubble[i]=b;
    }
    
   
    for(int i=0;i<a;i++){
        int flag = 1 ;// 逆の隣接要素が存在する
        while (flag){
            flag = 0;
            for (int j= a-1;j>0;j--) {
                if (bubble[j] < bubble[j-1]){
                    int c=bubble[j];
                    int d=bubble[j-1];
                    bubble[j]= d;
                    bubble[j-1]=c;
                    flag = 1;
                    count++;
                }
                
            }
            
        }
        

    }
    for(int p=0;p<a;p++){
        if(p<a-1){
            cout<<bubble[p]<<" ";
        }
        else if(p==a-1){
            cout<<bubble[p]<<endl;
        }
    }
    cout<<count<<endl;
    return 0;
}

