#include "interrupt_sound.h"
#include "singleton_t.h"

void
InterruptSound::play_pre_imp()
{
    Soundboard& sfx = singleton_t< Soundboard >::instance();
    sfx.stop();

    return;
}
