#include <iostream>
#include <vector>
using namespace std;
void output(vector<int> A)
{
    for(int i = 0; i < A.size(); ++i){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}
vector<int> insertionSort(vector<int> A)
{
    for(int i = 1; i < A.size(); ++i){
        output(A);
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
    output(A);
    return A;
}
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    insertionSort(A);
    return 0;
}
