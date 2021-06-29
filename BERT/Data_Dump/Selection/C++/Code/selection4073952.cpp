#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, count=0;
    cin >> N;
    vector<int> list(N);
    for (int i=0; i<N; i++){
        cin >> list.at(i);
    }
    for (int i=0; i<N; i++){
        int minj = i;
        int j = 0;
        for (j=i; j<N; j++){
            if (list.at(j)<list.at(minj)){
                minj = j;
            }
        }
        if (list.at(minj) != list.at(i)){
            swap(list.at(minj), list.at(i));
            count++;
        }
    }
    for (int i=0; i<N; i++){
        cout << list.at(i);
        if (i!=N-1){
            cout << ' ';
        }
    }
    cout << endl;
    cout << count << endl;
}
