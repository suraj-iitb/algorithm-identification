#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
void trace(int A[], int N){
    for (int i = 0; i < N - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
    
}

int main() {
    int n;
    int a;
    cin >> n;

    int array[100];
    REP(i, n){
        cin >> a;
        array[i] = a;
    }
    trace(array, n);
    for(int i = 1; i < (int)(n); i++){
        int v = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > v){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = v;
        trace(array, n);
    }

}
