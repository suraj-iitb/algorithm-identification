#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int selectionSort(vector<int> &A, int N){
    int count = 0;
    for(int i = 0; i < N; i++){
        int tmp_min = A.at(i);
        int tmp_j = i;
        for(int j = i + 1; j < N; j++){
            if(tmp_min > A.at(j)){
                tmp_min = A.at(j);
                tmp_j = j;
            }
            //cout << tmp_min << endl;
            }
        if(i != tmp_j){
            count++;
        }
        swap(A.at(i), A.at(tmp_j));
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
    count = selectionSort(A, N);

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
