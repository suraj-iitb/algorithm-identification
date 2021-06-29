#include <iostream>
using namespace std;

int main(){
    int tmp,j,N;
    cin >> N;
    int array[N];
    for(int i = 0; i < N; ++i){
        cin >> array[i];
    }
    for(int i = 0; i < N; ++i){
        cout << array[i];
        if(i != N - 1) cout << " " ;
    }
    cout << endl;
    for(int i = 1; i < N; ++i){
        tmp = array[i];
        j = i - 1;
        while(j >=0 && array[j] > tmp){
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = tmp;
        for(int k = 0; k < N; ++k){
            cout << array[k];
            if(k != N - 1) cout << " ";
        }
        cout << endl;
    }
}
