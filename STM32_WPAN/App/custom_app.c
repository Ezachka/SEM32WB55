/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_app.c
  * @author  MCD Application Team
  * @brief   Custom Example Application (Server)
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_common.h"
#include "dbg_trace.h"
#include "ble.h"
#include "custom_app.h"
#include "custom_stm.h"
#include "stm32_seq.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "BLE_services_custom.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  /* Virtual_com */
  uint8_t               Tx_out_Notification_Status;
  /* Human_Interface_Device */
  uint8_t               Rep_Notification_Status;
  /* Device_information */
  /* Battery_settings */
  uint8_t               Bat_Notification_Status;
  /* USER CODE BEGIN CUSTOM_APP_Context_t */

  /* USER CODE END CUSTOM_APP_Context_t */

  uint16_t              ConnectionHandle;
} Custom_App_Context_t;

/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private defines ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macros -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/**
 * START of Section BLE_APP_CONTEXT
 */

static Custom_App_Context_t Custom_App_Context;

/**
 * END of Section BLE_APP_CONTEXT
 */

uint8_t UpdateCharData[512];
uint8_t NotifyCharData[512];
uint16_t Connection_Handle;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* Virtual_com */
static void Custom_Tx_out_Update_Char(void);
static void Custom_Tx_out_Send_Notification(void);
/* Human_Interface_Device */
static void Custom_Rep_Update_Char(void);
static void Custom_Rep_Send_Notification(void);
/* Device_information */
/* Battery_settings */
static void Custom_Bat_Update_Char(void);
static void Custom_Bat_Send_Notification(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Functions Definition ------------------------------------------------------*/
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_1 */
    
  /* USER CODE END CUSTOM_STM_App_Notification_1 */
  switch (pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* USER CODE END CUSTOM_STM_App_Notification_Custom_Evt_Opcode */

    /* Virtual_com */
    case CUSTOM_STM_TX_OUT_READ_EVT:
      /* USER CODE BEGIN CUSTOM_STM_TX_OUT_READ_EVT */

      /* USER CODE END CUSTOM_STM_TX_OUT_READ_EVT */
      break;

    case CUSTOM_STM_TX_OUT_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_TX_OUT_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_TX_OUT_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_TX_OUT_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_TX_OUT_NOTIFY_DISABLED_EVT */
      
      /* USER CODE END CUSTOM_STM_TX_OUT_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_RX_IN_WRITE_NO_RESP_EVT:
      /* USER CODE BEGIN CUSTOM_STM_RX_IN_WRITE_NO_RESP_EVT */
      uint8_t *payload = pNotification->DataTransfered.pPayload;
      
      uint8_t len = pNotification->DataTransfered.Length;
      BLE_rx_data(payload,  len);
      
      /* USER CODE END CUSTOM_STM_RX_IN_WRITE_NO_RESP_EVT */
      break;

    /* Human_Interface_Device */
    case CUSTOM_STM_RX_READ_EVT:
      /* USER CODE BEGIN CUSTOM_STM_RX_READ_EVT */

      /* USER CODE END CUSTOM_STM_RX_READ_EVT */
      break;

    case CUSTOM_STM_REP_READ_EVT:
      /* USER CODE BEGIN CUSTOM_STM_REP_READ_EVT */

      /* USER CODE END CUSTOM_STM_REP_READ_EVT */
      break;

    case CUSTOM_STM_REP_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_REP_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_REP_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_REP_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_REP_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_REP_NOTIFY_DISABLED_EVT */
      break;

    /* Device_information */
    /* Battery_settings */
    case CUSTOM_STM_BAT_READ_EVT:
      /* USER CODE BEGIN CUSTOM_STM_BAT_READ_EVT */

      /* USER CODE END CUSTOM_STM_BAT_READ_EVT */
      break;

    case CUSTOM_STM_BAT_NOTIFY_ENABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_BAT_NOTIFY_ENABLED_EVT */

      /* USER CODE END CUSTOM_STM_BAT_NOTIFY_ENABLED_EVT */
      break;

    case CUSTOM_STM_BAT_NOTIFY_DISABLED_EVT:
      /* USER CODE BEGIN CUSTOM_STM_BAT_NOTIFY_DISABLED_EVT */

      /* USER CODE END CUSTOM_STM_BAT_NOTIFY_DISABLED_EVT */
      break;

    case CUSTOM_STM_NOTIFICATION_COMPLETE_EVT:
      /* USER CODE BEGIN CUSTOM_STM_NOTIFICATION_COMPLETE_EVT */

      /* USER CODE END CUSTOM_STM_NOTIFICATION_COMPLETE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_STM_App_Notification_default */

      /* USER CODE END CUSTOM_STM_App_Notification_default */
      break;
  }
  /* USER CODE BEGIN CUSTOM_STM_App_Notification_2 */

  /* USER CODE END CUSTOM_STM_App_Notification_2 */
  return;
}

void Custom_APP_Notification(Custom_App_ConnHandle_Not_evt_t *pNotification)
{
  /* USER CODE BEGIN CUSTOM_APP_Notification_1 */
    
  /* USER CODE END CUSTOM_APP_Notification_1 */

  switch (pNotification->Custom_Evt_Opcode)
  {
    /* USER CODE BEGIN CUSTOM_APP_Notification_Custom_Evt_Opcode */

    /* USER CODE END P2PS_CUSTOM_Notification_Custom_Evt_Opcode */
    case CUSTOM_CONN_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_CONN_HANDLE_EVT */
        
      /* USER CODE END CUSTOM_CONN_HANDLE_EVT */
      break;

    case CUSTOM_DISCON_HANDLE_EVT :
      /* USER CODE BEGIN CUSTOM_DISCON_HANDLE_EVT */

      /* USER CODE END CUSTOM_DISCON_HANDLE_EVT */
      break;

    default:
      /* USER CODE BEGIN CUSTOM_APP_Notification_default */

      /* USER CODE END CUSTOM_APP_Notification_default */
      break;
  }

  /* USER CODE BEGIN CUSTOM_APP_Notification_2 */

  /* USER CODE END CUSTOM_APP_Notification_2 */

  return;
}

void Custom_APP_Init(void)
{
  /* USER CODE BEGIN CUSTOM_APP_Init */

  /* USER CODE END CUSTOM_APP_Init */
  return;
}

/* USER CODE BEGIN FD */

/* USER CODE END FD */

/*************************************************************
 *
 * LOCAL FUNCTIONS
 *
 *************************************************************/

/* Virtual_com */
__USED void Custom_Tx_out_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Tx_out_UC_1*/

  /* USER CODE END Tx_out_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_TX_OUT, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN Tx_out_UC_Last*/

  /* USER CODE END Tx_out_UC_Last*/
  return;
}

void Custom_Tx_out_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Tx_out_NS_1*/

  /* USER CODE END Tx_out_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_TX_OUT, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN Tx_out_NS_Last*/

  /* USER CODE END Tx_out_NS_Last*/

  return;
}

/* Human_Interface_Device */
__USED void Custom_Rep_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Rep_UC_1*/

  /* USER CODE END Rep_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_REP, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN Rep_UC_Last*/

  /* USER CODE END Rep_UC_Last*/
  return;
}

void Custom_Rep_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Rep_NS_1*/

  /* USER CODE END Rep_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_REP, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN Rep_NS_Last*/

  /* USER CODE END Rep_NS_Last*/

  return;
}

/* Device_information */
/* Battery_settings */
__USED void Custom_Bat_Update_Char(void) /* Property Read */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Bat_UC_1*/

  /* USER CODE END Bat_UC_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_BAT, (uint8_t *)UpdateCharData);
  }

  /* USER CODE BEGIN Bat_UC_Last*/

  /* USER CODE END Bat_UC_Last*/
  return;
}

void Custom_Bat_Send_Notification(void) /* Property Notification */
{
  uint8_t updateflag = 0;

  /* USER CODE BEGIN Bat_NS_1*/

  /* USER CODE END Bat_NS_1*/

  if (updateflag != 0)
  {
    Custom_STM_App_Update_Char(CUSTOM_STM_BAT, (uint8_t *)NotifyCharData);
  }

  /* USER CODE BEGIN Bat_NS_Last*/

  /* USER CODE END Bat_NS_Last*/

  return;
}

/* USER CODE BEGIN FD_LOCAL_FUNCTIONS*/

/* USER CODE END FD_LOCAL_FUNCTIONS*/
