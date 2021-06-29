#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;      cin >> N;
    vector<int> a(N);
    for(int i = 0 ; i < N ; ++i)
        cin >> a[i];
    for(int i = 0 ; i < N ; ++i){
        for(int j = i - 1; j >= 0 ; --j)
            if(a[j + 1] < a[j])     swap(a[j + 1], a[j]);
            else    break;
        for(int i = 0 ; i < N - 1; ++i)
            cout << a[i] << ' ';
        cout << a[N - 1] << endl;
    }
}
