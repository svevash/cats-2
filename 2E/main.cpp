#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using ObjectId = unsigned long long int;

struct GameObject
{
    ObjectId id;
    string name;
    size_t x;
    size_t y;
};

//#include "game_database.h"

bool operator>(const GameObject& a, const GameObject& b) {
    return a.id > b.id;
}

template<class Tp, template<class> class Compare>
class DereferenceCompare {
  Compare<Tp> comp;

 public:
  bool operator()(const Tp* const a, const Tp* const b) const {
      return comp(*a, *b);
  }
};



class GameDatabase {
 public:
  GameDatabase() = default;

  void Insert(ObjectId id, string name, size_t x, size_t y) {
      GameObject ttt;
      ttt.name = name;
      ttt.id = id;
      ttt.x = x;
      ttt.y = y;
      Remove(id);
      objects[id] = ttt;
      names[name].insert(&(objects[id]));
      positions[std::pair<size_t, size_t>(x, y)].insert(&(objects[id]));
  }

  void Remove(ObjectId id) {
      auto iter = objects.find(id);
      if (iter != objects.end()) {
          names[iter->second.name].erase(&(iter->second));
          positions[std::pair<size_t, size_t>(iter->second.x,
                                              iter->second.y)].erase(&(iter->second));
          objects.erase(id);
          if (names[iter->second.name].empty()) {
              names.erase(iter->second.name);
          }
          if (positions[pair<size_t, size_t>(iter->second.x,
                                             iter->second.y)].empty()) {
              positions.erase(pair<size_t, size_t>(iter->second.x,
                                                   iter->second.y));
          }
      }
  }

  vector<GameObject> DataByName(string name) const {
      vector<GameObject> res;
      if (names.find(name) != names.end()) {
          for (const auto& i : names.find(name)->second) {
              res.push_back(*i);
          }
      }
      return res;
  }

  vector<GameObject> DataByPosition(size_t x, size_t y) const {
      vector<GameObject> res;
      if (positions.find(std::pair<size_t, size_t>(x, y)) != positions.end()) {
          for (auto i : positions.find(std::pair<size_t,
                                                 size_t>(x, y))->second) {
              res.push_back(*i);
          }
      }
      return res;
  }

  vector<GameObject> Data() const {
      vector<GameObject> res;
      for (const auto& i : objects) {
          res.push_back(i.second);
      }
      return res;
  }

 private:
  std::map<ObjectId, GameObject, std::greater<>> objects;
  std::map<string, std::set<GameObject*, DereferenceCompare<GameObject,
                                                            std::greater>>> names;
  std::map<std::pair<size_t, size_t>, std::set<GameObject*,
                                               DereferenceCompare<GameObject, std::greater>>> positions;
};





template<class Stream>
void operator<<(Stream& s, const GameObject& obj)
{
    s << obj.id << ' ' << obj.name << ' ' << obj.x << ' ' << obj.y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    GameDatabase db;
    // *******************************
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i)
    {
        size_t op_type, id, x, y;
        string name;
        cin >> op_type >> id;
        if (op_type) // remove operation
        {
            db.Remove(id);
            continue;
        }
        cin.ignore(1);
        cin >> name >> x >> y;
        db.Insert(id, std::move(name), x, y);
    }
    // *******************************
    for (size_t i = 0; i <= 49; ++i)
        for (size_t j = 0; j <= 49; ++j)
            for (const auto& e : db.DataByPosition(i, j))
                cout << e;
    for (char i = 'a'; i <= 'z'; ++i)
        for (char j = 'a'; j <= 'z'; ++j)
            for (const auto& e : db.DataByName(string() + i + j))
                cout << e;
    for (const auto& e : db.Data())
        cout << e;
    cout.flush();
    return 0;
}