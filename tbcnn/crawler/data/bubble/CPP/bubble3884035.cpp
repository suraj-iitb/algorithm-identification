#include <iostream>


class Control
{
public:
    bool Run();

private:
    bool Read();

    void Sort();

    void Write();

    bool isValid(int target);

private:

    class BubbleSort
    {
    public:
        int size;
        int* data;

        int cnt;

        BubbleSort();

        void Sort();
    };

    BubbleSort bubble_sort;

};

bool Control::Run()
{
    if (!Read())
        return false;

    Sort();

    Write();

    return true;
}

bool Control::Read()
{
    std::cin >> bubble_sort.size;

    if (!isValid(bubble_sort.size))
        return false;

    bubble_sort.data = new int[bubble_sort.size];

    for (int i = 0; i < bubble_sort.size; i++) {
        
        std::cin >> bubble_sort.data[i];
    }

    return true;
}

void Control::Sort()
{
    bubble_sort.Sort();
}

void Control::Write()
{
    for (int i = 0; i < bubble_sort.size; i++) {

        i == bubble_sort.size - 1 ? std::cout << bubble_sort.data[i] << std::endl : std::cout << bubble_sort.data[i] << " ";

    }

    std::cout << bubble_sort.cnt << std::endl;

    delete[] bubble_sort.data;
    bubble_sort.data = NULL;
}

bool Control::isValid(int target)
{
    const int MIN = 1;
    const int MAX = 100;

    if (MIN > target || MAX < target)
        return false;

    return true;
}

Control::BubbleSort::BubbleSort()
    : data(NULL)
    , size(0)
    , cnt(0)
{

}

void Control::BubbleSort::Sort()
{
    int flag = 1;

    while (flag) {

        flag = 0;

        for (int j = size - 1; j >= 1; j--) {
            
            if (data[j] < data[j - 1]) {
                int t = data[j];
                data[j] = data[j - 1];
                data[j - 1] = t;
                flag = 1;
                cnt++;
            }
        }
    }
}

int main()
{
    if (!Control().Run())
        return 1;

    return 0;
}
