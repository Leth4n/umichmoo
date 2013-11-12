/* See license.txt for license information. */

// these bit definitions are specific to Moo 1.2

#ifndef __DIGITAL_ACCEL_SENSOR_
#define __DIGITAL_ACCEL_SENSOR_

#define SENSOR_DATA_TYPE_ID       0x0D

#define DIGITAL_ACCEL_POWER       BIT4   // Pin 1.4

/*
 * Clock should be between 1 MHz and 5 MHz, according to the spec
 */
#define DIGITAL_ACCEL_CLK         BIT0   // Pin 3.0 - UCA0CLK
#define DIGITAL_ACCEL_MOSI        BIT4   // Pin 3.4 - UCA0SIMO
#define DIGITAL_ACCEL_MISO        BIT5   // Pin 3.5 - UCA0SOMI
#define DIGITAL_ACCEL_SEL         BIT6   // Pin 3.6 - GPIO 3.6
#define DIGITAL_ACCEL_INT1        BIT1   // Pin 6.1
#define DIGITAL_ACCEL_INT2        BIT0   // Pin 6.0

/*
 * ADXL 362 SPI commands, should be sent as first byte of SPI command
 */
#define DIGITAL_ACCEL_WRITE       ((uint8_t) 0x0A)
#define DIGITAL_ACCEL_READ        ((uint8_t) 0x0B)
#define DIGITAL_ACCEL_READ_FIFO   ((uint8_t) 0x0D)
/* MSP430 requires data to be written to receive data, so we use dummy byte */
#define DIGITAL_ACCEL_DUMMY       ((uint8_t) 0xFF)

/*
 * ADXL 362 addresses, sent as second byte of SPI command
 */
#define  DIGITAL_ACCEL_REG_DEVID_AD        ((uint8_t)  0x00)
#define  DIGITAL_ACCEL_REG_DEVID_MST       ((uint8_t)  0x01)
#define  DIGITAL_ACCEL_REG_PARTID          ((uint8_t)  0x02)
#define  DIGITAL_ACCEL_REG_REVID           ((uint8_t)  0x03)
#define  DIGITAL_ACCEL_REG_XDATA           ((uint8_t)  0x08)
#define  DIGITAL_ACCEL_REG_YDATA           ((uint8_t)  0x09)
#define  DIGITAL_ACCEL_REG_ZDATA           ((uint8_t)  0x0A)
#define  DIGITAL_ACCEL_REG_STATUS          ((uint8_t)  0x0B)
#define  DIGITAL_ACCEL_REG_FIFO_ENTRIES_L  ((uint8_t)  0x0C)
#define  DIGITAL_ACCEL_REG_FIFO_ENTRIES_H  ((uint8_t)  0x0D)
#define  DIGITAL_ACCEL_REG_XDATA_L         ((uint8_t)  0x0E)
#define  DIGITAL_ACCEL_REG_XDATA_H         ((uint8_t)  0x0F)
#define  DIGITAL_ACCEL_REG_YDATA_L         ((uint8_t)  0x10)
#define  DIGITAL_ACCEL_REG_YDATA_H         ((uint8_t)  0x11)
#define  DIGITAL_ACCEL_REG_ZDATA_L         ((uint8_t)  0x12)
#define  DIGITAL_ACCEL_REG_ZDATA_H         ((uint8_t)  0x13)
#define  DIGITAL_ACCEL_REG_TEMP_L          ((uint8_t)  0x14)
#define  DIGITAL_ACCEL_REG_TEMP_H          ((uint8_t)  0x14)
#define  DIGITAL_ACCEL_REG_SOFT_RESET      ((uint8_t)  0x1F)
#define  DIGITAL_ACCEL_REG_THRESH_ACT_L    ((uint8_t)  0x20)
#define  DIGITAL_ACCEL_REG_THRESH_ACT_H    ((uint8_t)  0x21)
#define  DIGITAL_ACCEL_REG_TIME_ACT        ((uint8_t)  0x22)
#define  DIGITAL_ACCEL_REG_THRESH_INACT_L  ((uint8_t)  0x23)
#define  DIGITAL_ACCEL_REG_THRESH_INACT_H  ((uint8_t)  0x24)
#define  DIGITAL_ACCEL_REG_TIME_INACT_L    ((uint8_t)  0x25)
#define  DIGITAL_ACCEL_REG_TIME_INACT_H    ((uint8_t)  0x26)
#define  DIGITAL_ACCEL_REG_ACT_INACT_CTL   ((uint8_t)  0x27)
#define  DIGITAL_ACCEL_REG_FIFO_CONTROL    ((uint8_t)  0x28)
#define  DIGITAL_ACCEL_REG_FIFO_SAMPLES    ((uint8_t)  0x29)
#define  DIGITAL_ACCEL_REG_INTMAP1         ((uint8_t)  0x2A)
#define  DIGITAL_ACCEL_REG_INTMAP2         ((uint8_t)  0x2B)
#define  DIGITAL_ACCEL_REG_FILTER_CTL      ((uint8_t)  0x2C)
#define  DIGITAL_ACCEL_REG_POWER_CTL       ((uint8_t)  0x2D)
#define  DIGITAL_ACCEL_REG_SELF_TEST       ((uint8_t)  0x2E)

/*
 * Data for configuring the ADXL 362 filter register
 */
enum EDigitalAccelRange {
  EDigitalAccelRange_2g = 0x0,
  EDigitalAccelRange_4g = 0x1,
  EDigitalAccelRange_8g = 0x2,
}

enum EDigitalAccelOdr {
  EDigitalAccelOdr_12Hz = 0x0,
  EDigitalAccelOdr_25Hz = 0x1,
  EDigitalAccelOdr_50Hz = 0x2,
  EDigitalAccelOdr_100Hz = 0x3
  EDigitalAccelOdr_200Hz = 0x4,
  EDigtal_AccelOdr_400Hz = 0x4,
};

#define DIGITAL_ACCEL_FILT_HALF_BW 16
#define DIGITAL_ACCEL_FILT_EXT_SAMPLE 8

/*
 * Data for controlling the ADXL 362 power register
 */
enum EDigitalAccelMode {
  EDigitalAccelMode_Standby      =  0x0,
  EDigitalAccelMode_Measurement  =  0x2
};

enum EDigitalAccelLowNoise {
  EDigitalAccelLowNoise_normal    =  0x0,
  EDigitalAccelLowNoise_low       =  0x1,
  EDigitalAccelLowNoise_ultralow  =  0x2,
};


#define  DIGITAL_ACCEL_POWER_AUTOSLEEP  4
#define  DIGITAL_ACCEL_POWER_WAKEUP     8
#define  DIGITAL_ACCEL_POWER_EXT_CLK   64

/*
 * Recommended USCI Initialization and Reset (from page 438 of MSP430x2xx Family
 * Guide)
 *   1. Set UCSWRST (BIS.B #UCSWRST,&UCxCTL1) (Done on PUC)
 *   2. Initialize all USCI registers with UCSWRST=1 (including UCxCTL1) (Done on PUC)
 *   3. Configure ports (Can really start here if just initializing, not resetting)
 *   4. Clear UCSWRST via software (BIC.B, #UCSWRST, &UCxCTL1)
 *   5. Enable interrupts (optional) via UCxRXIE and/or UCxTXIE
 */

/*
 * Initialization/power functions.
 */
/*
 * Turns on the accelerometer.
 *
 * Expects pin 1.4 to be setup properly already (GPIO mode selected, direction
 * set to out). If it is not properly configured, then call
 * digital_accel_setup_pins() first.
 */
void digital_accel_power_on();

/*
 * Turns off the accelerometer.
 */
void digital_aceel_power_off();

/*
 * Initializes the SPI interface for the accelerometer.
 */
void digital_accel_init();

/*
 * Selects pin modes for pins of the accelerometer, in case they were configured
 * as GPIO pins.
 *
 * This function by itself will not setup the SPI interface.
 */
void digital_accel_setup_pins();


/*
 * Set the power register to the values that are appropriate
 */
void digital_accel_set_power(enum EDigitalAccelMode, enum EDigitalAccelLowNoise, uint8_t flags);

/*
 * Set the filter register to values that are appropriate
 */
void digital_accel_set_filter(enum EDigitalAccelRange range, enum EDigitalAccelOdr odr, uint8_t flags); 

void digital_accel_write_address(uint8_t address, uint8_t byte); 
uint8_t digital_accel_read_address(uint8_t address); 
void digital_accel_read_burst(uint8_t start_address, uint8_t * data, uint8_t len); 
void digital_accel_write_burst(uint8_t start_address, uint8_t * data, uint8_t len); 

#endif