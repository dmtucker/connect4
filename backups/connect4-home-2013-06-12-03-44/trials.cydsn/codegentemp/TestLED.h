/*******************************************************************************
* File Name: TestLED.h  
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

#if !defined(CY_PINS_TestLED_H) /* Pins TestLED_H */
#define CY_PINS_TestLED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TestLED_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TestLED__PORT == 15 && ((TestLED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TestLED_Write(uint8 value) ;
void    TestLED_SetDriveMode(uint8 mode) ;
uint8   TestLED_ReadDataReg(void) ;
uint8   TestLED_Read(void) ;
uint8   TestLED_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TestLED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TestLED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TestLED_DM_RES_UP          PIN_DM_RES_UP
#define TestLED_DM_RES_DWN         PIN_DM_RES_DWN
#define TestLED_DM_OD_LO           PIN_DM_OD_LO
#define TestLED_DM_OD_HI           PIN_DM_OD_HI
#define TestLED_DM_STRONG          PIN_DM_STRONG
#define TestLED_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TestLED_MASK               TestLED__MASK
#define TestLED_SHIFT              TestLED__SHIFT
#define TestLED_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TestLED_PS                     (* (reg8 *) TestLED__PS)
/* Data Register */
#define TestLED_DR                     (* (reg8 *) TestLED__DR)
/* Port Number */
#define TestLED_PRT_NUM                (* (reg8 *) TestLED__PRT) 
/* Connect to Analog Globals */                                                  
#define TestLED_AG                     (* (reg8 *) TestLED__AG)                       
/* Analog MUX bux enable */
#define TestLED_AMUX                   (* (reg8 *) TestLED__AMUX) 
/* Bidirectional Enable */                                                        
#define TestLED_BIE                    (* (reg8 *) TestLED__BIE)
/* Bit-mask for Aliased Register Access */
#define TestLED_BIT_MASK               (* (reg8 *) TestLED__BIT_MASK)
/* Bypass Enable */
#define TestLED_BYP                    (* (reg8 *) TestLED__BYP)
/* Port wide control signals */                                                   
#define TestLED_CTL                    (* (reg8 *) TestLED__CTL)
/* Drive Modes */
#define TestLED_DM0                    (* (reg8 *) TestLED__DM0) 
#define TestLED_DM1                    (* (reg8 *) TestLED__DM1)
#define TestLED_DM2                    (* (reg8 *) TestLED__DM2) 
/* Input Buffer Disable Override */
#define TestLED_INP_DIS                (* (reg8 *) TestLED__INP_DIS)
/* LCD Common or Segment Drive */
#define TestLED_LCD_COM_SEG            (* (reg8 *) TestLED__LCD_COM_SEG)
/* Enable Segment LCD */
#define TestLED_LCD_EN                 (* (reg8 *) TestLED__LCD_EN)
/* Slew Rate Control */
#define TestLED_SLW                    (* (reg8 *) TestLED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TestLED_PRTDSI__CAPS_SEL       (* (reg8 *) TestLED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TestLED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TestLED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TestLED_PRTDSI__OE_SEL0        (* (reg8 *) TestLED__PRTDSI__OE_SEL0) 
#define TestLED_PRTDSI__OE_SEL1        (* (reg8 *) TestLED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TestLED_PRTDSI__OUT_SEL0       (* (reg8 *) TestLED__PRTDSI__OUT_SEL0) 
#define TestLED_PRTDSI__OUT_SEL1       (* (reg8 *) TestLED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TestLED_PRTDSI__SYNC_OUT       (* (reg8 *) TestLED__PRTDSI__SYNC_OUT) 


#if defined(TestLED__INTSTAT)  /* Interrupt Registers */

    #define TestLED_INTSTAT                (* (reg8 *) TestLED__INTSTAT)
    #define TestLED_SNAP                   (* (reg8 *) TestLED__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TestLED_H */


/* [] END OF FILE */
