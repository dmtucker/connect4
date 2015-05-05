/*******************************************************************************
* File Name: Connector.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Connector_H) /* Pins Connector_H */
#define CY_PINS_Connector_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Connector_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Connector__PORT == 15 && ((Connector__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Connector_Write(uint8 value) ;
void    Connector_SetDriveMode(uint8 mode) ;
uint8   Connector_ReadDataReg(void) ;
uint8   Connector_Read(void) ;
uint8   Connector_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Connector_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Connector_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Connector_DM_RES_UP          PIN_DM_RES_UP
#define Connector_DM_RES_DWN         PIN_DM_RES_DWN
#define Connector_DM_OD_LO           PIN_DM_OD_LO
#define Connector_DM_OD_HI           PIN_DM_OD_HI
#define Connector_DM_STRONG          PIN_DM_STRONG
#define Connector_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Connector_MASK               Connector__MASK
#define Connector_SHIFT              Connector__SHIFT
#define Connector_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Connector_PS                     (* (reg8 *) Connector__PS)
/* Data Register */
#define Connector_DR                     (* (reg8 *) Connector__DR)
/* Port Number */
#define Connector_PRT_NUM                (* (reg8 *) Connector__PRT) 
/* Connect to Analog Globals */                                                  
#define Connector_AG                     (* (reg8 *) Connector__AG)                       
/* Analog MUX bux enable */
#define Connector_AMUX                   (* (reg8 *) Connector__AMUX) 
/* Bidirectional Enable */                                                        
#define Connector_BIE                    (* (reg8 *) Connector__BIE)
/* Bit-mask for Aliased Register Access */
#define Connector_BIT_MASK               (* (reg8 *) Connector__BIT_MASK)
/* Bypass Enable */
#define Connector_BYP                    (* (reg8 *) Connector__BYP)
/* Port wide control signals */                                                   
#define Connector_CTL                    (* (reg8 *) Connector__CTL)
/* Drive Modes */
#define Connector_DM0                    (* (reg8 *) Connector__DM0) 
#define Connector_DM1                    (* (reg8 *) Connector__DM1)
#define Connector_DM2                    (* (reg8 *) Connector__DM2) 
/* Input Buffer Disable Override */
#define Connector_INP_DIS                (* (reg8 *) Connector__INP_DIS)
/* LCD Common or Segment Drive */
#define Connector_LCD_COM_SEG            (* (reg8 *) Connector__LCD_COM_SEG)
/* Enable Segment LCD */
#define Connector_LCD_EN                 (* (reg8 *) Connector__LCD_EN)
/* Slew Rate Control */
#define Connector_SLW                    (* (reg8 *) Connector__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Connector_PRTDSI__CAPS_SEL       (* (reg8 *) Connector__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Connector_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Connector__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Connector_PRTDSI__OE_SEL0        (* (reg8 *) Connector__PRTDSI__OE_SEL0) 
#define Connector_PRTDSI__OE_SEL1        (* (reg8 *) Connector__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Connector_PRTDSI__OUT_SEL0       (* (reg8 *) Connector__PRTDSI__OUT_SEL0) 
#define Connector_PRTDSI__OUT_SEL1       (* (reg8 *) Connector__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Connector_PRTDSI__SYNC_OUT       (* (reg8 *) Connector__PRTDSI__SYNC_OUT) 


#if defined(Connector__INTSTAT)  /* Interrupt Registers */

    #define Connector_INTSTAT                (* (reg8 *) Connector__INTSTAT)
    #define Connector_SNAP                   (* (reg8 *) Connector__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Connector_H */


/* [] END OF FILE */
