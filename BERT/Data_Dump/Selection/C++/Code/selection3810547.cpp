#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int Arr[N] = {0};
    for (int i = 0; i < N; i++){
        cin >> Arr[i];
    }

    int Cnt = 0;
    int MinIndex = 0;
    for (int i = 0; i < N; i++){
        MinIndex = i;
        for (int j = i; j < N; j++){
            if (Arr[j] < Arr[MinIndex]){
                MinIndex = j;
            }
        }
        swap(Arr[i], Arr[MinIndex]);
        if (i != MinIndex) Cnt++;
    }

    for (int i = 0; i < N; i++){
        cout << Arr[i];
        if (i != N-1) cout << " ";
    }
    cout << endl;
    cout << Cnt << endl;

    return 0;
}

