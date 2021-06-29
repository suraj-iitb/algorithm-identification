#include <iostream>
#include <memory>
// #include <iomanip>
using namespace std;

struct Card
{
  char suit;
  int number;
  int index;
};

int
partition(Card cards[], int p, int r)
{
  int x = cards[r].number;
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (cards[j].number <= x) {
      i++;
      Card tmp = cards[i];
      cards[i] = cards[j];
      cards[j] = tmp;
    }
  }

  Card tmp = cards[i + 1];
  cards[i + 1] = cards[r];
  cards[r] = tmp;

  return i + 1;
}

void
quicksort(Card cards[], int p, int r)
{
  if (p < r) {
    int q = partition(cards, p, r);
    quicksort(cards, p, q - 1);
    quicksort(cards, q + 1, r);
  }
}

bool
isStable(Card cards[], int size)
{
  char suits[] = "SHCD";
  for (int s = 0; s < 4; s++) {
    char suit = suits[s];
    Card prev = { 0, -1, -1 };
    for (int i = 0; i < size; i++) {
      if (prev.number == cards[i].number && prev.index > cards[i].index) {
        return false;
      }
      prev = cards[i];
    }
  }

  return true;
}

int
main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // cout << fixed << setprecision(5);

  int n;
  cin >> n;
  auto cards = make_unique<Card[]>(n);

  for (int i = 0; i < n; i++) {
    cards[i].index = i;
    cin >> cards[i].suit >> cards[i].number;
  }

  quicksort(cards.get(), 0, n - 1);

  if (isStable(cards.get(), n)) {
    cout << "Stable\n";
  } else {
    cout << "Not stable\n";
  }

  for (int i = 0; i < n; i++) {
    cout << cards[i].suit << " " << cards[i].number << "\n";
  }

  return 0;
}

