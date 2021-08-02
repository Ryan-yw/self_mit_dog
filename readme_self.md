# 需要安装的依赖库：

sudo apt install mesa-common-dev freeglut3-dev coinor-libipopt-dev libblas-dev liblapack-dev gfortran liblapack-dev coinor-libipopt-dev cmake gcc build-essential libglib2.0-dev

sudo apt-get install default-jdk python-all-dev liblua5.1-0-dev golang doxygen python-epydoc libc6-dev


# sim界面需要依赖qt,要修改安装包的路径：
if(POLICY CMP0071)
  cmake_policy(SET CMP0071 OLD)
endif()

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(Qt5Core_DIR /opt/Qt5.10.0/5.10.0/gcc_64/lib/cmake/Qt5Core)
set(Qt5Widgets_DIR /opt/Qt5.10.0/5.10.0/gcc_64/lib/cmake/Qt5Widgets)
set(Qt5Gamepad_DIR /opt/Qt5.10.0/5.10.0/gcc_64/lib/cmake/Qt5Gamepad)


find_package(Qt5Core CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
get_target_property(QtCore_location Qt5::Core LOCATION)
message(STATUS ${QtCore_location})
find_package(Qt5Gui CONFIG REQUIRED)


# 测试
./sim/sim
./user/MIT_Controller/mit_ctrl m s

# qt 安装在      /opt/qt/ 目录下


# 可能存在的问题：找不到 liblsm.so.1 
 sudo cp /usr/local/lib/liblcm.* .

# 实习任务
运动控制算法

1. 完成MIT开源代码的安装和使用；
2. 添加Aliengo到MIT开源代码中；
3. 完成仿真环境下的斜坡估计代码的加入；https://www.youtube.com/watch?v=gZKRE9yvzgw
4. 完成楼梯的识别，以及相对位置关系的建立；https://www.youtube.com/watch?v=CpzQu25iLa0
5. 完成人体跟随的任务；
6. 调研四足上楼梯的方案与方法；


# 论文
1. A Low Cost Modular Actuator for Dynamic Robots【有github网址】
2. Design of a High Torque Density Modular Actuator for Dynamic Robots
3. MIT Cheetah 3: Design and Control of a Robust, Dynamic Quadruped Robot
4. Software and Control Design for the MIT Cheetah Quadruped Robots
5. High-slope Terrain Locomotion for Torque-Controlled Quadruped Robots
6. Optimization-based motion planning for legged robots
7. Highly Dynamic Quadruped Locomotion via Whole-Body Impulse Control and Model Predictive Control
8. Regularized Predictive Control Framework for Robust Dynamic Legged Locomotion
9. Optimized Jumping on the MIT Cheetah 3 Robot
10. Dynamic Locomotion in the MIT Cheetah 3 Through Convex Model-Predictive Control