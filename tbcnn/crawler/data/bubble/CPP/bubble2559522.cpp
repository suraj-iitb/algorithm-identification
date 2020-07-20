#include<iostream>
using namespace std;

class Counter{
    int cnt;
public:
    Counter():cnt(0){}
    int show(){return cnt;}
    void up(){++cnt;}
    void down(){--cnt;}
};

void swap(int& a,int& b){
    int t=a;
    a=b;
    b=t;
}

int main(){
    int n;
    cin>>n;
    Counter a;
    int* array=new int[n];
    for(int i=0;i<n;++i){
        cin>>array[i];
    }
    int flag=1;
    while(flag){
        flag=0;
        for(int i=n-1;i>=0;--i){
            if(array[i]<array[i-1]){
                swap(array[i],array[i-1]);
                flag=1;
                a.up();
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<array[i];
        if(i!=n-1){cout<<" ";}
    }
    cout<<"\n";
    cout<<a.show()<<"\n";
}
