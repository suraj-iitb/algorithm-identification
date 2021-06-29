#include <iostream>
#include <vector>

int bubble_sort(std::vector<int>& ary) {
    int n = ary.size();
    int flag = 1;
    int replace_counter = 0;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > 0; j--) {
            if (ary[j] <  ary[j - 1]) {
                std::swap(ary[j], ary[j - 1]);
                replace_counter++;
                flag = 1;
            }
        }
    }
    return replace_counter;
}

int main(int argc, char const* argv[])
{
    int N = 0;
    std::vector<int> ary;
    std::cin >> N;
    ary.resize(N);
    for(auto& i: ary) {
        std::cin >> i;
    }
    int c = bubble_sort(ary);
    for(int i = 0; i < N-1; i++) {
        std::cout << ary[i] << " ";
    }
    std::cout << ary[N - 1] << std::endl;
    std::cout << c << std::endl;
    return 0;
}
