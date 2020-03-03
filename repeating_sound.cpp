#include "repeating_sound.h"
#include "lightsaber_consts.h"
#include "sound_manager.h"

repeating_sound::repeating_sound( uint8_t sound_num )
    : interrupt_sound( sound_num )
{  
}

void
repeating_sound::tick_impl( sound_manager& manager )
{ 
    manager.tick_from_repeating_sound( *this );
}
