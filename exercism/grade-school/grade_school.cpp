#include "grade_school.h"

#include <algorithm>

namespace grade_school {
school::school() {}

const school::roster_t& school::roster() const { return roster_; }
void school::add(std::string_view name, int grade) {
  roster_[grade].push_back(std::string(name));
  std::sort(roster_[grade].begin(), roster_[grade].end());
}

const std::vector<std::string>& school::grade(int grade) const {
  auto it = roster_.find(grade);
  static const std::vector<std::string> empty_list;
  return (it != roster_.end()) ? it->second : empty_list;
}
}  // namespace grade_school
