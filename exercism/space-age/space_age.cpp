#include "space_age.h"

namespace space_age {
namespace {
static constexpr double EARTH_YEAR_SECONDS = 31557600;

static constexpr double MERCURY_YEAR = 0.2408467;
static constexpr double VENUS_YEAR = 0.615119726;
static constexpr double EARTH_YEAR = 1.0;
static constexpr double MARS_YEAR = 1.88088158;
static constexpr double JUPITER_YEAR = 11.862615;
static constexpr double SATURN_YEAR = 29.447498;
static constexpr double URANUS_YEAR = 84.016846;
static constexpr double NEPTUNE_YEAR = 164.79132;

}  // namespace

space_age::space_age(long long seconds)
    : seconds_(seconds), earth_years_(seconds / EARTH_YEAR_SECONDS) {}

long long space_age::seconds() const { return seconds_; }

double space_age::on_earth() const { return earth_years_ / 1.0; }
double space_age::on_mercury() const { return earth_years_ / MERCURY_YEAR; }
double space_age::on_venus() const { return earth_years_ / VENUS_YEAR; }
double space_age::on_mars() const { return earth_years_ / MARS_YEAR; }
double space_age::on_jupiter() const { return earth_years_ / JUPITER_YEAR; }
double space_age::on_saturn() const { return earth_years_ / SATURN_YEAR; }
double space_age::on_uranus() const { return earth_years_ / URANUS_YEAR; }
double space_age::on_neptune() const { return earth_years_ / NEPTUNE_YEAR; }

}  // namespace space_age
