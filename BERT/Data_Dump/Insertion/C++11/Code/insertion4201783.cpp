// InsertionSort.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
using namespace std;

int insertionSort(
    vector<int> &list
) {
    for (int i = 0; i < list.size(); ++i) {
        auto tmp = list[i];
        for (int j = i - 1; j >= 0; --j) {
            if (tmp < list[j]) {
                list[j + 1] = list[j];
                list[j] = tmp;
            }
        }
        for (int j = 0; j < list.size(); ++j) {
            cout << list[j];
            if (j != (list.size() - 1)) {
                cout << " ";
            }
            else{
                cout << endl;
            }
        }
    }
    return 0;
}

int main()
{
    int num, a;
    cin >> num;
    vector<int> list;
    for (int i = 0; i < num; ++i) {
        cin >> a;
        list.push_back(a);
    }
    insertionSort(list);
    return 0;
}

