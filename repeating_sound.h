#ifndef REPEATING_SOUND_H
#define REPEATING_SOUND_H

#include "interrupt_sound.h"

class repeating_sound : public interrupt_sound
{
private:
    long m_last_checked_millis;
    
public:
    repeating_sound( uint8_t sound_num );
    virtual void tick_impl( sound_manager& manager );

private:
    long last_checked_millis() { return this->m_last_checked_millis; }
    void last_checked_millis( long time_millis ) { this->m_last_checked_millis = time_millis; }    
    long last_checked_interval();


 private:
    repeating_sound();
    repeating_sound& operator=( const repeating_sound& );
    repeating_sound( const repeating_sound& );
};

#endif // REPEATING_SOUND_H
