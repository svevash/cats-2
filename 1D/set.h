#include <vector>

class Set {
 public:
  Set(const std::vector<int64_t> & v) {
      for (auto i : v) {
          Add(i);
      }
  }

  Set() = default;

  void Add(int64_t num) {
      if (!Contains(num)) {
          vec.push_back(num);
      }
  }

  void Remove(int64_t num) {
      if (Contains(num)) {
          if (vec.size() > 0) {
              int64_t k = 0;
              while (vec[k] != num) {
                  k++;
              }
              vec[k] = vec[vec.size() - 1];
              vec.resize(vec.size() - 1);
          } else {
              vec.resize(0);
          }
      }

  }

  bool Contains(int64_t num) const {
      for (auto i : vec) {
          if (i == num) {
              return true;
          }
      }
      return false;
  }

  std::vector<int64_t> Data() const {
      std::vector<int64_t> v(vec);
      return v;
  }

  ////  A|B
  Set Union(const Set & B) const {
      std::vector<int64_t> res;
      Set Res(res);
      for (auto i : vec) {
          Res.Add(i);
      }
      for (auto i : B.Data()) {
          Res.Add(i);
      }
      return Res;
  }

  //// A&B
  Set Intersection(const Set & B) const {
      std::vector<int64_t> res;
      Set Res(res);
      for (auto i : vec) {
          if (B.Contains(i)) {
              Res.Add(i);
          }
      }
      return Res;
  }

  //// A-B
  Set Difference(const Set & B) const {
      std::vector<int64_t> res;
      Set Res(res);
      for (auto i : vec) {
          if (!B.Contains(i)) {
              Res.Add(i);
          }
      }
      return Res;
  }

  //// A|B - A&B
  Set SymmetricDifference(const Set & B) const {
      std::vector<int64_t> res;
      Set Res(res);
      for (auto i : vec) {
          if (!B.Contains(i)) {
              Res.Add(i);
          }
      }
      for (auto i : B.Data()) {
          if (!Contains(i)) {
              Res.Add(i);
          }
      }
      return Res;
  }

 private:
  std::vector<int64_t> vec;
};
