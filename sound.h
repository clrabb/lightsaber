#ifndef SOUND_H
#define SOUND_H

#include <stdint.h> //uint8_t
#include "lightsaber_types.h"

class Sound
{
private:
    uint8_t      m_track_num;

public:
    Sound( uint8_t track_num ) 
        : m_track_num( track_num )
    {
    }

    virtual void play();
    virtual void play_imp_pre();
    virtual void play_imp_post();
    virtual void stop_playing();
    uint8_t track_number() { return this->m_track_num; }

private:
    void play_track();
    
private:
    Sound( const Sound& );
    Sound& operator=( const Sound& );
};

#endif // SOUND_H
