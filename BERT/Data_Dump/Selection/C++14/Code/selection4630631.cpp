#include <bits/stdc++.h>
using namespace std;
void selectionsort(vector<int> &A, int N, int &count){
    for (int i=0; i<N; i++){
        int minj = i;
        for (int j=i; j<N; j++){
            if (A.at(j) < A.at(minj)){
                minj = j;
            }
        }
        if (A.at(i) != A.at(minj)) count += 1;
        int t = A.at(i);
        A.at(i) = A.at(minj);
        A.at(minj) = t;
    }
}

int main(){
    int N, count = 0;
    cin >> N;
    vector<int> Ai(N);
    for (int j=0; j<N; j++){
        cin >> Ai.at(j);
    }
    selectionsort(Ai, N, count);
    for (int j=0; j<N; j++){
        if (j != N-1) cout << Ai.at(j) << " ";
        else cout << Ai.at(j) << endl;
    }
    cout << count << endl;
    return 0;
}
