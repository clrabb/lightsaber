#include "movement.h"


bool 
movement::has_clashed()
{
    this->change();
    return CLASH == this->m_current_effect;
}

bool 
movement::has_swung()
{
    this->change();
    return SWING == this->m_current_effect;
}

bool 
movement::has_spun()
{
    this->change();
    return SPIN == this->m_current_effect;
}

bool 
movement::should_change()
{
    long millis_since_last_change = millis() - this->m_last_change_millis;
    
    return ( millis_since_last_change >= this->m_next_change_interval_millis );
}

void
movement::change()
{
    if ( this->should_change() )
    {
        long next_interval = this->generate_next_change_interval();
        this->m_current_effect = random( 2 );
        this->m_next_change_interval_millis = next_interval;
        this->m_last_change_millis = millis();
    }
}
   
long 
movement::generate_next_change_interval()
{
    return random( 20, 5000 );
}
