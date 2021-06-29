#include <iostream>
#include <vector>
using namespace std;
struct card{
    char suit;
    int value;
};
int part (vector<card> &a, int p, int r){
    int xi = p;
    for (int i = p; i < r; i++){
        if (a[i].value <= a[r].value){
            swap(a[i], a[xi]);
            xi++;
        }
    }
    swap(a[xi], a[r]);
    return xi;
}
void quickSort (vector<card> &a, int p, int r){
    int q;
    if (p < r){
        q = part(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}
void merge1(vector<card> &s, int l1, int r1, int l2, int r2){
    int i = l1, j = l2;
    vector<card> temp;
    while (i <= r1 && j <= r2){
        if (s[i].value <= s[j].value){
            temp.push_back(s[i++]);
        }
        else
            temp.push_back(s[j++]);
    }
    while (i <= r1)
        temp.push_back(s[i++]);
    while (j <= r2)
        temp.push_back(s[j++]);
    for (int i = 0; i < temp.size(); i++){
        s[l1++] = temp[i];
    }
    temp.clear();
}
void mergeSort(vector<card> &s, int index_start, int index_end){
    if (index_start < index_end){
        int mid = (index_start + index_end) / 2;
        mergeSort(s, index_start, mid);
        mergeSort(s, mid+1, index_end);
        merge1(s, index_start, mid, mid+1, index_end);
    }
}
int main()
{
    vector<card> a,b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        card temp;
        cin >> temp.suit;
        cin >> temp.value;
        a.push_back(temp);
    }
    b = a;
    quickSort(a, 0, n-1);
    mergeSort(b, 0, n-1);
    int stable = 1;
    for (int i = 0; i < a.size(); i++){
        if (a[i].suit != b[i].suit){
            stable = 0;
            break;
        }
    }
    if (stable == 0)
        cout << "Not stable" << endl;
    else
        cout << "Stable" << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i].suit << " " << a[i].value << endl;
    }
    return 0;
}

