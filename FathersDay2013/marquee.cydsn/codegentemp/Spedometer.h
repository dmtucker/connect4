/*******************************************************************************
* File Name: Spedometer.h  
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

#if !defined(CY_PINS_Spedometer_H) /* Pins Spedometer_H */
#define CY_PINS_Spedometer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Spedometer_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Spedometer__PORT == 15 && ((Spedometer__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Spedometer_Write(uint8 value) ;
void    Spedometer_SetDriveMode(uint8 mode) ;
uint8   Spedometer_ReadDataReg(void) ;
uint8   Spedometer_Read(void) ;
uint8   Spedometer_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Spedometer_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Spedometer_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Spedometer_DM_RES_UP          PIN_DM_RES_UP
#define Spedometer_DM_RES_DWN         PIN_DM_RES_DWN
#define Spedometer_DM_OD_LO           PIN_DM_OD_LO
#define Spedometer_DM_OD_HI           PIN_DM_OD_HI
#define Spedometer_DM_STRONG          PIN_DM_STRONG
#define Spedometer_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Spedometer_MASK               Spedometer__MASK
#define Spedometer_SHIFT              Spedometer__SHIFT
#define Spedometer_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Spedometer_PS                     (* (reg8 *) Spedometer__PS)
/* Data Register */
#define Spedometer_DR                     (* (reg8 *) Spedometer__DR)
/* Port Number */
#define Spedometer_PRT_NUM                (* (reg8 *) Spedometer__PRT) 
/* Connect to Analog Globals */                                                  
#define Spedometer_AG                     (* (reg8 *) Spedometer__AG)                       
/* Analog MUX bux enable */
#define Spedometer_AMUX                   (* (reg8 *) Spedometer__AMUX) 
/* Bidirectional Enable */                                                        
#define Spedometer_BIE                    (* (reg8 *) Spedometer__BIE)
/* Bit-mask for Aliased Register Access */
#define Spedometer_BIT_MASK               (* (reg8 *) Spedometer__BIT_MASK)
/* Bypass Enable */
#define Spedometer_BYP                    (* (reg8 *) Spedometer__BYP)
/* Port wide control signals */                                                   
#define Spedometer_CTL                    (* (reg8 *) Spedometer__CTL)
/* Drive Modes */
#define Spedometer_DM0                    (* (reg8 *) Spedometer__DM0) 
#define Spedometer_DM1                    (* (reg8 *) Spedometer__DM1)
#define Spedometer_DM2                    (* (reg8 *) Spedometer__DM2) 
/* Input Buffer Disable Override */
#define Spedometer_INP_DIS                (* (reg8 *) Spedometer__INP_DIS)
/* LCD Common or Segment Drive */
#define Spedometer_LCD_COM_SEG            (* (reg8 *) Spedometer__LCD_COM_SEG)
/* Enable Segment LCD */
#define Spedometer_LCD_EN                 (* (reg8 *) Spedometer__LCD_EN)
/* Slew Rate Control */
#define Spedometer_SLW                    (* (reg8 *) Spedometer__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Spedometer_PRTDSI__CAPS_SEL       (* (reg8 *) Spedometer__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Spedometer_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Spedometer__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Spedometer_PRTDSI__OE_SEL0        (* (reg8 *) Spedometer__PRTDSI__OE_SEL0) 
#define Spedometer_PRTDSI__OE_SEL1        (* (reg8 *) Spedometer__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Spedometer_PRTDSI__OUT_SEL0       (* (reg8 *) Spedometer__PRTDSI__OUT_SEL0) 
#define Spedometer_PRTDSI__OUT_SEL1       (* (reg8 *) Spedometer__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Spedometer_PRTDSI__SYNC_OUT       (* (reg8 *) Spedometer__PRTDSI__SYNC_OUT) 


#if defined(Spedometer__INTSTAT)  /* Interrupt Registers */

    #define Spedometer_INTSTAT                (* (reg8 *) Spedometer__INTSTAT)
    #define Spedometer_SNAP                   (* (reg8 *) Spedometer__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Spedometer_H */


/* [] END OF FILE */
