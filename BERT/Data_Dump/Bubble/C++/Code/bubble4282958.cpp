/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <iostream>

class BubbleSort {
 public:
  BubbleSort();
  ~BubbleSort();
  void Main(std::istream &input_stream);

 private:
  void Sort();
  bool ShouldSwap(const int index_target);
  void SwapWithLeftNext(const int index_target);
  void Load(std::istream &input_stream);
  void Print();

 private:
  int count_;
  int values_[100];
  int swapped_count_;
};

BubbleSort::BubbleSort() : count_(0), values_{-1}, swapped_count_{0} {}

BubbleSort::~BubbleSort() {}

void BubbleSort::Main(std::istream &input_stream) {
  Load(input_stream);
  Sort();
  Print();
}

void BubbleSort::Sort() {
  bool should_scan = true;
  int index_unsorted_head = 0;
  while (should_scan) {
    should_scan = false;
    for (int index_target = count_ - 1; index_target >= index_unsorted_head + 1; --index_target) {
      if (ShouldSwap(index_target)) {
        SwapWithLeftNext(index_target);
        should_scan = true;
      }
    }
    ++index_unsorted_head;
  }
}

bool BubbleSort::ShouldSwap(const int index_target) {
  return (values_[index_target - 1] > values_[index_target]);
}

void BubbleSort::SwapWithLeftNext(const int index_target) {
  const int cvalue = values_[index_target];
  values_[index_target] = values_[index_target - 1];
  values_[index_target - 1] = cvalue;
  ++swapped_count_;
}

void BubbleSort::Load(std::istream &input_stream) {
  input_stream >> count_;
  for (int index = 0; index < count_; ++index) {
    input_stream >> values_[index];
  }
}

void BubbleSort::Print() {
  for (int index = 0; index < count_; ++index) {
    if (index != 0) {
      std::cout << " ";
    }
    std::cout << values_[index];
  }
  std::cout << std::endl;
  std::cout << swapped_count_ << std::endl;
}

int main(int argc, char *argv[]) {
  BubbleSort *bubble_sort = new BubbleSort();
  bubble_sort->Main(std::cin);
  delete bubble_sort;
  return 0;
}

