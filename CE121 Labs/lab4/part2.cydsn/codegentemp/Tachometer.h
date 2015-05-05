/*******************************************************************************
* File Name: Tachometer.h  
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

#if !defined(CY_PINS_Tachometer_H) /* Pins Tachometer_H */
#define CY_PINS_Tachometer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Tachometer_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Tachometer__PORT == 15 && ((Tachometer__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Tachometer_Write(uint8 value) ;
void    Tachometer_SetDriveMode(uint8 mode) ;
uint8   Tachometer_ReadDataReg(void) ;
uint8   Tachometer_Read(void) ;
uint8   Tachometer_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Tachometer_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Tachometer_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Tachometer_DM_RES_UP          PIN_DM_RES_UP
#define Tachometer_DM_RES_DWN         PIN_DM_RES_DWN
#define Tachometer_DM_OD_LO           PIN_DM_OD_LO
#define Tachometer_DM_OD_HI           PIN_DM_OD_HI
#define Tachometer_DM_STRONG          PIN_DM_STRONG
#define Tachometer_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Tachometer_MASK               Tachometer__MASK
#define Tachometer_SHIFT              Tachometer__SHIFT
#define Tachometer_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Tachometer_PS                     (* (reg8 *) Tachometer__PS)
/* Data Register */
#define Tachometer_DR                     (* (reg8 *) Tachometer__DR)
/* Port Number */
#define Tachometer_PRT_NUM                (* (reg8 *) Tachometer__PRT) 
/* Connect to Analog Globals */                                                  
#define Tachometer_AG                     (* (reg8 *) Tachometer__AG)                       
/* Analog MUX bux enable */
#define Tachometer_AMUX                   (* (reg8 *) Tachometer__AMUX) 
/* Bidirectional Enable */                                                        
#define Tachometer_BIE                    (* (reg8 *) Tachometer__BIE)
/* Bit-mask for Aliased Register Access */
#define Tachometer_BIT_MASK               (* (reg8 *) Tachometer__BIT_MASK)
/* Bypass Enable */
#define Tachometer_BYP                    (* (reg8 *) Tachometer__BYP)
/* Port wide control signals */                                                   
#define Tachometer_CTL                    (* (reg8 *) Tachometer__CTL)
/* Drive Modes */
#define Tachometer_DM0                    (* (reg8 *) Tachometer__DM0) 
#define Tachometer_DM1                    (* (reg8 *) Tachometer__DM1)
#define Tachometer_DM2                    (* (reg8 *) Tachometer__DM2) 
/* Input Buffer Disable Override */
#define Tachometer_INP_DIS                (* (reg8 *) Tachometer__INP_DIS)
/* LCD Common or Segment Drive */
#define Tachometer_LCD_COM_SEG            (* (reg8 *) Tachometer__LCD_COM_SEG)
/* Enable Segment LCD */
#define Tachometer_LCD_EN                 (* (reg8 *) Tachometer__LCD_EN)
/* Slew Rate Control */
#define Tachometer_SLW                    (* (reg8 *) Tachometer__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Tachometer_PRTDSI__CAPS_SEL       (* (reg8 *) Tachometer__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Tachometer_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Tachometer__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Tachometer_PRTDSI__OE_SEL0        (* (reg8 *) Tachometer__PRTDSI__OE_SEL0) 
#define Tachometer_PRTDSI__OE_SEL1        (* (reg8 *) Tachometer__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Tachometer_PRTDSI__OUT_SEL0       (* (reg8 *) Tachometer__PRTDSI__OUT_SEL0) 
#define Tachometer_PRTDSI__OUT_SEL1       (* (reg8 *) Tachometer__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Tachometer_PRTDSI__SYNC_OUT       (* (reg8 *) Tachometer__PRTDSI__SYNC_OUT) 


#if defined(Tachometer__INTSTAT)  /* Interrupt Registers */

    #define Tachometer_INTSTAT                (* (reg8 *) Tachometer__INTSTAT)
    #define Tachometer_SNAP                   (* (reg8 *) Tachometer__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Tachometer_H */


/* [] END OF FILE */
