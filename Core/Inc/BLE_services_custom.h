#ifndef BLE_SERVICES_CUSTOM_H
#define BLE_SERVICES_CUSTOM_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stdlib.h"
#include "stdint.h"
  
void BLE_USB_compromiss_init(void);    
    
void BLE_rx_data(uint8_t* data, uint32_t size);
    
    
void BLE_Send_Joystick_Test(void);
    void BLE_Joystick_Send_State(int16_t x, int16_t y, uint8_t buttons) ;

#ifdef __cplusplus
}
#endif

#endif

/**********END OF FILE****/ 