#include <iostream>
#include<algorithm>

using namespace std;
static const int MAX = 1000;

int main() {
    int num[MAX],n,p;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        cout<<num[i];
    }
    cout<<endl;


    for(int i=1;i<n;i++){
        p=num[i];
        int j=i-1;
        while (j>=0&&num[j]>p){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=p;

        for(int k=0;k<n;k++){
            if(k!=0) cout<<" ";
            cout<<num[k];
        }
        cout<<endl;
    }
    return 0;
}

