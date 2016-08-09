# kuka_planning_interface

####Test Action Server/Client for KUKA control:

Launch server
```
$ roslaunch pour_kuka server.launch
```

Launch client
```
$ roslaunch pour_kuka client.launch
```

####Actions available in server:

CDS motions:
```
$ rosservice call /control_cmd_interface/kuka_cmd 'home'
$ rosservice call /control_cmd_interface/kuka_cmd 'pour'
$ rosservice call /control_cmd_interface/kuka_cmd 'back'
```

Linear Joint Motion:
```
$ rosservice call /control_cmd_interface/kuka_cmd 'goto_init'
$ rosservice call /control_cmd_interface/kuka_cmd 'goto_home'
```

Teaching commands:
```
$ rosservice call /control_cmd_interface/kuka_cmd 'grav_comp'
$ rosservice call /control_cmd_interface/kuka_cmd 'safe_grav_comp'
$ rosservice call /control_cmd_interface/kuka_cmd 'joint_imp'
$ rosservice call /control_cmd_interface/kuka_cmd 'joint_stiff'
$ rosservice call /control_cmd_interface/kuka_cmd 'lock_joint_6'
$ rosservice call /control_cmd_interface/kuka_cmd 'lock_joint_7'
$ rosservice call /control_cmd_interface/kuka_cmd 'lock_joint_5_6'

```

---
####To test this interface in simulation
Launch rviz simulator 
```
$ roslaunch kuka_lwr_bringup lwr_simulation.launch
```
Cartesian-to-Joint/Joint-to-Cart Estimation
```
$ roslaunch state_transformers pouring_ctrls_sim.launch
```

####To test this interface with the real robot (specifically for teaching commands)
Launch rviz simulator 
```
$ roslaunch kuka_lwr_bringup lwr_realtime.launch
```
Cartesian-to-Joint/Joint-to-Cart Estimation
```
$ roslaunch state_transformers pouring_ctrls_real.launch
```
