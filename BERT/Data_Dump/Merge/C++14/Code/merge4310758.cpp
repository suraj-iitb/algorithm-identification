/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <cstdint>
#include <iostream>
#include <string>

constexpr int32_t kMaxArraySize = 500000;

void CallMergeSort(std::istream &input_stream);

class MergeSort {
 public:
  MergeSort() noexcept;
  ~MergeSort() noexcept;
  void AddData(const int32_t value);
  void ResetData() noexcept;
  void Sort();
  void Print() const noexcept;

 private:
  MergeSort(const MergeSort &obj) noexcept = delete;
  MergeSort &operator=(const MergeSort &obj) noexcept = delete;
  MergeSort(MergeSort &&obj) = delete;
  MergeSort &operator=(MergeSort &&obj) = delete;

  void ComputeMergeSort(const int32_t left_end, const int32_t right_end);
  void MergeLeftAndRight(const int32_t left_end, const int32_t center, const int32_t right_end);
  int32_t GetCenterIndex(const int32_t left_end, const int32_t right_end) const;

 private:
  int32_t size_;
  int32_t comparison_count_;  //< デバッグ用
  int32_t values_[kMaxArraySize];
  int32_t left_values_[kMaxArraySize / 2 + 1];   //< 作業領域
  int32_t right_values_[kMaxArraySize / 2 + 1];  //< 作業領域
};

void CallMergeSort(std::istream &input_stream) {
  input_stream.tie(0);
  std::ios::sync_with_stdio(false);
  MergeSort *merge_sort = new MergeSort();
  try {
    int32_t count;
    input_stream >> count;
    for (int32_t index = 0; index < count; ++index) {
      int32_t cvalue;
      input_stream >> cvalue;
      merge_sort->AddData(cvalue);
    }
    merge_sort->Sort();
    merge_sort->Print();
  } catch (...) {
    std::cout << "ERROR" << std::endl;
    throw;
  }
  delete merge_sort;
}

// ****************************************************

MergeSort::MergeSort() noexcept : size_(0), comparison_count_(0), values_{}, left_values_{}, right_values_{} {}
MergeSort::~MergeSort() noexcept {}

void MergeSort::AddData(const int32_t value) {
  if (size_ >= kMaxArraySize) {
    std::cout << "ERROR: AddData(): Data size exceeded a limit = " << kMaxArraySize << std::endl;
    throw 1;
  }
  values_[size_] = value;
  size_++;
}

void MergeSort::Sort() {
  try {
    ComputeMergeSort(0, size_);
  } catch (...) {
    throw;
  }
}

void MergeSort::Print() const noexcept {
  for (int32_t index = 0; index < size_; ++index) {
    if (index != 0) {
      std::cout << " ";
    }
    std::cout << values_[index];
  }
  std::cout << std::endl;
  std::cout << comparison_count_ << std::endl;
}

void MergeSort::ComputeMergeSort(const int32_t left_end, const int32_t right_end) {
  if ((right_end < left_end) || ((left_end < 0) || (right_end > size_))) {
    std::cout << "ERROR: ComputeMergeSort: invalid args. left_end=" << left_end << ", right_end=" << right_end
              << std::endl;
    throw 1;
  }
  try {
    if (left_end + 1 < right_end) {
      const int32_t center = GetCenterIndex(left_end, right_end);
      ComputeMergeSort(left_end, center);
      ComputeMergeSort(center, right_end);
      MergeLeftAndRight(left_end, center, right_end);
    } else {
      // DO NOTHING
    }
  } catch (...) {
    throw;
  }
}

void MergeSort::MergeLeftAndRight(const int32_t left_end, const int32_t center, const int32_t right_end) {
  if (((left_end < 0) || (right_end > size_) || (center <= left_end) || (right_end <= center))) {
    std::cout << "ERROR: MergeLeftAndRight: invalid args. left_end=" << left_end << ", center=" << center
              << ", right_end=" << right_end << std::endl;
    throw 1;
  }
  const int32_t left_size = center - left_end;
  const int32_t right_size = right_end - center;
  if (left_size > kMaxArraySize / 2) {
    std::cout << "ERROR: MergeLeftAndRight: Invalid left_size. left_size=" << left_size << std::endl;
    throw 1;
  } else if (right_size > kMaxArraySize / 2) {
    std::cout << "ERROR: MergeLeftAndRight: Invalid right_size. right_size=" << right_size << std::endl;
    throw 1;
  }
  try {
    for (int32_t index_left = 0; index_left < left_size; ++index_left) {
      left_values_[index_left] = values_[left_end + index_left];
    }
    left_values_[left_size] = INT32_MAX;
    for (int32_t index_right = 0; index_right < right_size; ++index_right) {
      right_values_[index_right] = values_[center + index_right];
    }
    right_values_[right_size] = INT32_MAX;

    int32_t index_left = 0;
    int32_t index_right = 0;
    for (int32_t index_target = left_end; index_target < right_end; ++index_target) {
      if (left_values_[index_left] <= right_values_[index_right]) {
        values_[index_target] = left_values_[index_left];
        ++index_left;
      } else {
        values_[index_target] = right_values_[index_right];
        ++index_right;
      }
      ++comparison_count_;
    }
  } catch (...) {
    throw;
  }
}

int32_t MergeSort::GetCenterIndex(const int32_t left_end, const int32_t right_end) const {
  if ((right_end <= left_end + 1) || ((left_end < 0) || (right_end > size_))) {
    std::cout << "ERROR: GetCenterIndex: invalid args. left_end=" << left_end << ", right_end=" << right_end
              << std::endl;
    throw 1;
  }
  return (left_end + right_end) / 2;
}

void MergeSort::ResetData() noexcept {
  size_ = 0;
}

int main(int argc, char *argv[]) {
  try {
    CallMergeSort(std::cin);
  } catch (...) {
    std::cout << "ERROR: Main" << std::endl;
  }
  return 0;
}

