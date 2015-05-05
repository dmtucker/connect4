/*******************************************************************************
* File Name: Red.h  
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

#if !defined(CY_PINS_Red_H) /* Pins Red_H */
#define CY_PINS_Red_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Red_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Red__PORT == 15 && ((Red__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Red_Write(uint8 value) ;
void    Red_SetDriveMode(uint8 mode) ;
uint8   Red_ReadDataReg(void) ;
uint8   Red_Read(void) ;
uint8   Red_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Red_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Red_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Red_DM_RES_UP          PIN_DM_RES_UP
#define Red_DM_RES_DWN         PIN_DM_RES_DWN
#define Red_DM_OD_LO           PIN_DM_OD_LO
#define Red_DM_OD_HI           PIN_DM_OD_HI
#define Red_DM_STRONG          PIN_DM_STRONG
#define Red_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Red_MASK               Red__MASK
#define Red_SHIFT              Red__SHIFT
#define Red_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Red_PS                     (* (reg8 *) Red__PS)
/* Data Register */
#define Red_DR                     (* (reg8 *) Red__DR)
/* Port Number */
#define Red_PRT_NUM                (* (reg8 *) Red__PRT) 
/* Connect to Analog Globals */                                                  
#define Red_AG                     (* (reg8 *) Red__AG)                       
/* Analog MUX bux enable */
#define Red_AMUX                   (* (reg8 *) Red__AMUX) 
/* Bidirectional Enable */                                                        
#define Red_BIE                    (* (reg8 *) Red__BIE)
/* Bit-mask for Aliased Register Access */
#define Red_BIT_MASK               (* (reg8 *) Red__BIT_MASK)
/* Bypass Enable */
#define Red_BYP                    (* (reg8 *) Red__BYP)
/* Port wide control signals */                                                   
#define Red_CTL                    (* (reg8 *) Red__CTL)
/* Drive Modes */
#define Red_DM0                    (* (reg8 *) Red__DM0) 
#define Red_DM1                    (* (reg8 *) Red__DM1)
#define Red_DM2                    (* (reg8 *) Red__DM2) 
/* Input Buffer Disable Override */
#define Red_INP_DIS                (* (reg8 *) Red__INP_DIS)
/* LCD Common or Segment Drive */
#define Red_LCD_COM_SEG            (* (reg8 *) Red__LCD_COM_SEG)
/* Enable Segment LCD */
#define Red_LCD_EN                 (* (reg8 *) Red__LCD_EN)
/* Slew Rate Control */
#define Red_SLW                    (* (reg8 *) Red__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Red_PRTDSI__CAPS_SEL       (* (reg8 *) Red__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Red_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Red__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Red_PRTDSI__OE_SEL0        (* (reg8 *) Red__PRTDSI__OE_SEL0) 
#define Red_PRTDSI__OE_SEL1        (* (reg8 *) Red__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Red_PRTDSI__OUT_SEL0       (* (reg8 *) Red__PRTDSI__OUT_SEL0) 
#define Red_PRTDSI__OUT_SEL1       (* (reg8 *) Red__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Red_PRTDSI__SYNC_OUT       (* (reg8 *) Red__PRTDSI__SYNC_OUT) 


#if defined(Red__INTSTAT)  /* Interrupt Registers */

    #define Red_INTSTAT                (* (reg8 *) Red__INTSTAT)
    #define Red_SNAP                   (* (reg8 *) Red__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Red_H */


/* [] END OF FILE */
