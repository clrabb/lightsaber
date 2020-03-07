#include "interrupt_sound.h"
#include "singleton_t.h"
#include "logger.h"

void
interrupt_sound::play_imp_pre()
{
    soundboard& sfx = singleton_t< soundboard >::instance();
    if ( this->is_playing() )
    {
        sfx.stop();
    }

    return;
}
