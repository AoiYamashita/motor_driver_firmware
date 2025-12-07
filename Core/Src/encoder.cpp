#include "encoder.hpp"

Encoder::Encoder(GPIO_TypeDef* Aport, uint16_t Apin,GPIO_TypeDef* Bport, uint16_t Bpin,int rpp):
    rpp{rpp},A_state{false},B_state{false},Z_state{false},count{0},cycle_count{0},degree{0},rpm{0},
    Aport{Aport},Apin{Apin},Bport{Bport},Bpin{Bpin},useZ{false}{
    }

Encoder::Encoder(GPIO_TypeDef* Aport, uint16_t Apin,GPIO_TypeDef* Bport, uint16_t Bpin,GPIO_TypeDef* Zport, uint16_t Zpin,int rpp):
    rpp{rpp},A_state{false},B_state{false},Z_state{false},count{0},cycle_count{0},degree{0},rpm{0},
    Aport{Aport},Apin{Apin},Bport{Bport},Bpin{Bpin},Zport{Zport},Zpin{Zpin},useZ{true}{
    }

void Encoder::PinCallBack(uint16_t pin){
    if(pin == Apin){
        A_state = HAL_GPIO_ReadPin(Aport, Apin);
        count += (B_state==A_state) ? -1 : 1;
        cycle_count += (B_state==A_state) ? -1 : 1;
    }
    if(pin == Bpin){
        B_state = HAL_GPIO_ReadPin(Bport, Bpin);
        count += (B_state==A_state) ? 1 : -1;
        cycle_count += (B_state==A_state) ? 1 : -1;
    }
    if(!useZ)return;
    if(pin == Zpin){
        if(HAL_GPIO_ReadPin(Zport, Zpin))cycle_count = 0;
    }
}

void Encoder::TimCallBack(){//1kHz 1ms
    rpm = 60.0*1000.0*count/(2.0*rpp);
    degree = 180*cycle_count/rpp;
    count = 0;
}

int Encoder::get_rpm(){return rpm;};
int Encoder::get_degree(){return degree;};