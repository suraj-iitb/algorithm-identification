#include<iostream>
#include <vector>
using namespace std;

int selection_sort(vector<int>& a){
    int count_swap{0};

    for (int i = 0; i < a.size(); i++){
        int minj{i};
        for (int j = i; j < a.size(); j++){
            if (a[minj] > a[j]){
                minj = j;
            };
        }
        if (minj != i){
            swap(a[minj], a[i]);
            count_swap += 1;
        };
    };
    return count_swap;
}

int main(){

    int N{0};
    cin >> N;
    //#unique_ptr<array<int, N>> a;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int count_swap{0};
    count_swap = selection_sort(a);
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl << count_swap << endl;
    return 0;
}

