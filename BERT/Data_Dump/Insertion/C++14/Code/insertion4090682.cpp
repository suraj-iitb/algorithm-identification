#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

void print_vec(vector<int> & v){
for (vector<int>::iterator vec_itr = begin(v); vec_itr!=end(v)-1; ++vec_itr ){
                cout << *vec_itr << " ";
            }
            cout << *(end(v)-1)<< "\n";
}

vector<int> & insertion_sort(vector<int> & vec, int const & n){
    int key;
    REP(i, n){
        key = vec[i];
        int j = i;
        while( j > 0 && vec[j-1] > key ){
            swap(vec[j-1], vec[j]);
            j--;
        }
        // print
        print_vec(vec);
    }
    return vec;
}

int main () {
    // input
    int n;
    cin >> n;
    vector<int> input(n, 0);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &input[i]);
    }

    insertion_sort(input, n);
}
