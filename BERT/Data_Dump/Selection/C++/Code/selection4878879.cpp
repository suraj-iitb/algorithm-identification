#include <iostream>
#include <algorithm>
#include <utility> 
using namespace std;
int main(void){
    int min,tmp,cou=0;
    int a,b[100]={};
    cin>>a;
    for(int z=0;z<a;z++){
        cin>>b[z];
    }
    if(a!=1){
        for(int z=0;z<a;z++){
            min=b[z];
            tmp=z;
            for(int f=z+1;f<a;f++){
               if(min > b[f]){
                    tmp = f;
                    min = b[f];
                }
            }
            if(b[z]>b[tmp]){
                swap(b[z],b[tmp]);
                cou++;
            }
        }
        for(int z=0; z < a;z++){
            if(z != 0) cout << " ";
            cout<<b[z];
        }cout<<endl<<cou<<endl;
    }else{
        cout<<b[0]<<endl<<0<<endl;
    }
}

