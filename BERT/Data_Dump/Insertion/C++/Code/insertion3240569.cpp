#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define BUG (cout << "Sehen Sie mich!" << endl)

#define N 100
int main()
{
        int n;
        int arr[N];
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) {
                cout << arr[i];
                if (i != n -1)
                        cout << " ";
        }
        cout << endl;
        for (int i = 1; i < n; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = key;
                for (int i = 0; i < n; i++) {
                        cout << arr[i];
                        if (i != n -1)
                                cout << " ";
                }
                cout << endl;
        }
        return 0;
}

