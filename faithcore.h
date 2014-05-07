#ifndef FAITHCORE_H
#define FAITHCORE_H


class Faithcore
{

public:
    Faithcore();
    enum MessageCode
    {
        AUTH = 100,
        SAVE_CONFIG = 101,
        GET_CONFG = 110,
        GET_HOSTS_LIST,
        GET_HOST,
        GET_LAB_LIST,
        REQUEST_IP,
        OK = 200,
        ERROR = 400,
    };
    enum DataType
    {
        NOTHING,
        FILE,
        STRING,
        IP
    };
};

#endif // FAITHCORE_H
