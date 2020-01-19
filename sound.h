#ifndef SOUND_H
#define SOUND_H

#include <stdint.h> //uint8_t
#include "lightsaber_types.h"

class sound
{
private:
    uint8_t      m_track_num;

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


    // Testing
    //
    boolean is_playing();

private:
    void play_track();
    
private:
    sound( const sound& );
    sound& operator=( const sound& );
};

#endif // SOUND_H
