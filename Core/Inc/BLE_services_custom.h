#ifndef BLE_SERVICES_CUSTOM_H
#define BLE_SERVICES_CUSTOM_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stdlib.h"
#include "stdint.h"
  
void BLE_USB_compromiss_init(void);    
    
void BLE_rx_data(uint8_t* data, uint32_t size);
    
    
    
    

#ifdef __cplusplus
}
#endif

#endif

/**********END OF FILE****/ 