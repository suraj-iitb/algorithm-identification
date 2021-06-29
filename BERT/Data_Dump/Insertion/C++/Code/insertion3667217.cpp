#include<iostream>
using namespace std;
int main(){
    int a,b;
    
    cin>>a;
    int insert[a];
    for(int i=0;i<a;i++){
        cin>>b;
        insert[i]=b;
    }
    
   
    for(int i=0;i<a;i++){
        int v = insert[i];
        int j = i - 1;
        while (j >= 0&& insert[j] > v){
            insert[j+1] = insert[j];
            j--;
            insert[j+1] = v;
            
        }
        for(int p=0;p<a;p++){
            if(p<a-1){
                cout<<insert[p]<<" ";
            }
            else if(p==a-1){
                cout<<insert[p]<<endl;
            }
        }
    }
    return 0;
}
