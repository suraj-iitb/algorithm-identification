#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define  all(x) (x).begin(),(x).end()
typedef long long ll;

void bublle_sort(vector<int> A){
    bool flag = true;
    int cnt = 0;
    while (flag){
        flag = false;
        for (int i = A.size()-1; i > 0; i--){
            if(A[i-1] > A[i]){
                swap(A[i-1], A[i]);
                flag = true;
                cnt++;
            }
        }
    }
    rep(i, A.size()){
        cout << A[i];
        if (i != A.size()-1) cout << " ";
    }
    cout << endl << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    bublle_sort(A);
}
