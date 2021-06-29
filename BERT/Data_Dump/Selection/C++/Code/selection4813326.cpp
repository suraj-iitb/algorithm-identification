#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt = 0;

void selection_sort(vector<int>& A, int n){
    cnt = 0;
        for(int i = 0; i < n; ++i){
        int mini = i;
        for(int j = i + 1; j < n; ++j){
            if(A[j] < A[mini])
                mini = j;
        }
        if(i != mini){
            swap(A[i], A[mini]);
            ++cnt;
        }            
    }
}

void print_pass(vector<int>& A, int n){
    for(int i = 0; i < n; ++i){
        if(i > 0) 
            cout << " " ;
        cout << A[i];
        }
        cout << endl;
    }

int main()
{
    int n;
    cin >> n;
    vector<int> ivec;
    for(int i = 0; i < n; ++i){
        int tmp;
        cin >> tmp;
        ivec.push_back(tmp);
    }
    selection_sort(ivec, n);
    print_pass(ivec, n);
    cout << cnt << endl;
    return 0;
}
 
