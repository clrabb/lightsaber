#include <SoftwareSerial.h>
#include <Adafruit_Soundboard.h>

#include "lightsaber_consts.h"
#include "lightsaber_types.h"
#include "singleton_t.h"




void setup() {
    Serial.begin( 115200 );
    init_singletons();
    init_pins();
    init_soundboard();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void init_pins()
{
    pinMode( SFX_ACT, INPUT );
}

void init_soundboard()
{
    Soundboard& board = singleton_t< Soundboard >::instance();
    SoftwareSerial& ss = singleton_t< SoftwareSerial >::instance();
    
    ss.begin( SOUNDBOARD_BAUD );
    if ( !( board.reset() ) )
    {
        Serial.println( "Not Found" );
        while( 1 );
    }

    Serial.println( "Found board" );
}

void init_singletons()
{
    singleton_t< SoftwareSerial >   serial1(    new SoftwareSerial( SFX_RX, SFX_TX ) );
    singleton_t< Soundboard >       soundboard( new Soundboard( &( serial1.instance() ), NULL, SFX_RST ) );
}
