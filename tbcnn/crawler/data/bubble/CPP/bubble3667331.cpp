#include<iostream>
using namespace std;
int main(){
    int flag,i,n,x,y,count;
    flag = 1;
    i = 0;
    count = 0;
    cin >> n;
    int A[100] = {};
    for(int j = 0; j < n; j++){
        cin >> A[j];
    }
    while (flag == 1){
        flag = 0;
        for(int j = n-1; j >= i + 1; j--){
            if(A[j] < A[j-1]){
                x = A[j];
                y = A[j-1];
                A[j-1] = x;
                A[j] = y;
                flag = 1;
                count ++;
            }
        }
        i ++;
    }
    for(int j = 0; j < n; j ++){
        if(j != 0){
            cout << " ";
        }
        cout << A[j];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
