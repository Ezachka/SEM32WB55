#include "BLE_services_custom.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "usbd_cdc_if.h"
/******************************************************************************/
/******************************* DEFINITIONS **********************************/



/****************************** FUNCTIONS DEF**********************************/

/******************************* FUNCTIONS ************************************/

void BLE_rx_data(uint8_t* data, uint32_t size){
     Custom_STM_App_Update_Char(CUSTOM_STM_TX_OUT, data);
     CDC_Transmit_FS((uint8_t*)data, size);
}

/**
* @}
*/






