#include <iostream>
#include <vector>

using namespace std;

struct Card {
  char suit;
  long num;

  bool operator==(const Card& c) const {
    return (suit == c.suit) && (num == c.num);
  }

  bool operator!=(const Card& c) const {
    return !((suit == c.suit) && (num == c.num));
  }

  bool operator<=(const Card& c) const {
    return num <= c.num;
  }
};

void merge(vector<Card> &v, vector<Card> &vl, vector<Card> &vr) {
  int n = (int)v.size();
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < n; ++i) {
    if (j >= (int)vl.size()) v[i] = vr[k++];
    else if (k >= (int)vr.size()) v[i] = vl[j++];
    else if (vl[j] <= vr[k]) v[i] = vl[j++];
    else v[i] = vr[k++];
  }
}

void mergesort(vector<Card> &v) {
  int n = (int)v.size();
  if (n > 1){
    vector<Card> vl(v.begin(), v.begin() + n/2);
    vector<Card> vr(v.begin() + n/2, v.end());
    mergesort(vl);
    mergesort(vr);
    merge(v, vl, vr);
  }
}

int partition(vector<Card> &v, int p, int r) {
  Card t;
  Card x = v[r];
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (v[j] <= x) {
      ++i;
      t = v[i];
      v[i] = v[j];
      v[j] = t;
    }
  }
  t = v[i+1];
  v[i+1] = v[r];
  v[r] = t;

  return i+1;
}

void quicksort(vector<Card> &v, int p, int r) {
  if (r > p) {
    int q = partition(v, p, r);
    quicksort(v, p, q-1);
    quicksort(v, q+1, r);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  vector<Card> A, B;
  cin >> n;
  A.reserve(n);
  B.reserve(n);
  for (int i = 0; i < n; ++i) {
    Card c;
    cin >> c.suit >> c.num;
    A.push_back(c);
    B.push_back(c);
  }

  quicksort(A, 0, n-1);
  mergesort(B);

  int i;
  for (i = 0; i < n; ++i)
    if (A[i] != B[i]) break;
  if (i < n) cout << "Not stable\n";
  else cout << "Stable\n";

  for (int i = 0; i < n; ++i)
    cout << A[i].suit << " " << A[i].num << "\n";

  return 0;
}

