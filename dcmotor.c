#include "dcmotor.h"
    


    void DC_Motor_Init(void){
      DC_DriveDDR|= _BV(DC_XPinL);
      DC_DriveDDR|= _BV(DC_XPinR);
      
      DC_DriveDDR|= _BV(DC_YPinL);
      DC_DriveDDR|= _BV(DC_YPinR);
    }

    void DC_DriveX(uint8_t pwm){
      if (pwm) {DC_DriveXPort|=_BV()} else {}
      
    }
    void DC_DriveY(uint8_t pwm){
      
    }
