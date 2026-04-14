#include "BLE_services_custom.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "usbd_cdc_if.h"
#include "main.h"
/******************************************************************************/
/******************************* DEFINITIONS **********************************/



/****************************** FUNCTIONS DEF**********************************/

/******************************* FUNCTIONS ************************************/
void BLE_USB_compromiss_init(void){
    LL_HSEM_1StepLock(HSEM, 5); //deny change HSEM by ble Nessesary!!!
    //HSI48 stable (work better)
    __HAL_RCC_CRS_CLK_ENABLE();
    RCC_CRSInitTypeDef crsInit = {0};
    crsInit.Prescaler = RCC_CRS_SYNC_DIV1;
    crsInit.Source = RCC_CRS_SYNC_SOURCE_USB; // 
    crsInit.ReloadValue = __HAL_RCC_CRS_RELOADVALUE_CALCULATE(48000000, 1000);
    crsInit.ErrorLimitValue = 34;
    crsInit.HSI48CalibrationValue = 32;
    HAL_RCCEx_CRSConfig(&crsInit);
}


void BLE_rx_data(uint8_t* data, uint32_t size){
    Custom_STM_App_Update_Char_Variable_Length(CUSTOM_STM_TX_OUT, data,size) ;
    CDC_Transmit_FS((uint8_t*)data, size);
}

/**
* @}
*/






