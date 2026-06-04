namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus { troll = 0, guest = 1, user = 2, mod = 3 };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action { read, write, remove };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster, AccountStatus viewer) {
  if (poster == AccountStatus::troll) {
    return (viewer == AccountStatus::troll);
  }
  return true;
}

bool display_post_switch(AccountStatus poster, AccountStatus viewer) {
  switch (poster) {
  case AccountStatus::troll:
    return (viewer == AccountStatus::troll);

  case AccountStatus::guest:
  case AccountStatus::user:
  case AccountStatus::mod:
    return true;

  default:
    return false;
  }
}

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus status) {
  switch (action) {
  case Action::read:
    return true;
  case Action::write:
    return (status != AccountStatus::guest);
  case Action::remove:
    return (status == AccountStatus::mod);
  default:
    return false;
  }
}

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus p1, AccountStatus p2) {
  bool p1_auth = (p1 == AccountStatus::user || p1 == AccountStatus::mod);
  bool p2_auth = (p2 == AccountStatus::user || p2 == AccountStatus::mod);

  bool p_troll = (p1 == AccountStatus::troll && p2 == AccountStatus::troll);

  return (p1_auth && p2_auth) || (p_troll);
}

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus p1, AccountStatus p2) { return p1 > p2; }
} // namespace hellmath
