/* 
 * File:   newmain.c
 * Author: gri
 *
 * Created on 21 ??????? 2021 ?., 22:49
 */

#include <stdio.h>
#include <stdlib.h>

#include "mylcd.h"
#include "dcmotor.h"

/*
 * 
 */
int main(int argc, char** argv) {
  
  myLCD_Init();
     
    myLCD_PRINT("my-CNC\n");
    
    DC_Motor_Init();
    return (EXIT_SUCCESS);
}

