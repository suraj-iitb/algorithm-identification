#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

template<typename T>
int partition(T ar[], int p, int r){
    T pivot = ar[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if(ar[j] <= pivot){
            i++;
            swap(ar[i], ar[j]);
        }
    }
    i++;
    swap(ar[i], ar[r]);
    return i;
}

template<typename T>
void quicksort(T ar[], int p, int r){
    if(p < r){
        int q = partition(ar, p, r);
        quicksort(ar, p, q - 1);
        quicksort(ar, q + 1, r);
    }
}

class Card {
    public:
        char squit;
        int value;
        bool operator <=(const Card &c){
            return this->value <= c.value;
        }

        bool operator != (const Card &c){
            return this->value != c.value || squit != c.squit;
        }

        bool operator > (const Card &c){
            return this->value > c.value;
        }
};

Card qs[100000];
Card bs[100000];

int main(int argc, char const* argv[])
{
    int n;

    scanf("%d ", &n);
    
    for (int i = 0; i < n; i++) {
        char s;
        int v;
        scanf("%c %d ", &s, &v);
        qs[i].squit = s;
        qs[i].value = v;
        bs[i].squit = s;
        bs[i].value = v;
    }

    quicksort(qs, 0, n - 1);
    stable_sort(bs, bs+n,
        [](const Card &fst, const Card &snd) -> bool
        {
            if(fst.value < snd.value) return true;
            return false;
        });

    bool is_stable = true;
    for (int i = 0; i < n; i++) {
        if(qs[i] != bs[i]){
            is_stable = false;
            break;
        }
    }

    if (is_stable) {
        puts("Stable");
    } else {
        puts("Not stable");
    }

    for (int i = 0; i < n ; i++) {
        printf("%c %d\n", qs[i].squit, qs[i].value);
    }

    return 0;
}
