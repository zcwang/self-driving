#ifndef PATH_PLANNING_COST
#define PATH_PLANNING_COST

#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>

#include "utility.h"
#include "params.h"
#include "prediction.h"
#include "../Eigen-3.3/Eigen/Dense"
#include "behavior.h"
#include "trajectory.h"

class Cost {
public:
  Cost(struct TrajectoryXY const &trajectory, Target target, Prediction &prediction, int car_lane);
  virtual ~Cost();
  double get_cost() {
    return _cost;
  }
private:
  bool check_collision(double x0, double y0, double theta0, double x1, double y1, double theta1);
  int check_collision_on_trajectory(TrajectoryXY const &trajectory, std::map<int, std::vector<Coord>> &predictions);
  bool check_max_capabilities(std::vector<std::vector<double>> &traj);
  double get_predicted_dmin(TrajectoryXY const &trajectory, std::map<int, std::vector<Coord>> &predictions);
  double _cost;
};

#endif // PATH_PLANNING_COST
