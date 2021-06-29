#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i != a.size() - 1) cout << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> vi) {
    int count = 0;
    for (int j = 0; j < vi.size(); j++) {
        int mini,min = 101;

        for (int i = j; i < vi.size(); i++) {
            if(min > vi[i]){
                mini = i;
                min = vi[i];
            }
        }

        if(j != mini) {
            vi[mini] = vi[j];
            vi[j] = min;
            count++;
        }
    }
    print(vi);
    cout << count << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    selectionSort(a);
    return 0;
}
