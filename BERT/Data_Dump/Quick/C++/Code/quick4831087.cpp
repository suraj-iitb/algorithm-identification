#include <iostream>

using namespace std;

class Card
{
public:
    char type;
    int val;
    int seq;

    Card(){};
    Card(Card &c)
    {
        this->type = c.type;
        this->val = c.val;
        this->seq = c.seq;
    }
    ~Card(){};
    bool operator>(const Card &o)
    {
        if (this->val > o.val)
        {
            return true;
        }
        return false;
    }
    bool operator<(const Card &o)
    {
        if (this->val > o.val)
        {
            return false;
        }
        return true;
    }
    bool operator<=(const Card &o)
    {
        if (this->val <= o.val)
        {
            return true;
        }
        return false;
    }
};

int cnt;
Card a[101010];
Card l[101010];
Card r[101010];
Card c[101010];
Card bk[101010];

void mergeSort(Card a[], int left, int right);
void merge(Card a[], int left, int mid, int right);
void quickSort(Card a[], int l, int r);
int partition(Card a[], int l, int r);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].type >> c[i].val;
        c[i].seq = i;
        bk[i] = c[i];
    }
    quickSort(c, 0, n);
    mergeSort(bk, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (c[i].seq != bk[i].seq)
        {
            cout << "Not stable" << endl;
            break;
        }
        if (i == n - 1)
        {
            cout << "Stable" << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i].type << " " << c[i].val << endl;
    }
    return 0;
}

void mergeSort(Card a[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
    return;
}

void merge(Card a[], int left, int mid, int right)
{
    int cnt1, cnt2;
    cnt1 = mid - left;
    cnt2 = right - mid;
    for (int i = 0; i < cnt1; i++)
    {
        l[i] = a[left + i];
    }
    for (int i = 0; i < cnt2; i++)
    {
        r[i] = a[mid + i];
    }
    l[cnt1].val = 0x7FFFFFFF;
    r[cnt2].val = 0x7FFFFFFF;
    int i, j;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
    return;
}

void quickSort(Card a[], int l, int r)
{
    if (l < r)
    {
        int pos = partition(a, l, r);
        quickSort(a, l, pos);
        quickSort(a, pos + 1, r);
    }
    return;
}

int partition(Card a[], int l, int r)
{
    Card sep = a[r - 1];
    int i = l;
    for (int j = l; j < r - 1; j++)
    {
        if (a[j] <= sep)
        {
            Card temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            i++;
        }
    }
    a[r - 1] = a[i];
    a[i] = sep;
    return i;
}
