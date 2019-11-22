class Object {
 public:
  virtual std::string ToString() const = 0;
  virtual ~Object() {}
};

class Factory {
 public:
  void Register(const std::string& class_id, Object* (*instance_creator)()) {

  }
  Object* Create(const std::string& class_id) {

  }
 private:

};
