#ifndef LOGGER_H
#define LOGGER_H

#include "lightsaber_consts.h"
#include <Stream.h>

#define __DEBUG_LOGGING__

class logger
{
private:
    Stream& m_stream;
    
public:
    logger( Stream& stream )
        : m_stream( stream )
    {
    }

    void print( const char* message );
    void print( uint8_t number );
    void println( const char* message );
    void println( uint8_t number );

private:
    Stream& stream() { return this->m_stream; }

private:
    logger();
    logger& operator=( const logger& );
    logger( const logger& );
};

#endif 
