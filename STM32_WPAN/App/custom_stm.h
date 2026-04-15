/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_stm.h
  * @author  MCD Application Team
  * @brief   Header for custom_stm.c module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUSTOM_STM_H
#define CUSTOM_STM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ble_types.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  /* Virtual_com */
  CUSTOM_STM_TX_OUT,
  CUSTOM_STM_RX_IN,
  /* Human_Interface_Device */
  CUSTOM_STM_RX,
  CUSTOM_STM_REP,
  /* Device_information */
  CUSTOM_STM_PNP,
  /* Battery_settings */
  CUSTOM_STM_BAT,
} Custom_STM_Char_Opcode_t;

typedef enum
{
  /* Transmit_to_phone */
  CUSTOM_STM_TX_OUT_READ_EVT,
  CUSTOM_STM_TX_OUT_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_TX_OUT_NOTIFY_DISABLED_EVT,
  /* Receive_from_phone */
  CUSTOM_STM_RX_IN_WRITE_NO_RESP_EVT,
  /* Report_map */
  CUSTOM_STM_RX_READ_EVT,
  /* Report */
  CUSTOM_STM_REP_READ_EVT,
  CUSTOM_STM_REP_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_REP_NOTIFY_DISABLED_EVT,
  /* PnP */
  /* Battery_Level */
  CUSTOM_STM_BAT_READ_EVT,
  CUSTOM_STM_BAT_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_BAT_NOTIFY_DISABLED_EVT,
  CUSTOM_STM_NOTIFICATION_COMPLETE_EVT,

  CUSTOM_STM_BOOT_REQUEST_EVT
} Custom_STM_Opcode_evt_t;

typedef struct
{
  uint8_t * pPayload;
  uint8_t   Length;
} Custom_STM_Data_t;

typedef struct
{
  Custom_STM_Opcode_evt_t       Custom_Evt_Opcode;
  Custom_STM_Data_t             DataTransfered;
  uint16_t                      ConnectionHandle;
  uint8_t                       ServiceInstance;
  uint16_t                      AttrHandle;
} Custom_STM_App_Notification_evt_t;

/* USER CODE BEGIN ET */
///@TODO Joy HID DESC
#define HID_JOYSTICK_REPORT_DESC_SIZE              44U    

static uint8_t HID_JOYSTICK_ReportDesc[HID_JOYSTICK_REPORT_DESC_SIZE]  =
{
     0x05, 0x01, // USAGE_PAGE (Generic Desktop)
 0x09, 0x04,   // USAGE (Game Pad)
 0xa1, 0x01,   // COLLECTION (Application)
 0x09, 0x01,   //   USAGE (Pointer)
 0xa1, 0x00,   //   COLLECTION (Physical)
 0x09, 0x30,   //    USAGE (X)
 0x09, 0x31,   //    USAGE (Y)
 //0x09, 0x33,   //    USAGE (Rx)
 //0x09, 0x34,   //    USAGE (RY)
 0x16, 0x18, 0xfc,   //    LOGICAL_MINIMUM (-1000)//0x16, 0x01, 0xf8,   //    LOGICAL_MINIMUM (-2047)
 0x26, 0xe8, 0x03,   //    LOGICAL_MAXIMUM (1000)//0x26, 0xff, 0x07,   //    LOGICAL_MAXIMUM (2047)
 0x75, 0x10,   //    REPORT_SIZE (16)
 0x95, 0x02,   //    REPORT_COUNT (2)
 0x81, 0x02,   //    INPUT (Data,Var,Abs)
 0xc0,         //   END_COLLECTION
 0x05, 0x09,   //   USAGE_PAGE (Button)
 0x19, 0x01,   //   USAGE_MINIMUM (Button 1)
 0x29, 0x08,   //   USAGE_MAXIMUM (Button 8)
 0x15, 0x00,   //   LOGICAL_MINIMUM (0)
 0x25, 0x01,   //   LOGICAL_MAXIMUM (1)
 0x75, 0x01,   //   REPORT_SIZE (1)
 0x95, 0x08,   //   REPORT_COUNT (8)
 0x81, 0x02,   //   INPUT (Data,Var,Abs)
 0xc0 //          END_COLLECTION
};

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
extern uint16_t SizeTx_Out;
extern uint16_t SizeRx_In;
extern uint16_t SizeRx;
extern uint16_t SizeRep;
extern uint16_t SizePnp;
extern uint16_t SizeBat;

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macros -----------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions ------------------------------------------------------- */
void SVCCTL_InitCustomSvc(void);
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification);
tBleStatus Custom_STM_App_Update_Char(Custom_STM_Char_Opcode_t CharOpcode,  uint8_t *pPayload);
tBleStatus Custom_STM_App_Update_Char_Variable_Length(Custom_STM_Char_Opcode_t CharOpcode, uint8_t *pPayload, uint8_t size);
tBleStatus Custom_STM_App_Update_Char_Ext(uint16_t Connection_Handle, Custom_STM_Char_Opcode_t CharOpcode, uint8_t *pPayload);
/* USER CODE BEGIN EF */

/* USER CODE END EF */

#ifdef __cplusplus
}
#endif

#endif /*CUSTOM_STM_H */
