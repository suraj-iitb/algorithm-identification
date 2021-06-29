#include <iostream>

void swap(int& a,int& b);

using namespace std;

int main()
{
    int N,t[100];
    int num=0,m=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>t[i];
    }
    for(int i=0;i<N;i++){
        m=i;
        for(int j=i+1;j<N;j++){
            if(t[m]>t[j]){
                m=j;
            }
        }
        if(i!=m){
            swap(t[i],t[m]);
            num++;
        }
    }
    cout<<t[0];
    for(int i=1;i<N;i++){
        cout<<" "<<t[i];
    }
    cout<<endl;
    cout<<num<<endl;
}
void swap(int& a,int& b)
{
    int c;
    c=a;
    a=b;
    b=c;
}
