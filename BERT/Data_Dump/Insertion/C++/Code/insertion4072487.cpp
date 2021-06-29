#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, v, j;
    cin >> N;
    vector<int> list(N);
    for (int i=0; i<N; i++){
        cin >> list.at(i);
        if (i==N-1){
            cout << list.at(i) << endl;
        }else{
            cout << list.at(i) << ' ';
        }
    }
    for (int i=1; i<N; i++){
        v = list[i];
        j = i - 1;
        while (j >= 0 && list[j] > v){
            list[j+1] = list[j];
            j--;
        }
        list[j+1] = v;
        for (int i=0; i<N; i++){
            if (i==N-1){
                cout << list.at(i) << endl;
            }else{
                cout << list.at(i) << ' ';
            }     
        }
    }
}
