#include <iostream>
using namespace std;

void show(int* list, int N){
    for (int i=0; i<N-1; i++)
        cout << list[i] << " ";
    cout << list[N-1] << endl;
}

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++) cin >> a[i];
    
    int count = 0;
    for(int k=N-1; k>=1; k--){
        for (int i=0; i<k; i++){
            if (a[i] > a[i+1]){
                swap(a[i], a[i+1]);
                count += 1;
            }
        }
    }
    show(a, N);
    cout << count << endl;
    return 0;
}
