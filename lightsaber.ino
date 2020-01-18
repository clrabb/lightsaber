#include "lightsaber_consts.h"
#include "lightsaber_types.h"
#include "singleton_t.h"
#include "sound.h"

#include <SoftwareSerial.h>

enum sounds
{
    HUM_NUM,  
    POWERON_NUM, 
    POWEROFF_NUM,
    SWING1_NUM,
    SWING2_NUM,
    CLASH1_NUM,
    CLASH2_NUM,
    SPIN1_NUM,
    SPIN2_NUM   
};

Sound hum( static_cast< uint8_t >( 0 ) ); 
Sound power_on( static_cast< uint8_t >( 1 ) );

void setup() {
    Serial.begin( 115200 );
    init_singletons();
    init_pins();
    init_soundboard();

}

void loop() {
    hum.play();
    delay( 1000 );
    hum.stop_playing();
    power_on.play();
    
}

void init_pins()
{
    pinMode( SFX_ACT, INPUT );
}

void init_soundboard()
{
    SoftwareSerial& ss = singleton_t< SoftwareSerial >::instance();
    Soundboard& sfx = singleton_t< Soundboard >::instance();  
    
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

    singleton_t< Soundboard >( new Soundboard( &(ss), NULL, SFX_RST ) );
}
