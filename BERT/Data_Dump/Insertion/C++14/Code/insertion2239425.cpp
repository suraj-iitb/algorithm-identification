#include <cstdio>
#include <vector>

using namespace std;

void p(const vector<int> &v)
{
    for (size_t i = 0; i < v.size() - 1; ++i) {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[v.size() - 1]);
}

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> v;
    int t;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &t);
        v.push_back(t);
    }
    p(v);
    for (size_t i = 1; i < v.size(); ++i) {
        int e = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > e) {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = e;
        p(v);
    }
}
