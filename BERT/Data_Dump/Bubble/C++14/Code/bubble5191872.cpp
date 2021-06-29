#include<iostream>
#include<utility>
using namespace std;

int main(){
    int N, a[100], t = 0;
    cin >> N;
    for(int i = 0 ; i < N ; i++) cin >> a[i];
    for(int i = 0 ; i < N ; i++){
        for(int j = N - 1 ; j > i ; j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
                t++;
            }
        }
    }
    for(int i = 0 ; i < N - 1 ; i++) cout << a[i] << " ";
    cout << a[N-1] << endl;
    cout << t << endl;
    return 0;
}
