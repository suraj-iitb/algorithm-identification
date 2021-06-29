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
    Counter counter;
    int n;
    cin>>n;
    int* array=new int[n];
    for(int i=0;i<n;++i){
        cin>>array[i];
    }

    for(int i=0;i<n;++i){
        int min=i;
        for(int j=i;j<n;++j){
            if(array[j]<array[min]){
                min=j;
            }
        }
        if(i!=min){
            swap(array[i],array[min]);
            counter.up();
        }
    }
    for(int i=0;i<n;++i){
        cout<<array[i];
        if(i!=n-1){
            cout<<" ";
        }
    }
    cout<<"\n";
    cout<<counter.show()<<"\n";
}
