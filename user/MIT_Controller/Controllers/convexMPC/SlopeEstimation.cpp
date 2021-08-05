#include "SlopeEstimation.h"
#include <math.h>

/*!
 *  斜坡估计
 */
void Slope::computeSlope(const Vec3<float>* pFoot, const float yaw)
{
    //斜坡角度估计
    W << 1,pFoot[0][0], pFoot[0][1],
            1,pFoot[1][0], pFoot[1][1],  
            1,pFoot[2][0], pFoot[2][1],
            1,pFoot[3][0], pFoot[3][1];
    z<< pFoot[0][2],
        pFoot[1][2],
        pFoot[2][2],
        pFoot[3][2];
    W_t = W.transpose();
    m = W_t * W;
    a =  m.inverse() * W_t * z;
    angle = std::abs(std::atan(a[1])); 

    //roll pitch 角度补偿
    pitch = std::abs(std::atan(std::tan(angle) * std::cos(yaw)));
    if(yaw >= (-M_PI + roll_offset) && yaw < (M_PI - roll_offset))
    {
        roll = std::asin((std::sin(angle)-std::sin(std::abs(pitch))*std::cos(std::abs(yaw)))/(std::sin(std::abs(yaw))));
        pre_roll = 0;
    }   
 
    if(yaw >= -M_PI_2 && yaw < 0) 
    {
        pitch = -1 * pitch;
        roll = roll;
    }
    else if(yaw >= 0 && yaw <M_PI_2)
    {
        pitch = -1 * pitch;
        roll = -1 * roll;
    }
    else if(yaw >= M_PI_2 && yaw < (M_PI - roll_offset))
    {
        pitch = 1 * pitch;
        roll = -1 * roll;
    }
    else if (yaw >= (-M_PI + roll_offset) && yaw < -M_PI_2)
    {
        pitch = 1 * pitch;
        roll =  roll;
    }
    else
    {
        pitch = pitch;
        roll = 0;
    }


    //roll = std::asin((std::sin(angle)-std::sin(pitch)*std::cos(yaw))/std::sin(yaw));
    
    std::cout << "测试" << std::sin(std::abs(yaw)) << std::endl;    
    // std::cout << -1*a << std::endl; 
    // std::cout << "pitch=" << pitch <<std::endl; 
    // std::cout << pitch << std::endl;    
    
};









/*!
 *  打印状态估计的到的参数 
 */
void printEstimationParam(const StateEstimate<float>& se)
{

    std::cout << "状态估计参数" << std::endl;
    //std::cout << "contactEstimate:"   << se.contactEstimate[0] << "  " << se.contactEstimate[1] << "  " << se.contactEstimate[2] << "  " << se.contactEstimate[3] << std::endl;
    //std::cout << "postion:"   << se.position[0] << "  " << se.position[1] << "  " << se.position[2] << std::endl;
    //std::cout << "vBody:"     << se.vBody[0] << "  " << se.vBody[1] << "  " << se.vBody[2] << std::endl;
    //std::cout << "vWorld:" << se.vWorld[0] << "  " << se.vWorld[1] << "  " << se.vWorld[2] << std::endl;
    //std::cout << "aBody:" << se.aBody[0] << "  " << se.aBody[1] << "  " << se.aBody[2] << std::endl;
    //std::cout << "aWorld:" << se.aWorld[0] << "  " << se.aWorld[1] << "  " << se.aWorld[2] << std::endl;
    //std::cout << "omegaBody:" << se.omegaBody[0] << "  " << se.omegaBody[1] << "  " << se.omegaBody[2] << std::endl;
    //std::cout << "omegaWorld:" << se.omegaWorld[0] << "  " << se.omegaWorld[1] << "  " << se.omegaWorld[2] << std::endl;
    std::cout << "rpy:"       << se.rpy[0] << "  " << se.rpy[1] << "  " << se.rpy[2] << std::endl;

    //测试rBody
    // Mat3<float> R_X,R_Y,R_Z,R;
    // R_X <<  1, 0,                   0,
    //         0, std::cos(se.rpy[0]),-std::sin(se.rpy[0]),
    //         0, std::sin(se.rpy[0]), std::cos(se.rpy[0]);

    // R_Y <<  std::cos(se.rpy[1]), 0, std::sin(se.rpy[1]),
    //         0,                   1, 0,
    //        -std::sin(se.rpy[1]), 0, std::cos(se.rpy[1]);

    // R_Z <<  std::cos(se.rpy[2]),-std::sin(se.rpy[2]),0,
    //         std::sin(se.rpy[2]), std::cos(se.rpy[2]),0,
    //         0,                   0,                  1;

    // R = R_X*R_Y*R_Z;
    //  std::cout << "rBody" << std::endl;
    //  std::cout << se.rBody << std::endl;
    // std::cout << "R" << std::endl;
    // std::cout << R - se.rBody.transpose() << std::endl;
    
}


