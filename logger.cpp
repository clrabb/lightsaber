#include "logger.h"

void
logger::print( const char* message )
{
#ifdef __DEBUG_LOGGING__
    this->stream().print( message );
#endif
}

void
logger::println( const char* message )
{
#ifdef __DEBUG_LOGGING__
    this->stream().println( message );
#endif
}

void 
logger::print( uint8_t number )
{
    const int BUFF_SIZE = 100;
    char buffer[ BUFF_SIZE ];

    itoa( number, buffer, 10  );

    this->print( buffer );
}


void 
logger::println( uint8_t number )
{
    const int BUFF_SIZE = 100;
    char buffer[ BUFF_SIZE ];

    itoa( number, buffer, 10  );

    this->println( buffer );
}
