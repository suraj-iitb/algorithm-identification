#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num[n];
    for(int i=0; i<n;i++) {
        cin>>num[i];
    }
    for(int i=0; i<n;i++) {
        for(int s=0; s<i; s++){
        if(num[i]<num[s]){
            swap(num[i],num[s]);
        }
        }
        for(int t=0; t<n-1;t++){
            cout<<num[t]<<" ";
        }
        cout<<num[n-1]<<endl;
    }
    return 0;
}
