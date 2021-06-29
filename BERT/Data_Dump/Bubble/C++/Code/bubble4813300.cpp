#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt = 0;

void bubble_sort(vector<int>& A, int n){
    cnt = 0;
        for(int i = 0; i < n; ++i){
            bool flag = false;
            for(int j = 0; j < n - 1 - i; ++j){
                if(A[j] > A[j + 1]){
                    swap(A[j], A[j + 1]);
                    flag = true;
                    ++cnt;
                }
            }
            if(!flag)   
                break;
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
    bubble_sort(ivec, n);
    print_pass(ivec, n);
    cout << cnt << endl;
    return 0;
}
 
