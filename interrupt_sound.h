#ifndef INTERRUPT_SOUND_H
#define INTERRUPT_SOUND_H

#include "sound.h"

class interrupt_sound : public sound
{
public:
    interrupt_sound( uint8_t track_number )
        : sound( track_number )
    {       
    }

protected:
    virtual void play_imp_pre();
};


#endif // INTERRUPT_SOUND_H
