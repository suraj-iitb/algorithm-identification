#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Card
{
public:
    char simbol;
    int num;

    Card() : simbol('\0'), num(0) {}
    Card(char s, int n) : simbol(s), num(n) {}
};

void merge(vector<Card>& v, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    vector<Card> v1(size1);
    vector<Card> v2(size2);

    for (int i = 0; i < size1; ++i) {
        v1[i].simbol = v[left+i].simbol;
        v1[i].num = v[left+i].num;
    }
    for (int i = 0; i < size2; ++i) {
        v2[i].simbol = v[mid+1+i].simbol;
        v2[i].num = v[mid+1+i].num;
    }

    int idx = left;
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < size1 && idx2 < size2) {
        if (v1[idx1].num <= v2[idx2].num) {
            v[idx].simbol = v1[idx1].simbol;
            v[idx].num = v1[idx1].num;
            ++idx1;
        } else {
            v[idx].simbol = v2[idx2].simbol;
            v[idx].num = v2[idx2].num;
            ++idx2;
        }
        ++idx;
    }

    while (idx1 < size1) {
        v[idx].simbol = v1[idx1].simbol;
        v[idx].num = v1[idx1].num;
        ++idx1;
        ++idx;
    }
    while (idx2 < size2) {
        v[idx].simbol = v2[idx2].simbol;
        v[idx].num = v2[idx2].num;
        ++idx2;
        ++idx;
    }
}

void merge_sort(vector<Card>& v, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

int partition(vector<Card>& v, int left, int right)
{
    int pivot = v[right].num;
    int boundary = left - 1;

    for (int i = left; i < right; ++i) {
        if (v[i].num <= pivot) {
            ++boundary;
            swap(v[boundary], v[i]);
        }
    }
    ++boundary;
    swap(v[boundary], v[right]);

    return boundary;
}

void quick_sort(vector<Card>& v, int left, int right)
{
    if (left < right) {
        int pivot = partition(v, left, right);
        quick_sort(v, left, pivot - 1);
        quick_sort(v, pivot + 1, right);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Card> cards(n);
    for (int i = 0; i < n; ++i)
        cin >> cards[i].simbol >> cards[i].num;

    vector<Card> stable_cards(n);
    copy(cards.begin(), cards.end(), stable_cards.begin());

    quick_sort(cards, 0, n - 1);
    merge_sort(stable_cards, 0, n - 1);

    bool stable = true;
    for (int i = 0; i < n; ++i) {
        if (cards[i].simbol != stable_cards[i].simbol || cards[i].num != stable_cards[i].num) {
            stable = false;
            break;
        }
    }

    if (stable)
        cout << "Stable\n";
    else
        cout << "Not stable\n";

    cout << cards[0].simbol << ' ' << cards[0].num << '\n';
    for (int i = 1; i < n; ++i)
        cout << cards[i].simbol << ' ' << cards[i].num << '\n';
}

