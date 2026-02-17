#include "encoder.hpp"

Encoder::Encoder(GPIO_TypeDef* Aport, uint16_t Apin,GPIO_TypeDef* Bport, uint16_t Bpin,int rpp):
    rpp{rpp},A_state{false},B_state{false},Z_state{false},count{0},cycle_count{0},degree{0},rpm{0},
    Aport{Aport},Apin{Apin},Bport{Bport},Bpin{Bpin},useZ{false},tim_callback_cunter{0}{
    }

Encoder::Encoder(GPIO_TypeDef* Aport, uint16_t Apin,GPIO_TypeDef* Bport, uint16_t Bpin,GPIO_TypeDef* Zport, uint16_t Zpin,int rpp):
    rpp{rpp},A_state{false},B_state{false},Z_state{false},count{0},cycle_count{0},degree{0},rpm{0},
    Aport{Aport},Apin{Apin},Bport{Bport},Bpin{Bpin},Zport{Zport},Zpin{Zpin},useZ{true},tim_callback_cunter{0}{
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

void Encoder::TimCallBack(){//1Hz 1ms
    tim_callback_cunter++;
    degree = 180*cycle_count/rpp;
    if(tim_callback_cunter%10 == 0){
        float hoge = 60.0*1000.0*float(count/float(10.0*4.0*rpp));
        rpm = hoge;
        count = 0;
        tim_callback_cunter=0;
    }
}

int Encoder::get_rpm(){return rpm;};
int Encoder::get_degree(){return degree;};