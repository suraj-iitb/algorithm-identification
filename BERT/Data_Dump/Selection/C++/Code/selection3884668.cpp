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

    class SelectionSort
    {
    public:
        int size;
        int* data;

        int cnt;

        SelectionSort();

        void Sort();
    };

    SelectionSort selection_sort;

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
    std::cin >> selection_sort.size;

    if (!isValid(selection_sort.size))
        return false;

    selection_sort.data = new int[selection_sort.size];

    for (int i = 0; i < selection_sort.size; i++) {

        std::cin >> selection_sort.data[i];
    }

    return true;
}

void Control::Sort()
{
    selection_sort.Sort();
}

void Control::Write()
{
    for (int i = 0; i < selection_sort.size; i++) {

        i == selection_sort.size - 1 ? std::cout << selection_sort.data[i] << std::endl : std::cout << selection_sort.data[i] << " ";

    }

    std::cout << selection_sort.cnt << std::endl;

    delete[] selection_sort.data;
    selection_sort.data = NULL;
}

bool Control::isValid(int target)
{
    const int MIN = 1;
    const int MAX = 100;

    if (MIN > target || MAX < target)
        return false;

    return true;
}

Control::SelectionSort::SelectionSort()
    : data(NULL)
    , size(0)
    , cnt(0)
{

}

void Control::SelectionSort::Sort()
{
    for (int i = 0; i < Control::SelectionSort::size; i++) {

        int min = i;
        bool flag = false;

        for (int j = i; j < Control::SelectionSort::size; j++) {

            if (Control::SelectionSort::data[j] < Control::SelectionSort::data[min]) {

                min = j;
                flag = true;
            }
        }

        if (flag) {
            int t = Control::SelectionSort::data[i];
            Control::SelectionSort::data[i] = Control::SelectionSort::data[min];
            Control::SelectionSort::data[min] = t;
            cnt++;
        }
    }
}

int main()
{
    if (!Control().Run())
        return 1;

    return 0;
}
