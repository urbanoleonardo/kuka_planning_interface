#ifndef KUKA_ACTION_SERVER_KUKA_GRAV_AS_H_
#define KUKA_ACTION_SERVER_KUKA_GRAV_AS_H_

#include "kuka_action_server/default_types.h"
#include "kuka_action_server/base_action_server.h"

#include "kuka_action_server/base_j_action.h"
#include "kuka_action_server/base_ee_action.h"
#include "kuka_common_action_server/action_initialiser.h"

namespace asrv{

class Kuka_grav_as:  public Base_j_action, public Base_ee_action, public Base_action_server {

public:

    Kuka_grav_as(ros::NodeHandle&  nh, const Action_j_initialiser &init, const Action_ee_initialiser &init_ee);

    virtual bool execute_CB(alib_server& as_, alib_feedback& feedback_, const cptrGoal& goal);


private:

    std::string action_name;
    std::string action_type;


    // Desired Joint Impedance Command
    Eigen::VectorXd                         des_j_pose;
    Eigen::VectorXd                         des_j_velocity;
    Eigen::VectorXd                         des_j_stiffness;

    // Cartesian Commands
    tf::Pose        des_ee_pose_from_curr;    /// desired end-effector position

};

}

#endif
