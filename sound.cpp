#include "sound.h"
#include "lightsaber_types.h"
#include "lightsaber_consts.h"
#include "singleton_t.h"

void 
Sound::play()
{
    this->play_imp_pre();   
    this->play_track();
    this->play_imp_post();

    return; 
}

void 
Sound::play_imp_pre()
{
    // This space intentionally left blank

    return;
}

void 
Sound::play_imp_post()
{
}

void 
Sound::stop_playing()
{
    Soundboard& sfx = singleton_t< Soundboard >::instance();
    sfx.stop();
}

void 
Sound::play_track()
{

    Soundboard& sfx = singleton_t< Soundboard >::instance();
    sfx.playTrack( static_cast< uint8_t >( this->track_number() ) );
}
