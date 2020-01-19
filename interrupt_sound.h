#ifndef INTERRUPT_SOUND_H
#define INTERRUPT_SOUND_H

#include "sound.h"

class interrupt_sound : sound
{
    interrupt_sound( uint8_t track_number )
        : sound( track_number )
    {       
    }

    virtual void play_imp_pre();
};


#endif // INTERRUPT_SOUND_H
