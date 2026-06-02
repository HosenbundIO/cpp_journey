namespace targets {
// TODO: Insert the code for the alien class here
class Alien {
private:
  int health;

public:
  Alien(int x, int y) : health(3), x_coordinate(x), y_coordinate(y) {}

  int x_coordinate;
  int y_coordinate;

  int get_health() { return health; }
  bool hit() {
    if (get_health() > 0) {
      health -= 1;
      return true;
    }
    return false;
  }
  bool is_alive() { return get_health() > 0; }
  bool teleport(int x_new, int y_new) {
    x_coordinate = x_new;
    y_coordinate = y_new;
    return true;
  }
  bool collision_detection(Alien alien_obj) {
    return (alien_obj.x_coordinate == x_coordinate &&
            alien_obj.y_coordinate == y_coordinate);
  }
};
} // namespace targets
