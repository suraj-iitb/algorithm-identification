#include <iostream>
using namespace std;

void insert_sort(int* a, int* b){
    int l = b - a,y;
    for(y = 0; y < l-1; y++){
        cout << *(a+y) << ' ';
    }
    cout << *(a+l-1) << '\n';
    for(int x = 1; x < l; x++){
        y = x;
        int i = *(a+x);
        while( y > 0 && *(a+y-1) > i ){
            *(a+y) = *(a+y-1);
            y--;
        }
        *(a+y) = i;
        for(y = 0; y < l-1; y++){
            cout << *(a+y) << ' ';
        }
        cout << *(a+l-1) << '\n';
    }
}

int main(){
    int arr[100], N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    insert_sort(arr, arr+N);
    return 0;
}
