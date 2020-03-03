#ifndef SOUND_H
#define SOUND_H

#include <stdint.h> //uint8_t
#include "lightsaber_types.h"

class sound_manager;

class sound
{
private:
    uint8_t m_track_num;
    long    m_last_checked_millis;

public:
    sound( uint8_t track_num ) 
        : m_track_num( track_num )
    {
    }

    // Setters/getters
    //
    uint8_t track_number() { return this->m_track_num; }

    // Behavior
    //
    virtual void play();
    virtual void play_imp_pre();
    virtual void play_imp_post();
    virtual void stop_playing();


    // Timing
    //
    long last_checked_millis() { return this->m_last_checked_millis; }
    void last_checked_millis( long time_millis ) { this->m_last_checked_millis = time_millis; }    
    long last_checked_interval();
    void tick_impl( sound_manager& manager );
    virtual void tick( sound_manager& manager );
 
    
    
    // Testing
    //
    boolean is_playing();
    boolean is_not_playing() { return !( this->is_playing() ); }


private:
    void play_track();
    
    
private:
    sound( const sound& );
    sound& operator=( const sound& );
};

#endif // SOUND_H
