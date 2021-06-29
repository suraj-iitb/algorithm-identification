#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10000;
int main(){
    int n;
    cin >> n;
    vector<int> backet(MAX+1, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        backet[a]++;
    }

    vector<int> output(n);
    for(int i = 0, oind = 0; i <= MAX; i++){
        if(backet[i] > 0){
            while(backet[i]){
                output[oind++] = i;
                backet[i]--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << output[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
    return 0;
}
