#include <iostream>

using namespace std;

int main()
{
    int N,num[100];
    int ddata;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num[i];
    }
    int j;
    cout<<num[0];
    for(j=1;j<N;j++){
        cout<<" "<<num[j];
    }
    cout<<endl;
    for(int i=1;i<N;i++){
        ddata=num[i];
        j=i-1;
        while(j>=0&&num[j]>ddata){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=ddata;
        cout<<num[0];
        for(j=1;j<N;j++){
            cout<<" "<<num[j];
        }
        cout<<endl;
    }
    
}
