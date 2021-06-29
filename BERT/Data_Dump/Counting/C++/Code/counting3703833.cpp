#include <iostream>
#define ARRAY_SIZE 10000

using namespace std;

int main(){
    int n, num, ma = 0, mi = ARRAY_SIZE + 1, A[ARRAY_SIZE] = {};
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        A[num]++;
        ma = max(ma, num);
        mi = min(mi, num);
    }

    for(int i = mi; i <= ma; i++){
        for(int j = 0; j < A[i]; j++){
            if(i > mi || j > 0){ cout << " "; }
            cout << i;
        }
    }
    cout << endl;
    return 0;
}
