#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "lightsaber_consts.h"
#include "lightsaber_types.h"

class movement
{
private:
    accelerometer* m_accel;
    long           m_last_change_millis;
    long           m_next_change_interval_millis;
    short          m_current_effect; 

    static const short CLASH = 0;
    static const short SWING = 1;
    static const short SPIN  = 2;
    
public:
    movement()
    {
        this->m_accel = new accelerometer( 12345 );
        this->m_current_effect = 0;
    }

private:
    accelerometer* accel() { return this->m_accel; }

public:
    bool has_clashed();
    bool has_swung();
    bool has_spun();
    bool should_change();
    void change();
    long generate_next_change_interval();
    

private:
    movement( const movement& );
    movement& operator=( const movement& );
};


#endif // MOVEMENT_H
