#include "heartbeat.h"
#include "lightsaber_consts.h"


heartbeat::heartbeat( uint8_t led_pin, unsigned long mills_between_beats, unsigned long beat_length_mills )
    :
    m_led_pin( led_pin ),
    m_mills_between_beats( mills_between_beats ),
    m_beat_length_mills( beat_length_mills ),
    m_is_on( false )
{
    pinMode( HEARTBEAT_PIN, OUTPUT );
}

void
heartbeat::beat()
{
    if ( this->is_off() )
        this->off_beat();
    else
        this->on_beat();

    return;
}

unsigned long 
heartbeat::time_on()
{
    return
        ( this->is_on() )
            ? millis() - this->last_state_change_mills() 
            : 0
        ;           
}

unsigned long
heartbeat::time_off()
{
    return
        ( this->is_off() )
            ? millis() - this->last_state_change_mills() 
            : 0
        ;
}

void 
heartbeat::off_beat()
{   
    if ( this->time_off() >= this->mills_between_beats() )
    {
        this->turn_on();
    }

    return;
}

void
heartbeat::on_beat()
{
    if ( this->time_on() >= this->beat_length_mills() )
    {
        this->turn_off();
    }

    return;
}

void 
heartbeat::turn_on()
{
    this->is_on( true );
    digitalWrite( this->led_pin(), HIGH );
    digitalWrite( LED_BUILTIN, HIGH );

    this->last_state_change_mills( millis() );
    return;
}

void 
heartbeat::turn_off()
{
    this->is_on( false );
    digitalWrite( this->led_pin(), LOW );   
    digitalWrite( LED_BUILTIN, LOW );
    this->last_state_change_mills( millis() );

    return;
}
  
