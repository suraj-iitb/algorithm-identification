#include <iostream>
#include <string>
using namespace std;
int main(void){
    int a,b,j,v=0,f = 1;
    cin>>a;
    int A[a];
    for(int i=0;i<a;i++){
        cin>>A[i];
    }
    while(f){
        f=0;
        for(int j=a-1;j>0;j--){
            if(A[j]<A[j-1]){
              b=A[j];
              A[j]=A[j-1];
              A[j-1]=b;
              f=1;
              v++;
            }
        }
    }

    for(int i=0;i<a;i++){
        if(i==a-1){
            cout<<A[i]<<endl;
            cout<<v<<endl;
        }else{
            cout<<A[i]<<" ";
        }
    }

    /*for(int i=0;i<a;i++){
        if(i==a-1){
            cout<<A[i]<<endl;
        }else{
        cout<<A[i]<<" ";
        }
    }*/
    return 0;
}

