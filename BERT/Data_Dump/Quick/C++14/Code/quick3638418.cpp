#include <algorithm>
#include <iostream>
#include <vector>

const long INF = 10e9 + 1;

struct Card {
  char suit;
  long num;

  bool operator<=(Card &c) { return num <= c.num; };
  bool operator>=(Card &c) { return num >= c.num; };
  bool operator==(Card &c) { return num == c.num && suit == c.suit; };
  void print() { std::cout << suit << " " << num << std::endl; };
};

template <typename T> int partition(std::vector<T> &a, int p, int r) {
  T x = a.at(r);
  int i = p - 1;
  for (int j = p; j < r; ++j) {
    if (a.at(j) <= x) {
      ++i;
      std::swap(a.at(i), a.at(j));
    }
  }
  std::swap(a.at(i + 1), a.at(r));
  return i + 1;
}

template <typename T> void quickSort(std::vector<T> &a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}

template <typename T>
int merge(std::vector<T> &a, int left, int mid, int right) {
  int nL = mid - left, nR = right - mid;
  std::vector<T> L(nL, Card{}), R(nR, Card{});
  for (int i = 0; i < nL; i++) {
    L[i] = a[left + i];
  }
  for (int i = 0; i < nR; i++) {
    R[i] = a[mid + i];
  }
  L.push_back(Card{'A', INF});
  R.push_back(Card{'A', INF});

  int i = 0, j = 0;
  for (int k = left; k < right; ++k) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      ++i;
    } else {
      a[k] = R[j];
      ++j;
    }
  }
  return i + j;
}

template <typename T> void mergeSort(std::vector<T> &a, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

template <typename T>
bool isStable(std::vector<T> &orig, std::vector<T> &sorted) {
  std::size_t n = orig.size();
  std::vector<T> b(n, T{});
  std::copy(orig.begin(), orig.end(), b.begin());
  mergeSort<T>(b, 0, n);
  for (std::size_t i = 0; i < n; ++i) {
    if (!(sorted.at(i) == b.at(i)))
      return false;
  }
  return true;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Card> orig(n, Card{}), a(n, Card{});
  for (int i = 0; i < n; ++i) {
    Card c{};
    std::cin >> c.suit >> c.num;
    orig.at(i) = c;
  }

  copy(orig.begin(), orig.end(), a.begin());
  quickSort<Card>(a, 0, n - 1);
  std::cout << (isStable<Card>(orig, a) ? "Stable" : "Not stable") << std::endl;

  for (int i = 0; i < n; ++i) {
    a.at(i).print();
  }
}

