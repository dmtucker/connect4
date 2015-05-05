/*******************************************************************************
* File Name: transmitter.h  
* Version 1.80
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

#if !defined(CY_PINS_transmitter_H) /* Pins transmitter_H */
#define CY_PINS_transmitter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "transmitter_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 transmitter__PORT == 15 && ((transmitter__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    transmitter_Write(uint8 value) ;
void    transmitter_SetDriveMode(uint8 mode) ;
uint8   transmitter_ReadDataReg(void) ;
uint8   transmitter_Read(void) ;
uint8   transmitter_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define transmitter_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define transmitter_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define transmitter_DM_RES_UP          PIN_DM_RES_UP
#define transmitter_DM_RES_DWN         PIN_DM_RES_DWN
#define transmitter_DM_OD_LO           PIN_DM_OD_LO
#define transmitter_DM_OD_HI           PIN_DM_OD_HI
#define transmitter_DM_STRONG          PIN_DM_STRONG
#define transmitter_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define transmitter_MASK               transmitter__MASK
#define transmitter_SHIFT              transmitter__SHIFT
#define transmitter_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define transmitter_PS                     (* (reg8 *) transmitter__PS)
/* Data Register */
#define transmitter_DR                     (* (reg8 *) transmitter__DR)
/* Port Number */
#define transmitter_PRT_NUM                (* (reg8 *) transmitter__PRT) 
/* Connect to Analog Globals */                                                  
#define transmitter_AG                     (* (reg8 *) transmitter__AG)                       
/* Analog MUX bux enable */
#define transmitter_AMUX                   (* (reg8 *) transmitter__AMUX) 
/* Bidirectional Enable */                                                        
#define transmitter_BIE                    (* (reg8 *) transmitter__BIE)
/* Bit-mask for Aliased Register Access */
#define transmitter_BIT_MASK               (* (reg8 *) transmitter__BIT_MASK)
/* Bypass Enable */
#define transmitter_BYP                    (* (reg8 *) transmitter__BYP)
/* Port wide control signals */                                                   
#define transmitter_CTL                    (* (reg8 *) transmitter__CTL)
/* Drive Modes */
#define transmitter_DM0                    (* (reg8 *) transmitter__DM0) 
#define transmitter_DM1                    (* (reg8 *) transmitter__DM1)
#define transmitter_DM2                    (* (reg8 *) transmitter__DM2) 
/* Input Buffer Disable Override */
#define transmitter_INP_DIS                (* (reg8 *) transmitter__INP_DIS)
/* LCD Common or Segment Drive */
#define transmitter_LCD_COM_SEG            (* (reg8 *) transmitter__LCD_COM_SEG)
/* Enable Segment LCD */
#define transmitter_LCD_EN                 (* (reg8 *) transmitter__LCD_EN)
/* Slew Rate Control */
#define transmitter_SLW                    (* (reg8 *) transmitter__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define transmitter_PRTDSI__CAPS_SEL       (* (reg8 *) transmitter__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define transmitter_PRTDSI__DBL_SYNC_IN    (* (reg8 *) transmitter__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define transmitter_PRTDSI__OE_SEL0        (* (reg8 *) transmitter__PRTDSI__OE_SEL0) 
#define transmitter_PRTDSI__OE_SEL1        (* (reg8 *) transmitter__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define transmitter_PRTDSI__OUT_SEL0       (* (reg8 *) transmitter__PRTDSI__OUT_SEL0) 
#define transmitter_PRTDSI__OUT_SEL1       (* (reg8 *) transmitter__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define transmitter_PRTDSI__SYNC_OUT       (* (reg8 *) transmitter__PRTDSI__SYNC_OUT) 


#if defined(transmitter__INTSTAT)  /* Interrupt Registers */

    #define transmitter_INTSTAT                (* (reg8 *) transmitter__INTSTAT)
    #define transmitter_SNAP                   (* (reg8 *) transmitter__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_transmitter_H */


/* [] END OF FILE */
