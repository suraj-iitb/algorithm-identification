#include <iostream>
using namespace std;
int main(void){
    int n, i, j, minj, c, A[101], count = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> A[i];
    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j <= n-1; j++){
            if(A[j] < A[minj])
                minj = j;
        }
        if(minj != i){
        c = A[i];
        A[i] = A[minj];
        A[minj] = c;
        count++;
        }
    }
    for(i = 0; i < n; i++){
        if(i != n-1) cout << A[i] << ' ';
        else cout << A[i] << endl;
    }
        cout << count << endl;
    return 0;
}
