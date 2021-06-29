#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int N,x=0;
    cin >> N;
    vector<int> b(N);
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    bool f =true;
    while(f==true){
        f = false;
        for(int i = N-1; i > 0; i--){
            if(b[i]<b[i-1]){
                swap(b[i],b[i-1]);
                x++;
                f=true;
            }
        }
    }
    for(int i = 0; i < N-1; i++){
        cout << b[i] <<" ";
    }
    cout <<b[N-1]<< endl;
    cout << x << endl;
}
