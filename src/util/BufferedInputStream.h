// BufferedInputStream.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_BUFFEREDINPUTSTREAM_H
#define RAILGUN_BUFFEREDINPUTSTREAM_H

#include "common.h"

#define BUFFER_LEN 256

class BufferedInputStream {
private:
    FILE *fp{};
    char zsBuffer[BUFFER_LEN]{};
    Zelo::U16 index{};
    size_t m_BytesRead{};

public:
    explicit BufferedInputStream(char const *filename);

    ~BufferedInputStream();

    void close();

    char read();

    int read_int();

    void unread();
};


#endif //RAILGUN_BUFFEREDINPUTSTREAM_H