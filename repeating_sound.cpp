#include "repeating_sound.h"
#include "lightsaber_consts.h"
#include "sound_manager.h"
#include "logger.h"
#include "singleton_t.h"

repeating_sound::repeating_sound( uint8_t sound_num )
    : interrupt_sound( sound_num )
{  
}

void
repeating_sound::tick_impl( sound_manager& manager )
{ 
    logger& l = singleton_t< logger >::instance();
    
    l.println( "repeating_sound::tick_impl()" );
    manager.tick_from_repeating_sound( *this );
}
