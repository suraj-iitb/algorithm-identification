#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int i, j, k, N, SORT[100]={}, v;
    cin >> N;
    for(i=0; i<N; i++){
        cin >> SORT[i];
        cout << SORT[i];
        if(i != N-1) cout << " ";
    }
    cout << endl;
    for(i=1; i<=N-1; i++){
        v = SORT[i];
        j = i - 1;
        while(j >= 0 && SORT[j] > v){
            SORT[j+1] = SORT[j];
            j--;
        }
        SORT[j+1] = v;
        for(k=0; k<N; k++){
            cout << SORT[k];
            if(k != N-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
    

