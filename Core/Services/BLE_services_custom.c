#include "BLE_services_custom.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "usbd_cdc_if.h"
#include "main.h"
#include "stdbool.h"
/******************************************************************************/
/******************************* DEFINITIONS **********************************/
struct{
    uint8_t buff[256];
    uint16_t size_to_sent;
    bool ready;
}buf_ble_tx;
struct{
    uint8_t buff[256];
    uint16_t size_receive;
    bool ready;
}buf_ble_rx;


joy_report_t joy_report;
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

/******************************* COM PORT ************************************/

void BLE_tx_update(void){
    if (buf_ble_tx.ready){
        Custom_STM_App_Update_Char_Variable_Length(CUSTOM_STM_TX_OUT, buf_ble_tx.buff,buf_ble_tx.size_to_sent) ;
        buf_ble_tx.ready=false;
    }
    if (buf_ble_rx.ready){
        CDC_Transmit_FS(buf_ble_rx.buff, buf_ble_rx.size_receive);
        buf_ble_rx.ready=false;
    }
}
void BLE_rx_data(uint8_t* data, uint32_t size){
    memset(buf_ble_rx.buff,0x00,sizeof(buf_ble_rx.buff));
    memcpy(buf_ble_rx.buff,data,size);
    buf_ble_rx.size_receive=size;
    buf_ble_rx.ready=true;
    //    CDC_Transmit_FS((uint8_t*)data, size);
}

void BLE_tx_data(uint8_t* data, uint32_t size){
    memset(buf_ble_tx.buff,0x00,sizeof(buf_ble_tx.buff));
    memcpy(buf_ble_tx.buff,data,size);
    buf_ble_tx.size_to_sent=size;
    buf_ble_tx.ready=true;
    //   Custom_STM_App_Update_Char_Variable_Length(CUSTOM_STM_TX_OUT, data,size) ;
}


/******************************* HID JOY ************************************/
void BLE_Joystick_Send_State(int16_t x, int16_t y, uint8_t buttons) {
    //joy_report.reportId = 0x01;
    joy_report.x = x;
    joy_report.y = y;
    joy_report.btn = buttons;
    Custom_STM_App_Update_Char(CUSTOM_STM_REP, (uint8_t*)&joy_report);
}


/**
* @}
*/






