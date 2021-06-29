#include <iostream>
#include <vector>
using namespace std;
int qq = 0;
void merge1(vector<int> &s, int l1, int r1, int l2, int r2){
    vector<int> temp;
    int i = l1;
    int j = l2;
    while (i <= r1 && j <= r2){
        qq++;
        if (s[i] < s[j]){
            temp.push_back(s[i++]);
        }
        else
            temp.push_back(s[j++]);
    }
    while (i <= r1){
        temp.push_back(s[i++]);
        qq++;
    }
    while (j <= r2){
        temp.push_back(s[j++]);
        qq++;
    }
    for (int i = 0; i < temp.size(); i++){
        s[l1++] = temp[i];
    }
    temp.clear();
}
void mergeSort(vector<int> &s, int index_start, int index_end){
    if (index_start < index_end){
        int mid = (index_start + index_end) / 2;
        mergeSort(s, index_start, mid);
        mergeSort(s, mid+1, index_end);
        merge1(s, index_start, mid, mid+1, index_end);
    }
}
int main()
{
    vector<int> s;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> temp;
        s.push_back(temp);
    }
    mergeSort(s, 0, n-1);
    for (int i = 0; i < s.size(); i++){
        if (i == 0)
            cout << s[i];
        else
            cout << " " << s[i] ;
    }
    cout << endl;
    cout << qq << endl;
    return 0;
}

