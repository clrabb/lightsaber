#include "sound_manager.h"


sound_manager::sound_manager()
{
    this->init_swing_sounds();
    this->init_clash_sounds();
    this->init_spin_sounds();

    m_background_sound = new sound( HUM_NUM );
}

void
sound_manager::init_swing_sounds()
{
    this->m_swing_sounds[ 0 ] = new sound( SWING1_NUM );
    this->m_swing_sounds[ 1 ] = new sound( SWING2_NUM );
}

void
sound_manager::init_clash_sounds()
{
    this->m_clash_sounds[ 0 ] = new sound( CLASH1_NUM );
    this->m_clash_sounds[ 1 ] = new sound( CLASH2_NUM );
}

void
sound_manager::init_spin_sounds()
{
    this->m_spin_sounds[ 0 ] = new sound( SPIN1_NUM );
    this->m_spin_sounds[ 1 ] = new sound( SPIN2_NUM );
}
