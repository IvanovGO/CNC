/* 
 * File:   dcmotor.h
 * Author: gri
 *
 * Created on 24 ??????? 2021 ?., 22:11
 */



#include <avr/io.h>



#define F_CPU 12000000UL
    
#define DC_DriveXPORT PORTD
#define DC_DriveXDDR DDRD
#define DC_DriveYPORT PORTB
#define DC_DriveYDDR DDRB
#define DC_XPinL 0   
#define DC_XPinR 1  
#define DC_YPinL 2    
#define DC_YPinR 3   

    void DC_Motor_Init(void);
    void DC_DriveX(uint8_t pwm);
    void DC_DriveY(uint8_t pwm);


