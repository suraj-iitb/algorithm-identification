#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, int> bubbleSort(vector<int> a) {
    bool isSorted = false;
    int c = 0;

    while (!isSorted) {
        isSorted = true;
        for (int i = a.size() - 1; i >= 1; i--) {
            if (a[i] < a[i - 1] ) {
                swap(a[i], a[i - 1]);
                isSorted = false;
                c++;
            }
        }
    }

    return pair<vector<int>, int>(a, c);
}

int main() {
   int n;
   cin >> n;
   vector<int> a = vector<int>(n);
   for (int i = 0; i < n; i++) {
       cin >> a[i];
   }
   pair<vector<int>, int> sorted_count = bubbleSort(a);
   for(int i = 0; i < a.size(); i++) {
       if (i != 0) {
           cout << " ";
       }
       cout << sorted_count.first[i];
   }
   cout << endl << sorted_count.second << endl;

   return 0;
}
