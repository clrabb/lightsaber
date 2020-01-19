#include "sound.h"
#include "lightsaber_types.h"
#include "lightsaber_consts.h"
#include "singleton_t.h"

void 
sound::play()
{
    this->play_imp_pre();   
    this->play_track();
    this->play_imp_post();

    return; 
}

void 
sound::play_imp_pre()
{
    // This space intentionally left blank

    return;
}

void 
sound::play_imp_post()
{
}

void 
sound::stop_playing()
{
    soundboard& sfx = singleton_t< soundboard >::instance();
    sfx.stop();
}

void 
sound::play_track()
{
    if ( this->is_playing() )
    {
        this->stop_playing();
    }
    
    soundboard& sfx = singleton_t< soundboard >::instance();
    sfx.playTrack( static_cast< uint8_t >( this->track_number() ) );
}

boolean
sound::is_playing()
{
    return digitalRead( SFX_ACT ) == LOW;
}
