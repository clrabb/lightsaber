#include "sound_manager.h"
#include "lightsaber_consts.h"
#include "sound.h"

sound_manager::sound_manager()
{
    this->init_swing_sounds();
    this->init_clash_sounds();
    this->init_spin_sounds();
    this->init_background_sound();

    this->current_sound( this->background_sound() );
}

void
sound_manager::init_swing_sounds()
{
    this->m_swing_sounds[ 0 ] = new interrupt_sound( SWING1_NUM );
    this->m_swing_sounds[ 1 ] = new interrupt_sound( SWING2_NUM );
}

void
sound_manager::init_clash_sounds()
{
    this->m_clash_sounds[ 0 ] = new interrupt_sound( CLASH1_NUM );
    this->m_clash_sounds[ 1 ] = new interrupt_sound( CLASH2_NUM );
}

void
sound_manager::init_spin_sounds()
{
    this->m_spin_sounds[ 0 ] = new interrupt_sound( SPIN1_NUM );
    this->m_spin_sounds[ 1 ] = new interrupt_sound( SPIN2_NUM );
}

void
sound_manager::init_background_sound()
{
    this->background_sound( new repeating_sound( HUM_NUM ) );
}

boolean
sound_manager::is_playing()
{
    return this->current_sound()->is_playing();
}

void 
sound_manager::play_background()
{
    Serial.println( "playing background" );
    this->m_background_sound->play();
}

void 
sound_manager::play_random_clash()
{
    int idx = random( NUM_CLASH_SOUNDS );
    this->current_sound( this->m_clash_sounds[ idx ] );
    this->play();
    this->current_sound( this->background_sound() );
}

void
sound_manager::play_random_swing()
{
    Serial.println( "playing random swing" );
    int idx = random( NUM_SWING_SOUNDS );
    this->current_sound( this->m_swing_sounds[ idx ] );
    this->play();
    this->current_sound( this->background_sound() );
}

void
sound_manager::play_random_spin()
{
    int idx = random( NUM_SPIN_SOUNDS );
    this->current_sound( this->m_spin_sounds[ idx ] );
    this->play();
    this->current_sound( this->background_sound() );
}

void
sound_manager::play()
{
    this->current_sound()->play();
}

void
sound_manager::tick()
{
    this->current_sound()->tick( *this );
}

void 
sound_manager::tick_from_sound( sound& a_sound )
{
    if ( a_sound.is_not_playing() )
    {
        this->current_sound( this->background_sound() );
    }

    this->play();
}

void 
sound_manager::tick_from_repeating_sound( sound& a_sound )
{
    if ( a_sound.is_not_playing() )
        a_sound.play(); 
}
