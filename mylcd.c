
/*
#define myLCD_Port PORTD
#define myLCD_CON PORTD
#define myLCD_DDR DDRD
#define myLCD_RE 0
#define myLCD_ES 1
#define myLCD_D4 2
#define myLCD_D5 3
#define myLCD_D6 4
#define myLCD_D7 5
*/



#include "mylcd.h"

#include <stdarg.h>
#include <stdio.h>
#include <util/delay.h>

#define LCD_E_TIME 10
//#define DPD myLCD_PORT=0x00;
#define P myLCD_PORT
#define EU myLCD_CON|=  _BV(myLCD_E);
#define ED myLCD_CON&=~ _BV(myLCD_E);
#define RU myLCD_CON |=   _BV(myLCD_RS);
#define RD myLCD_CON &=~  _BV(myLCD_RS);
#define EN ED _delay_us(LCD_E_TIME); EU _delay_us(LCD_E_TIME); ED _delay_us(LCD_E_TIME);
#define d15 _delay_ms(15);
#define d45 _delay_ms(4);_delay_us(240);_delay_us(240);
#define d25 _delay_ms(2);_delay_us(240);_delay_us(240);
#define du150 _delay_us(150);
#define du250 _delay_us(250);
#define du40 _delay_us(40);

void wtp(uint8_t d){
  uint8_t wtp_mask=0;
  	wtp_mask |= _BV(myLCD_D4);
        wtp_mask |= _BV(myLCD_D5);
        wtp_mask |= _BV(myLCD_D6);
        wtp_mask |= _BV(myLCD_D7);
  if (d&0b00010000) {P|=_BV(myLCD_D4);} else {P&=~_BV(myLCD_D4);}
  if (d&0b00100000) {P|=_BV(myLCD_D5);} else {P&=~_BV(myLCD_D5);}
  if (d&0b01000000) {P|=_BV(myLCD_D6);} else {P&=~_BV(myLCD_D6);}
  if (d&0b10000000) {P|=_BV(myLCD_D7);} else {P&=~_BV(myLCD_D7);}
}

void myLCD_Init(){
  
        myLCD_CON_DDR |= _BV(myLCD_RS);
	myLCD_CON_DDR |= _BV(myLCD_E); //control ports is out
	myLCD_PORT_DDR |= _BV(myLCD_D4);
        myLCD_PORT_DDR |= _BV(myLCD_D5);
        myLCD_PORT_DDR |= _BV(myLCD_D6);
        myLCD_PORT_DDR |= _BV(myLCD_D7);//data port D7-D4 is on out
        d15
                
        wtp(0b00100000); EN d45 //2
        wtp(0b00100000); EN d45 //3
        wtp(0);  EN du250
        wtp(0);  EN du250 //4
        wtp(0b11100000); EN du150
        wtp(0); EN du150 //5
        wtp(0b01100000); EN du150
   

}       



void myLCD_Put(uint8_t ch){
  
  RU
  wtp(ch);
  EN du40
  wtp(ch<<4);       
  EN du40 
  RD
  d45
}

void myLCD_CLR(){
  RD
  wtp(0b0);EN du40
  wtp(0b00010000);EN du40

}
void myLCD_CR(){
  RD
  wtp(0b0);EN du40
  wtp(0b00110000);EN du40

}

void myLCD_INC(){
  RD
  wtp(0b10000000);EN du40
  wtp(0b00010000);EN du40
  
}

void myLCD_GotoXY(uint8_t x,uint8_t y){
  uint8_t tmp;
  if (y!=0) x+=40;
  tmp=x; 
  tmp|=_BV(7);
  wtp(tmp);
  EN du40
  wtp(tmp<<4);       
  EN d45 
}


void myLCD_SLEEP(uint8_t t){
  for (uint8_t i=0;i<t;i++){
    _delay_ms(250);_delay_ms(250);_delay_ms(250);_delay_ms(250);
    }
  }

void myLCD_mSLEEP(uint8_t t){    
for (uint8_t i=0;i<t;i++){
    _delay_ms(10);
    } }

void myLCD_PRINT(uint8_t *str){
  uint8_t i =0;
  while (str[i]!='\n'){
  myLCD_Put(str[i]);
    i++;}
}