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
  /* IO_COM */
  CUSTOM_STM_TX_OUT,
  CUSTOM_STM_RX_IN,
  /* Human_Interface_Device */
  CUSTOM_STM_RMAP,
  CUSTOM_STM_REP,
  CUSTOM_STM_INF,
  CUSTOM_STM_CP,
  /* Device_information */
  CUSTOM_STM_MNF,
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
  CUSTOM_STM_RMAP_READ_EVT,
  /* Report */
  CUSTOM_STM_REP_READ_EVT,
  CUSTOM_STM_REP_WRITE_EVT,
  CUSTOM_STM_REP_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_REP_NOTIFY_DISABLED_EVT,
  /* HID_Information */
  CUSTOM_STM_INF_READ_EVT,
  /* HID_Control_Point */
  CUSTOM_STM_CP_WRITE_NO_RESP_EVT,
  /* Manufacturer_Name_String */
  CUSTOM_STM_MNF_READ_EVT,
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

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
extern uint16_t SizeTx_Out;
extern uint16_t SizeRx_In;
extern uint16_t SizeRmap;
extern uint16_t SizeRep;
extern uint16_t SizeInf;
extern uint16_t SizeCp;
extern uint16_t SizeMnf;
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
