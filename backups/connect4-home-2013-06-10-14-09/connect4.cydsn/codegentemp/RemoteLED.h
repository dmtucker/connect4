/*******************************************************************************
* File Name: RemoteLED.h  
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

#if !defined(CY_PINS_RemoteLED_H) /* Pins RemoteLED_H */
#define CY_PINS_RemoteLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RemoteLED_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RemoteLED__PORT == 15 && ((RemoteLED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RemoteLED_Write(uint8 value) ;
void    RemoteLED_SetDriveMode(uint8 mode) ;
uint8   RemoteLED_ReadDataReg(void) ;
uint8   RemoteLED_Read(void) ;
uint8   RemoteLED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RemoteLED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RemoteLED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RemoteLED_DM_RES_UP          PIN_DM_RES_UP
#define RemoteLED_DM_RES_DWN         PIN_DM_RES_DWN
#define RemoteLED_DM_OD_LO           PIN_DM_OD_LO
#define RemoteLED_DM_OD_HI           PIN_DM_OD_HI
#define RemoteLED_DM_STRONG          PIN_DM_STRONG
#define RemoteLED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RemoteLED_MASK               RemoteLED__MASK
#define RemoteLED_SHIFT              RemoteLED__SHIFT
#define RemoteLED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RemoteLED_PS                     (* (reg8 *) RemoteLED__PS)
/* Data Register */
#define RemoteLED_DR                     (* (reg8 *) RemoteLED__DR)
/* Port Number */
#define RemoteLED_PRT_NUM                (* (reg8 *) RemoteLED__PRT) 
/* Connect to Analog Globals */                                                  
#define RemoteLED_AG                     (* (reg8 *) RemoteLED__AG)                       
/* Analog MUX bux enable */
#define RemoteLED_AMUX                   (* (reg8 *) RemoteLED__AMUX) 
/* Bidirectional Enable */                                                        
#define RemoteLED_BIE                    (* (reg8 *) RemoteLED__BIE)
/* Bit-mask for Aliased Register Access */
#define RemoteLED_BIT_MASK               (* (reg8 *) RemoteLED__BIT_MASK)
/* Bypass Enable */
#define RemoteLED_BYP                    (* (reg8 *) RemoteLED__BYP)
/* Port wide control signals */                                                   
#define RemoteLED_CTL                    (* (reg8 *) RemoteLED__CTL)
/* Drive Modes */
#define RemoteLED_DM0                    (* (reg8 *) RemoteLED__DM0) 
#define RemoteLED_DM1                    (* (reg8 *) RemoteLED__DM1)
#define RemoteLED_DM2                    (* (reg8 *) RemoteLED__DM2) 
/* Input Buffer Disable Override */
#define RemoteLED_INP_DIS                (* (reg8 *) RemoteLED__INP_DIS)
/* LCD Common or Segment Drive */
#define RemoteLED_LCD_COM_SEG            (* (reg8 *) RemoteLED__LCD_COM_SEG)
/* Enable Segment LCD */
#define RemoteLED_LCD_EN                 (* (reg8 *) RemoteLED__LCD_EN)
/* Slew Rate Control */
#define RemoteLED_SLW                    (* (reg8 *) RemoteLED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RemoteLED_PRTDSI__CAPS_SEL       (* (reg8 *) RemoteLED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RemoteLED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RemoteLED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RemoteLED_PRTDSI__OE_SEL0        (* (reg8 *) RemoteLED__PRTDSI__OE_SEL0) 
#define RemoteLED_PRTDSI__OE_SEL1        (* (reg8 *) RemoteLED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RemoteLED_PRTDSI__OUT_SEL0       (* (reg8 *) RemoteLED__PRTDSI__OUT_SEL0) 
#define RemoteLED_PRTDSI__OUT_SEL1       (* (reg8 *) RemoteLED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RemoteLED_PRTDSI__SYNC_OUT       (* (reg8 *) RemoteLED__PRTDSI__SYNC_OUT) 


#if defined(RemoteLED__INTSTAT)  /* Interrupt Registers */

    #define RemoteLED_INTSTAT                (* (reg8 *) RemoteLED__INTSTAT)
    #define RemoteLED_SNAP                   (* (reg8 *) RemoteLED__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RemoteLED_H */


/* [] END OF FILE */
