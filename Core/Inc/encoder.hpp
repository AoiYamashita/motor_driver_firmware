#ifndef ENCODER_H
#define ENCODER_H

#include <main.h>


class Encoder{
    private:
    int rpp;
    bool A_state;// true : SET, false : RESET
    bool B_state;// true : SET, false : RESET
    bool Z_state;// true : SET, false : RESET
    GPIO_TypeDef* Aport;
    uint16_t Apin;
    GPIO_TypeDef* Bport;
    uint16_t Bpin;
    GPIO_TypeDef* Zport;
    uint16_t Zpin;
    int count;
    int cycle_count;
    bool useZ;
    uint16_t degree;
    uint16_t rpm;
    public:
    //not use Z pin
    Encoder(GPIO_TypeDef* Aport, uint16_t Apin,GPIO_TypeDef* Bport, uint16_t Bpin,int rpp);
    //use Z pin
    Encoder(GPIO_TypeDef* Aport, uint16_t Apin,GPIO_TypeDef* Bport, uint16_t Bpin,GPIO_TypeDef* Zport, uint16_t Zpin,int rpp);
    void PinCallBack(uint16_t pin);
    void TimCallBack();//1kHz 1ms
    int get_rpm();
    int get_degree();
};

#endif