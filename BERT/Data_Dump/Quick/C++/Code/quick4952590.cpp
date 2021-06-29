#include <iostream>
using namespace std;

const int INF = 2e9;

struct card {
    char suit;
    int num;
};
int partition(card *a, int p, int r)
{
    int x = a[r].num;
    int i = p-1;

    for (int j = p; j < r; j++) {
        if (a[j].num <= x) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}
void quickSort(card *a, int p, int r)
{
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}

void merge(card *a, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    card L[n1],R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[mid + i];
    L[n1].num = INF; R[n2].num = INF;

    int i = 0; int j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].num <= R[j].num) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
    }

}


void mergeSort(card *a, int left, int right)
{
    if (left+1 < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}
int main()
{
    int n;
    cin >> n;
    card a[n],b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].suit;
        b[i].suit = a[i].suit;
        cin >> a[i].num;
        b[i].num = a[i].num;
    }

    quickSort(a, 0, n-1);
    mergeSort(b, 0, n);
    bool flag = true;

    for (int i = 0; i < n; i++) {
        if (a[i].suit != b[i].suit) {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << a[i].suit << ' ' << a[i].num << endl;
    }
    return 0;
}
