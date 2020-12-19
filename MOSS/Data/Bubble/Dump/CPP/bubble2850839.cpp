#include <iostream>
using namespace std;
int main(void){
    int i, j, flag, n, c, count, A[101];
    flag = 1;
    i = 0;
    count = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    while(flag){
        flag = 0;
        for(j = n - 1; j >= 1; j--){
            if(A[j - 1] > A[j]){
                c = A[j];
                A[j] = A[j-1];
                A[j-1] = c;
                count++;
                flag = 1;
            }
        }
        i++;
    }
              
    for(int i = 0; i < n; i++){
        if(i != n-1)cout << A[i]  << " ";
        else cout << A[i];
    }
    cout << endl << count << endl;
    
    
    return 0;
}
