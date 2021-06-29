#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int array[N];
    for(int i = 0; i < N; i++) cin >> array[i];

    for(int i = 0; i < N; i++){
        int val = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > val){
            array[j+1] = array[j];
            j--;
            array[j+1] = val;
        }
        for(int i = 0; i < N; i++){
            if(i != N-1)cout << array[i] << " ";
            else cout << array[i] << endl;
        }
    }

    return 0;
}
