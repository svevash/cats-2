class PrimeNumberGenerator {
 public:
  explicit PrimeNumberGenerator(int start) {
    this->startGen = start;
  };
  int GetNextPrime() {
    int answer;
    while (true) {
      int countDel = 0;
      for (int i = 2; i < this->startGen; i++) {
        if (this->startGen % i == 0) {
          countDel++;
        }
        if (countDel > 0) {
          break;
        }
      }
      if (countDel == 0) {
        answer = this->startGen;
        this->startGen++;
        return answer;
      } else {
        this->startGen++;
      }
    }
  };
 private:
  int startGen;
};
