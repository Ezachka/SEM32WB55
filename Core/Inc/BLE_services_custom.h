#ifndef BLE_SERVICES_CUSTOM_H
#define BLE_SERVICES_CUSTOM_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stdlib.h"
#include "stdint.h"
    //init
    void BLE_USB_compromiss_init(void);    
    //virtual com
    void BLE_tx_update(void);
    void BLE_rx_data(uint8_t* data, uint32_t size);
    void BLE_tx_data(uint8_t* data, uint32_t size);
    //HID joy
    #pragma pack(push, 1)
    typedef struct {
   //     uint8_t reportId;
        int16_t x;
        int16_t y;
        uint8_t btn;
    } joy_report_t;
    #pragma pack(pop) 

    void BLE_Send_Joystick_Test(void);
    void BLE_Joystick_Send_State(int16_t x, int16_t y, uint8_t buttons) ;
    
#ifdef __cplusplus
}
#endif

#endif

/**********END OF FILE****/ 