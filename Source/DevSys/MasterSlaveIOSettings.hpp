#ifndef MASTER_SLAVE_INPUT_OUTPUT_SETTINGS_HEADER_INCLUDED____
#define MASTER_SLAVE_INPUT_OUTPUT_SETTINGS_HEADER_INCLUDED____

struct MasterSlaveIOSettings
{
    unsigned tmWriteDelay_, timeOut_, silentTime_, repeatCount_;
    bool mustLogData_;
};



#endif
