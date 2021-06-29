#include <bits/stdc++.h>
using namespace std; 
void bubblesort (vector<int> &A, int N, int &count){
    int flag = 1;
    while (flag){
        flag = 0;
        for (int j=N-1; j>0; j--){
            if (A.at(j) < A.at(j-1)){
                count += 1;
                int t = A.at(j);
                A.at(j) = A.at(j-1);
                A.at(j-1) = t;
                flag = 1;
            }
        }
    }
    return;
}

int main(){
    int N, count = 0;
    cin >> N;
    vector<int> Ai(N);
    for (int i=0; i<N; i++){
        cin >> Ai.at(i);
    }
    bubblesort(Ai, N, count);
    for (int i=0; i<N; i++){
        if (i != N-1) cout << Ai.at(i) << " ";
        else cout << Ai.at(i) << endl;
    }
    cout << count << endl;
    return 0;
}
