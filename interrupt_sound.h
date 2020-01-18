#ifndef INTERRUPT_SOUND_H
#define INTERRUPT_SOUND_H

#include "sound.h"

class InterruptSound : Sound
{
    InterruptSound( uint8_t track_number )
        : Sound( track_number )
    {       
    }

    virtual void play_imp_pre();
};


#endif // INTERRUPT_SOUND_H
