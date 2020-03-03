#include "lightsaber_consts.h"
#include "lightsaber_types.h"
#include "singleton_t.h"
#include "sound.h"
#include "heartbeat.h"
#include "movement.h"
#include <Wire.h>

#include "sound_manager.h"

unsigned long last_millis = millis();
void setup() 
{
    Serial.begin( 9600 );
    while( !Serial );
    //Serial.println( "Serial port init'd" );
    
    init_pins();
    init_singletons();
    init_soundboard();
    //init_accel();
    //randomSeed( analogRead( 0 ) );
}



uint8_t type_to_play = 0;
void loop() 
{
    movement& m = singleton_t< movement >::instance();
    sound_manager& manager = singleton_t< sound_manager >::instance();


    while( 1 )
    {
        if ( type_to_play++ == 0 )
        {
            manager.play_background();
        }
        else if ( type_to_play++ == 1 )
        {
            manager.play_random_clash();
        }
        else if ( type_to_play == 2 )
        {
            manager.play_random_spin();
            type_to_play = 0;
        }
        
        delay( 5000 );
    }



    

    
    /*
    if ( m.has_clashed() )
    {
        manager.play_random_clash();
    } 
    else if ( m.has_spun() )
    {
        manager.play_random_spin();
    }
    else if ( m.has_swung() )
    {
        manager.play_random_swing();
    }
    */

    heartbeat& hb = singleton_t< heartbeat >::instance();
    hb.beat();
    manager.tick();
}

void init_pins()
{
    pinMode( SFX_ACT_PIN, INPUT     );
    pinMode( LED_BUILTIN, OUTPUT    );
    pinMode( HEARTBEAT_PIN, OUTPUT  );
}

void init_accel()
{
    Serial.println( "About to init accel" );
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
    soundboard& sfx = singleton_t< soundboard >::instance();  
    Serial.println("About to init soundboard" );
    serial_output.begin( SOUNDBOARD_BAUD );

    
    delay( 1000 );

    if (!sfx.reset()) 
    {
        Serial.println("Not found");
        while( 1 );
    }


    for ( short i = 0; i < 2; ++i )
    {
        sfx.volDown();
    }

    Serial.println( "Found board" );
}

void init_singletons()
{  
    singleton_t< sound_manager >( new sound_manager() ); 
    
    singleton_t< soundboard >( new soundboard( &(serial_output), NULL, SFX_RST_PIN ) );
    
    singleton_t< accelerometer >( new accelerometer( 12345 ) );
    singleton_t< heartbeat >( new heartbeat( HEARTBEAT_PIN, HEARTBEAT_DURATION_OFF, HEARTBEAT_DURATION_ON ) );
}
