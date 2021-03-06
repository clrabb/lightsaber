#include "sound.h"
#include "lightsaber_types.h"
#include "lightsaber_consts.h"
#include "singleton_t.h"
#include "sound_manager.h"
#include "logger.h"

void 
sound::play()
{
    this->play_imp_pre();   
    this->play_track();
    this->play_imp_post();

    return; 
}

boolean
sound::is_playing()
{
    return digitalRead( SFX_ACT_PIN ) == LOW;
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
    // This space intentionally left blank
    return;
}

void 
sound::stop_playing()
{
    soundboard& sfx = singleton_t< soundboard >::instance();
    sfx.stop();
}

void
sound::tick( sound_manager& manager )
{
    logger& l = singleton_t< logger >::instance();
    l.println( "sound::tick()" );
    
    this->tick_impl( manager );
}

void
sound::tick_impl( sound_manager& manager )
{
    logger& l = singleton_t< logger >::instance();
    l.println( "sound::tick_impl()" );
    
    manager.tick_from_sound( *this );
}


void 
sound::play_track()
{   
    logger& l = singleton_t< logger >::instance(); 
    uint8_t track_number = this->track_number();
    
    soundboard& sfx = singleton_t< soundboard >::instance();
    if ( !( sfx.playTrack(  static_cast< uint8_t >( track_number ) ) ) )
    {
        l.print( "Failed to play track " );
        l.println( track_number );
    }
    else
    {
        l.print( "Playing track " );
        l.println( track_number );
    }
}
