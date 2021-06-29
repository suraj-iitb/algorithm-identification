#include <iostream>
#include <vector>

class A
{
public:
    A()
    {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for(int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        int cnt = bubbleSort(a, n);

        show(a);
        std::cout << cnt << std::endl;
    }

    const int bubbleSort(std::vector<int>& a,  const int n)
    {
        int cnt = 0;
        bool flag = true;

        while(flag)
        {
            flag = false;

            for(int i = n - 1; i >= 1; --i)
            {
                if(a[i] < a[i - 1])
                {
                    int v = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = v;

                    flag = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void show(const std::vector<int>& a)
    {
        for(int i = 0; i < a.size(); ++i)
        {
            std::cout << a[i] << (i + 1 == a.size() ? "\n" : " ");
        }
    }
};

int main(void)
{
    A a;
    return 0;
}
