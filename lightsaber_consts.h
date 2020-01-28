#ifndef LIGHTSABER_CONSTS_H
#define LIGHTSABER_CONSTS_H

static const short SOUNDBOARD_BAUD = 9600;

static const short SFX_TX_PIN     = 10;
static const short SFX_RX_PIN     = 11;
static const short SFX_ACT_PIN    = 7;
static const short SFX_RST_PIN    = 2;
static const short HEARTBEAT_PIN  = 3;

static unsigned long    HEARTBEAT_DURATION_ON     = 50;  // milliseconds on
static unsigned long    HEARTBEAT_DURATION_OFF    = 1000; // milliseconds off
/* 
 * How much movement we ignore when x + y + z = 90.
 * 
 */
static const short JIGGLE_FACTOR = 2;

#endif // LIGHTSABER_CONSTS_H
