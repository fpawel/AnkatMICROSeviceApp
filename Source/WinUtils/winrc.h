//------------------------------------------------------------------------------
#ifndef winrcH
#define winrcH
//------------------------------------------------------------------------------
#include <utility>
typedef std::pair<void*, unsigned> RecourceBufferT;
RecourceBufferT MyGetResource( const char *name, const char *type);

//------------------------------------------------------------------------------

#endif
