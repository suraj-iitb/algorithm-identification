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
    int c = 0;
    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = v.size() - 1; j >= i + 1; --j) {
            if (v[j] < v[j - 1]) {
                int tmp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = tmp;
                ++c;
            }
        }
    }
    p(v);
    printf("%d\n", c);
}
