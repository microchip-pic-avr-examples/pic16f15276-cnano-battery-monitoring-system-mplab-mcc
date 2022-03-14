/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA6 aliases
#define Reg_En_TRIS                 TRISAbits.TRISA6
#define Reg_En_LAT                  LATAbits.LATA6
#define Reg_En_PORT                 PORTAbits.RA6
#define Reg_En_WPU                  WPUAbits.WPUA6
#define Reg_En_OD                   ODCONAbits.ODCA6
#define Reg_En_ANS                  ANSELAbits.ANSA6
#define Reg_En_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define Reg_En_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define Reg_En_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define Reg_En_GetValue()           PORTAbits.RA6
#define Reg_En_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define Reg_En_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define Reg_En_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define Reg_En_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define Reg_En_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define Reg_En_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define Reg_En_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define Reg_En_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_RB5 aliases
#define IO_RB5_TRIS                 TRISBbits.TRISB5
#define IO_RB5_LAT                  LATBbits.LATB5
#define IO_RB5_PORT                 PORTBbits.RB5
#define IO_RB5_WPU                  WPUBbits.WPUB5
#define IO_RB5_OD                   ODCONBbits.ODCB5
#define IO_RB5_ANS                  ANSELBbits.ANSB5
#define IO_RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RB5_GetValue()           PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RB5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RB5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RB5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RB5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RC2 aliases
#define Iload_TRIS                 TRISCbits.TRISC2
#define Iload_LAT                  LATCbits.LATC2
#define Iload_PORT                 PORTCbits.RC2
#define Iload_WPU                  WPUCbits.WPUC2
#define Iload_OD                   ODCONCbits.ODCC2
#define Iload_ANS                  ANSELCbits.ANSC2
#define Iload_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Iload_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Iload_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Iload_GetValue()           PORTCbits.RC2
#define Iload_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Iload_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Iload_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Iload_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Iload_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Iload_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define Iload_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define Iload_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC7 aliases
#define STAT1_TRIS                 TRISCbits.TRISC7
#define STAT1_LAT                  LATCbits.LATC7
#define STAT1_PORT                 PORTCbits.RC7
#define STAT1_WPU                  WPUCbits.WPUC7
#define STAT1_OD                   ODCONCbits.ODCC7
#define STAT1_ANS                  ANSELCbits.ANSC7
#define STAT1_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define STAT1_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define STAT1_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define STAT1_GetValue()           PORTCbits.RC7
#define STAT1_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define STAT1_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define STAT1_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define STAT1_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define STAT1_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define STAT1_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define STAT1_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define STAT1_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define Vinput_TRIS                 TRISDbits.TRISD0
#define Vinput_LAT                  LATDbits.LATD0
#define Vinput_PORT                 PORTDbits.RD0
#define Vinput_WPU                  WPUDbits.WPUD0
#define Vinput_OD                   ODCONDbits.ODCD0
#define Vinput_ANS                  ANSELDbits.ANSD0
#define Vinput_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Vinput_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Vinput_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Vinput_GetValue()           PORTDbits.RD0
#define Vinput_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Vinput_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define Vinput_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define Vinput_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define Vinput_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define Vinput_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define Vinput_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define Vinput_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define Iload_TRIS                 TRISDbits.TRISD1
#define Iload_LAT                  LATDbits.LATD1
#define Iload_PORT                 PORTDbits.RD1
#define Iload_WPU                  WPUDbits.WPUD1
#define Iload_OD                   ODCONDbits.ODCD1
#define Iload_ANS                  ANSELDbits.ANSD1
#define Iload_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define Iload_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define Iload_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define Iload_GetValue()           PORTDbits.RD1
#define Iload_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define Iload_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define Iload_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define Iload_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define Iload_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define Iload_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define Iload_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define Iload_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD3 aliases
#define Vbat_TRIS                 TRISDbits.TRISD3
#define Vbat_LAT                  LATDbits.LATD3
#define Vbat_PORT                 PORTDbits.RD3
#define Vbat_WPU                  WPUDbits.WPUD3
#define Vbat_OD                   ODCONDbits.ODCD3
#define Vbat_ANS                  ANSELDbits.ANSD3
#define Vbat_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define Vbat_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define Vbat_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define Vbat_GetValue()           PORTDbits.RD3
#define Vbat_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define Vbat_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define Vbat_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define Vbat_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define Vbat_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define Vbat_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define Vbat_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define Vbat_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set IO_RD4 aliases
#define Vload_TRIS                 TRISDbits.TRISD4
#define Vload_LAT                  LATDbits.LATD4
#define Vload_PORT                 PORTDbits.RD4
#define Vload_WPU                  WPUDbits.WPUD4
#define Vload_OD                   ODCONDbits.ODCD4
#define Vload_ANS                  ANSELDbits.ANSD4
#define Vload_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define Vload_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define Vload_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define Vload_GetValue()           PORTDbits.RD4
#define Vload_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define Vload_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define Vload_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define Vload_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define Vload_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define Vload_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define Vload_SetAnalogMode()      do { ANSELDbits.ANSD4 = 1; } while(0)
#define Vload_SetDigitalMode()     do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set IO_RD7 aliases
#define Ibat_TRIS                 TRISDbits.TRISD7
#define Ibat_LAT                  LATDbits.LATD7
#define Ibat_PORT                 PORTDbits.RD7
#define Ibat_WPU                  WPUDbits.WPUD7
#define Ibat_OD                   ODCONDbits.ODCD7
#define Ibat_ANS                  ANSELDbits.ANSD7
#define Ibat_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define Ibat_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define Ibat_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define Ibat_GetValue()           PORTDbits.RD7
#define Ibat_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define Ibat_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define Ibat_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define Ibat_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define Ibat_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define Ibat_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define Ibat_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define Ibat_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the RB5 pin functionality
 * @param none
 * @return none
 */
void RB5_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for RB5 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for RB5 at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void RB5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for RB5 pin.
 *        This is a dynamic interrupt handler to be used together with the RB5_SetInterruptHandler() method.
 *        This handler is called every time the RB5 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*RB5_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for RB5 pin. 
 *        This is a predefined interrupt handler to be used together with the RB5_SetInterruptHandler() method.
 *        This handler is called every time the RB5 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void RB5_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/