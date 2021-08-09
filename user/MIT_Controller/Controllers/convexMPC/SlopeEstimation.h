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
    void computeSlope(const Vec3<float>* pFoot,const float theta);

    Mat34<float> W_t;
    Vec4<float>  z;
    Mat43<float> W;
    Mat3<float> m;
    Vec3<float> a;
    float alpha;//斜坡倾角
    
    float roll = 0,roll_offset = 0.3;
    float pitch = 0;

};


void printEstimationParam(const StateEstimate<float>& se);






#endif
