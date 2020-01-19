#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "sound.h"

class sound_manager
{
private:

    // Constants
    //
    enum sounds
    {
        HUM_NUM,  
        POWERON_NUM, 
        POWEROFF_NUM,
        SWING1_NUM,
        SWING2_NUM,
        CLASH1_NUM,
        CLASH2_NUM,
        SPIN1_NUM,
        SPIN2_NUM   
    };

    static const short NUM_SWING_SOUNDS = 2;
    static const short NUM_CLASH_SOUNDS = 2;
    static const short NUM_SPIN_SOUNDS  = 2;

    // Members
    //
    sound* m_swing_sounds[ NUM_SWING_SOUNDS ];
    sound* m_clash_sounds[ NUM_CLASH_SOUNDS ];
    sound* m_spin_sounds[  NUM_SPIN_SOUNDS  ];
    sound* m_background_sound;

    // Initialization
    //
    void init_swing_sounds();
    void init_clash_sounds();
    void init_spin_sounds();

public:

    // Behavior
    //
    void play_random_clash();
    void play_random_swing();
    void play_random_spin();
    void play_background();
    
public:
    sound_manager();

    
private:
    sound_manager( const sound_manager& );
    sound_manager& operator=( const sound_manager& );  
};

#endif // SOUND_MANAGER_H
