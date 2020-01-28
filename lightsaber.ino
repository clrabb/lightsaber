#include "lightsaber_consts.h"
#include "lightsaber_types.h"
#include "singleton_t.h"
#include "sound.h"
#include "heartbeat.h"
#include <Wire.h>

#include "sound_manager.h"
#include <SoftwareSerial.h>

unsigned long last_millis = millis();
void setup() 
{
    Serial.begin( 115200 );
    init_singletons();
    init_pins();
    //init_soundboard();
    //init_accel();
    randomSeed( analogRead( 0 ) );
}


int next_fire = 3000; // random( 6000 );

void loop() 
{

/*
    
    sound_manager& manager = singleton_t< sound_manager >::instance();
    manager.play_background();
    unsigned long now = millis();
    long interval = now - last_millis;
    if ( ( interval ) >= next_fire )
    {
        next_fire = random( 500, 3000 );
        Serial.print( "Delay was: " );
        Serial.print( next_fire );
        Serial.print( "  Interval was: " );
        Serial.println( interval );

        int sound_type = random( 3 );
        Serial.print( "Sound index was: " );
        Serial.println( sound_type );
        switch ( sound_type )
        {
            case 0: 
                manager.play_random_clash();
                break;

            case 1:
                manager.play_random_swing();
                break;

            case 2:
                manager.play_random_spin();
                break;
        }
        
        manager.play_background();
        last_millis = now;
    }

    */

    heartbeat& hb = singleton_t< heartbeat >::instance();
    hb.beat();
}

void init_pins()
{
    pinMode( SFX_ACT_PIN, INPUT );
}

void init_accel()
{
    accelerometer& accel = singleton_t< accelerometer >::instance();

    /* Initialise the sensor */
    if(!accel.begin())
    {
    /* There was a problem detecting the ADXL343 ... check your connections */
        Serial.println("Ooops, no ADXL343 detected ... Check your wiring!");
        while(1);
    }

    /* Set the range to whatever is appropriate for your project */

    accel.setRange(ADXL343_RANGE_16_G);
    // accel.setRange(ADXL343_RANGE_8_G);
    // accel.setRange(ADXL343_RANGE_4_G);
    // accel.setRange(ADXL343_RANGE_2_G);
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

    sfx.volDown();
    sfx.volDown();
    sfx.volDown();
    sfx.volDown();

    Serial.println( "Found board" );
}

void init_singletons()
{  
    /*

    singleton_t< SoftwareSerial >( new SoftwareSerial( SFX_RX_PIN, SFX_TX_PIN ) );
    SoftwareSerial& ss = singleton_t< SoftwareSerial >::instance();

    singleton_t< soundboard >( new soundboard( &(ss), NULL, SFX_RST_PIN ) );
    singleton_t< sound_manager >( new sound_manager() ); */
    singleton_t< heartbeat >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
}
