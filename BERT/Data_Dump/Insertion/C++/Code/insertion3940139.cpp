#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int N,a;
    cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
        if(i==N-1){
            cout << v[i] << endl;
        }
        else{
            cout << v[i] <<" " ;
        }
    }
    
    for(int i = 1; i <N; i++){
        a = v[i];
        int j=i-1;
        while(j>=0 && v[j]>a){
            v[j+1]=v[j];
            j--;
            v[j+1]=a;
        }
        for(int k = 0; k <N; k++){
            if(k==N-1){
                cout << v[k] << endl;
            }
            else{
                cout << v[k] << " " ;
            }
        }
    }
}
