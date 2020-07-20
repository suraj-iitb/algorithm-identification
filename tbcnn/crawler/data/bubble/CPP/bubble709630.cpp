#include <iostream>

void swap(int& a,int& b);

using namespace std;

int main()
{
    int N,t[100];
    int num=0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>t[i];
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<N-i;j++){
            if(t[j-1]>t[j]){
                swap(t[j-1],t[j]);
                num++;
            }
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
