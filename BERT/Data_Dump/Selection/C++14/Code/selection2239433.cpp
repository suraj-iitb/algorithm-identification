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
    for (size_t i = 0; i < v.size(); ++i) {
        int mini = i;
        for (size_t j = i; j < v.size(); ++j) {
            if (v[j] < v[mini]) {
                mini = j;
            }
        }
        if (static_cast<int>(i) != mini) {
            int tmp = v[i];
            v[i] = v[mini];
            v[mini] = tmp;
            ++c;
        }
    }
    p(v);
    printf("%d\n", c);
}
