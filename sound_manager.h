#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "sound.h"
#include "interrupt_sound.h"
#include "repeating_sound.h"

class sound_manager
{
private:

    // Constants
    //
    enum sounds
    {
        HUM_NUM         = 0,  
        POWERON_NUM     = 1, 
        POWEROFF_NUM    = 2,
        SWING1_NUM      = 3,
        SWING2_NUM      = 4,
        CLASH1_NUM      = 5,
        CLASH2_NUM      = 6,
        SPIN1_NUM       = 7,
        SPIN2_NUM       = 8   
    };

    static const short NUM_SWING_SOUNDS = 2;
    static const short NUM_CLASH_SOUNDS = 2;
    static const short NUM_SPIN_SOUNDS  = 2;

    // Members
    //
    interrupt_sound* m_swing_sounds[ NUM_SWING_SOUNDS ];
    interrupt_sound* m_clash_sounds[ NUM_CLASH_SOUNDS ];
    interrupt_sound* m_spin_sounds[  NUM_SPIN_SOUNDS  ];
    repeating_sound* m_background_sound;
    sound* m_current_sound;

    // Initialization
    //
    void init_swing_sounds();
    void init_clash_sounds();
    void init_spin_sounds();
    void init_background_sound();

    // Getters/setters
    //
    void current_sound( sound* a_sound ) { this->m_current_sound = a_sound; } 
    sound* current_sound() { return this->m_current_sound; }
    
    void background_sound( repeating_sound* a_sound ){ this->m_background_sound = a_sound; }
    repeating_sound* background_sound(){ return this->m_background_sound; }
    

public:

    // Behavior
    //
    void play_random_clash();
    void play_random_swing();
    void play_random_spin();
    void play_background();
    void play();

    // Testing
    //
    boolean is_playing();

    // Give some time to the manager
    //
    void tick();
    void tick_from_repeating_sound( sound& a_sound );
    void tick_from_sound( sound& a_sound );
    
public:
    sound_manager();

    
private:
    sound_manager( const sound_manager& );
    sound_manager& operator=( const sound_manager& );  
};

#endif // SOUND_MANAGER_H
