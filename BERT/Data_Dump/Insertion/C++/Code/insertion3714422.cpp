#include <iostream>
#include <vector>
using namespace std;
int main() {
    std::vector <int> A;
    int N,k=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> k;
        A.push_back(k);
    }
    for(int j=0;j<N;j++) cout << A[j] << ((j<N-1) ? ' ' : '\n');
    for(int i=1;i<N;i++){
        k = A[i];
        int j=i-1;
        for(;j >= 0&& A[j]>k;){
            A.erase(A.begin()+j+1);
            A.insert(A.begin() + j+1, A[j]);
            j--;
        }
        A.erase(A.begin() + j+1);
        A.insert(A.begin() + j+1, k);
        for(int j = 0; j<N;j++){
            cout << A[j] << ((j==N-1)?'\n' : ' ');
        }
    }
   return 0;
}

