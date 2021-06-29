#include <iostream>
#include <climits>

using namespace std;

#define N 1000000
#define MAXVALUE 1000000000

struct Card
{
    int key;
    char symbol;
};

Card CARD[N], CARD2[N];
int length;

void swap(Card*, Card*);
int partition(int, int);
void quicksort(int , int);

void merge(int, int, int);
void mergesort(int, int);

int main() {
    int index = 0;

    cin >> length;
    for(int i=0; i < length; ++i) {
        cin >> CARD[i].symbol >> CARD[i].key;
        CARD2[i].symbol = CARD[i].symbol;
        CARD2[i].key = CARD[i].key;
    }

    quicksort(0, length-1);
    mergesort(0, length);

    bool stability = true;
    for(int i=0; i < length; ++i) {
        if(CARD[i].symbol != CARD2[i].symbol) stability = false;
    }

    if(stability == true)
        cout << "Stable" << endl;
    
    else 
        cout << "Not stable" << endl;

    for(int i=0; i<length; ++i) {
        cout << CARD[i].symbol << " " << CARD[i].key << endl;
    }

    return 0;
}

void swap(Card *p1, Card *p2) {
    Card tmp;
    tmp = *p2;
    *p2 = *p1;
    *p1 = tmp;
}

int partition(const int p, const int r) {
    int x = CARD[r].key, i = p-1;

    for(int j=p; j < r; ++j) {
        if(CARD[j].key <= x) {
            i++;
            swap(&CARD[i], &CARD[j]);
        }
    }
    swap(&CARD[i+1], &CARD[r]);

    return (i+1);
}

void quicksort(int p, int r) {
    if(p < r) {
        int q;
        q = partition(p, r);
        quicksort(p, q-1);
        quicksort(q+1, r);
    }
}

void merge(int left, int mid, int right) {
    int i=0, j=0;
    int n1 = mid - left, n2 = right - mid;
    Card *L = new Card[n1+1], *R = new Card[n2+1];

    for(i=0; i<n1; ++i) {
        L[i] = CARD2[left+i];
    } 

    for(i=0; i<n2; ++i) {
        R[i] = CARD2[mid+i];
    }

    L[n1].key = R[n2].key = INT_MAX;
    i = j = 0;
    for(int k = left; k < right; ++k) {
        if(L[i].key <= R[j].key) {
            CARD2[k] = L[i];
            i++;
        }

        else {
            CARD2[k] = R[j];
            j++;
        }
    }
}   

void mergesort(int left, int right) {
    if(left+1 < right) {
        int mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid, right);
        merge(left, mid, right);
    }
}
