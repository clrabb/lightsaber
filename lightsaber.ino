#include "lightsaber_consts.h"
#include "lightsaber_types.h"
#include "singleton_t.h"
#include "sound.h"

#include "sound_manager.h"

#include <SoftwareSerial.h>



void setup() {
    Serial.begin( 115200 );
    init_singletons();
    init_pins();
    init_soundboard();

}

void loop() 
{

    
}

void init_pins()
{
    pinMode( SFX_ACT, INPUT );
}

void init_soundboard()
{
    SoftwareSerial& ss = singleton_t< SoftwareSerial >::instance();
    soundboard& sfx = singleton_t< soundboard >::instance();  
    
    ss.begin( SOUNDBOARD_BAUD );
    if ( !( sfx.reset() ) )
    {
        Serial.println( "Not Found" );
        while( 1 );
    }

    Serial.println( "Found board" );
}

void init_singletons()
{  
    singleton_t< SoftwareSerial >( new SoftwareSerial( SFX_RX, SFX_TX ) );
    SoftwareSerial& ss = singleton_t< SoftwareSerial >::instance();

    singleton_t< soundboard >( new soundboard( &(ss), NULL, SFX_RST ) );
}
