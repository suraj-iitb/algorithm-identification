#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> data(N);
    for( int i = 0; i < N; i++ ){
        cin >> data[i];
    }
    for( int i = 0; i < N; i++ ){
        int key = data[i];
        int j = i - 1;
        while( j >= 0 && data[j] > key ){
            data[j+1] = data[j];
            j--;
        }
        data[j+1] = key;
        for( int k = 0; k < N; k++ ){
            if( k != 0 ) cout << ' ';
            cout << data[k];
        }
        cout << endl;
    }

}
