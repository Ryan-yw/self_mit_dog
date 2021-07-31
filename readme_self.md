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

