

#include<iostream>
#include<memory>
#include <vector>
#include <string>
#include<sstream>

using namespace std;

void trace(vector<int> &vec){
    int i;
    for (i = 0; i < vec.size(); i++){
        if (i > 0 ) cout << " ";
        cout << vec[i];
    }
    cout << '\n';
}

void InsertionSort(vector<int> &vec)
{
    int j, i, v;
    for (i = 1; i < vec.size(); i++){
        v = vec[i];
        j = i-1;
        while( j >= 0 && vec[j] > v){
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = v;
        trace(vec);
    }
}
 
int main(){
    int N, i, j;
    cin >> N;
    vector<int> vec(N);
    int val;
    for(i = 0; i < N; i++){
        cin >> val;
        vec[i] = val;
    }

    trace(vec);
    InsertionSort(vec);
}
