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
        OK = 200,
        FILE = 201,
        ERROR = 400,
    };
};

#endif // FAITHCORE_H
