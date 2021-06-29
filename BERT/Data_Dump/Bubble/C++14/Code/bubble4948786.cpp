#include<bits/stdc++.h>
using namespace std;

void bubble(int n,std::vector<int> &a, int &cnt){
    int flag = 1;
    int temp = 0;
    while(flag){
        flag = 0;
        for(int i = 1;i<n;i++){
            if(a[i]<a[i-1]){
                temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                cnt+=1;
                flag = 1;
            }
        }
    }
}

void output(int n,std::vector<int>a,int cnt){

    for(int s=0; s<n;s++){
        cout<<(s? " ":"")<<a[s];
    }
    cout<<endl;
    cout<<cnt<<endl;
}

int main(){
    int n = 0;
    int counts = 0;

    cin>>n;
    vector<int> a(n,0);
    for(int& j : a){
        std::cin>>j;
    }

    bubble(n,a,counts);
    output(n,a,counts);

    return 0;
}


