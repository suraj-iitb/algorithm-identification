#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bubleSort(vector<int> &A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = N - 1; j > i; j--){
            if(A.at(j-1) > A.at(j)){
                //cout << A.at(j) << " " << A.at(j-1) << endl;
                swap(A.at(j), A.at(j-1));
                //cout << A.at(j) << " " << A.at(j-1) << endl;
                count++;
            }
        }


    }
    return count;
}




int main(){
    int N, count;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    count = bubleSort(A, N);

    for(int i = 0; i < N; i++){
        if(i!=0){
            cout << " ";
        }
        cout << A.at(i);
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
