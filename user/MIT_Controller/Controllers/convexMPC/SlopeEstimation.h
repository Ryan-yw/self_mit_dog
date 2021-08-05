#ifndef SLOPE_ESTIMATION_H
#define SLOPE_ESTIMATION_H

/*!
*  斜坡估计代码
*/
#include <eigen3/Eigen/Dense>
#include <cppTypes.h>
#include <../FSM_States/ControlFSMData.h>



class Slope
{
public:
    void computeSlope(const Vec3<float>* pFoot,const float yaw);

    Mat34<float> W_t;
    Vec4<float>  z;
    Mat43<float> W;
    Vec3<float> a;
    float angle;
    Mat3<float> m;
    float roll = 0,pre_roll,roll_offset = 0.3;
    float pitch = 0;

};


void printEstimationParam(const StateEstimate<float>& se);






#endif
