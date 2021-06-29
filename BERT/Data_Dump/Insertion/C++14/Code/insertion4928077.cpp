#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int R[n];
    for(int i = 0; i < n; i++){
        cin >> R[i];
    }
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            cout << R[i] << endl;
        }else{
            cout << R[i] << " ";
        }
    }
    for(int i = 1; i < n; i++){
        int v = R[i];
        int j = i - 1;
        while(j >= 0 && R[j] > v){
            R[j + 1] = R[j];
            j--;
        }
        R[j + 1] = v;
        for(int j = 0; j < n; j++){
            if(j == n - 1){
                cout << R[j] << endl;
            }else{
                cout << R[j] << " ";
            }
        }
    }
    return 0;
}
