#include <iostream>
#include <vector>
#define rep(i, k, n) for(int i=k; i<n; i++)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A;
    int tmp;
    rep(i, 0, n) {
        cin >> tmp;
        A.push_back(tmp);
    }
    vector<int> SelectionSort(vector<int> vec);
    vector<int> answer = SelectionSort(A);
    rep(i, 1, n) cout << answer.at(i) << " ";
    cout << answer.at(n) << endl;
    cout << answer.at(0) << endl;
}

vector<int> SelectionSort(vector<int> vec) {
    int swap_count = 0;
    int size = vec.size();
    rep(i, 0, size) {
        int tmp = i;
        rep(j, i, size) { // Get number of the minimum value
            if (vec.at(tmp) > vec.at(j)) {
                tmp = j;
            }
        }
        if (tmp != i){
            swap(vec.at(tmp), vec.at(i));
            swap_count++;
        }
    }
    vector<int> answer;
    answer.push_back(swap_count);
    rep(i, 0, size) answer.push_back(vec.at(i));
    return answer;
}
