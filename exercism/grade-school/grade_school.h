#pragma once

#include <map>
#include <string>
#include <vector>

namespace grade_school {
class school {
 public:
  using roster_t = std::map<int, std::vector<std::string>>;

  school();

  const roster_t& roster() const;
  const std::vector<std::string>& grade(int grade) const;

  void add(std::string_view name, int grade);

 private:
  roster_t roster_;
};

}  // namespace grade_school
