#include "interrupt_sound.h"
#include "singleton_t.h"

void
interrupt_sound::play_imp_pre()
{
    soundboard& sfx = singleton_t< soundboard >::instance();
    sfx.stop();

    return;
}
