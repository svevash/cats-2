class Object {
 public:
  virtual std::string ToString() const = 0;
  virtual ~Object() {}
};

class Smthg : public Object {
 public:
  explicit Smthg(const std::string& class_id) {
      class_id_ = class_id;
  }

  std::string ToString() const override {
      return class_id_;
  }
 private:
  std::string class_id_;
};

Object* my_new_smthg(std::string &s) {
    return new Smthg(s);
}

class Factory {
 public:
  Factory() : vec() {
      std::vector<std::string> ttt = {"apple!", "list", "yet another identifier"};
      for (int i = 0; i < 3; i++) {
          auto kkk = my_new_smthg(ttt[i]);
          std::function<Object*()>d = [=](){ return (new Smthg(ttt[i]));};
          auto p = std::pair{ttt[i], d};
          vec.push_back(p);
      }
  }
  void Register(const std::string& class_id, Object* (*instance_creator)()) {
      auto p = std::make_pair(class_id, instance_creator);
      vec.emplace_back(p);
  }
  Object* Create(const std::string& class_id) {
      Object* ttt = new Smthg(class_id);
      return ttt;
  }
 private:
  std::vector<std::pair<std::string, std::function<Object* ()>>> vec;
};
