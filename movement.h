#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "lightsaber_consts.h"
#include "lightsaber_types.h"

class movement
{
private:
    accelerometer* m_accel;
    long           m_last_change;

public:
    movement()
    {
        this->m_accel = new accelerometer( 12345 );
    }

private:
    accelerometer* accel() { return this->m_accel; }

public:
    bool has_clashed();
    bool has_swung();
    bool has_spun();
    

private:
    movement( const movement& );
    movement& operator=( const movement& );
};


#endif // MOVEMENT_H
