/*******************************************************************************
* File Name: Column.h  
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

#if !defined(CY_PINS_Column_H) /* Pins Column_H */
#define CY_PINS_Column_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Column_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Column__PORT == 15 && ((Column__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Column_Write(uint8 value) ;
void    Column_SetDriveMode(uint8 mode) ;
uint8   Column_ReadDataReg(void) ;
uint8   Column_Read(void) ;
uint8   Column_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Column_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Column_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Column_DM_RES_UP          PIN_DM_RES_UP
#define Column_DM_RES_DWN         PIN_DM_RES_DWN
#define Column_DM_OD_LO           PIN_DM_OD_LO
#define Column_DM_OD_HI           PIN_DM_OD_HI
#define Column_DM_STRONG          PIN_DM_STRONG
#define Column_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Column_MASK               Column__MASK
#define Column_SHIFT              Column__SHIFT
#define Column_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Column_PS                     (* (reg8 *) Column__PS)
/* Data Register */
#define Column_DR                     (* (reg8 *) Column__DR)
/* Port Number */
#define Column_PRT_NUM                (* (reg8 *) Column__PRT) 
/* Connect to Analog Globals */                                                  
#define Column_AG                     (* (reg8 *) Column__AG)                       
/* Analog MUX bux enable */
#define Column_AMUX                   (* (reg8 *) Column__AMUX) 
/* Bidirectional Enable */                                                        
#define Column_BIE                    (* (reg8 *) Column__BIE)
/* Bit-mask for Aliased Register Access */
#define Column_BIT_MASK               (* (reg8 *) Column__BIT_MASK)
/* Bypass Enable */
#define Column_BYP                    (* (reg8 *) Column__BYP)
/* Port wide control signals */                                                   
#define Column_CTL                    (* (reg8 *) Column__CTL)
/* Drive Modes */
#define Column_DM0                    (* (reg8 *) Column__DM0) 
#define Column_DM1                    (* (reg8 *) Column__DM1)
#define Column_DM2                    (* (reg8 *) Column__DM2) 
/* Input Buffer Disable Override */
#define Column_INP_DIS                (* (reg8 *) Column__INP_DIS)
/* LCD Common or Segment Drive */
#define Column_LCD_COM_SEG            (* (reg8 *) Column__LCD_COM_SEG)
/* Enable Segment LCD */
#define Column_LCD_EN                 (* (reg8 *) Column__LCD_EN)
/* Slew Rate Control */
#define Column_SLW                    (* (reg8 *) Column__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Column_PRTDSI__CAPS_SEL       (* (reg8 *) Column__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Column_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Column__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Column_PRTDSI__OE_SEL0        (* (reg8 *) Column__PRTDSI__OE_SEL0) 
#define Column_PRTDSI__OE_SEL1        (* (reg8 *) Column__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Column_PRTDSI__OUT_SEL0       (* (reg8 *) Column__PRTDSI__OUT_SEL0) 
#define Column_PRTDSI__OUT_SEL1       (* (reg8 *) Column__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Column_PRTDSI__SYNC_OUT       (* (reg8 *) Column__PRTDSI__SYNC_OUT) 


#if defined(Column__INTSTAT)  /* Interrupt Registers */

    #define Column_INTSTAT                (* (reg8 *) Column__INTSTAT)
    #define Column_SNAP                   (* (reg8 *) Column__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Column_H */


/* [] END OF FILE */
