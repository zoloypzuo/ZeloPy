// BufferedInputStream.cpp
// created on 2020/2/26
// author @zoloypzuo

#include "BufferedInputStream.h"

using namespace Zelo;

int BufferedInputStream::read_int() {
//    spdlog::debug_section("BufferedInputStream::read_int()");
    U32 b1 = (read() & 0xffu);
    U32 b2 = (read() & 0xffu) << 8u;
    U32 b3 = (read() & 0xffu) << 16u;
    U32 b4 = (read() & 0xffu) << 24u;
//    spdlog::debug("b1={},b2={},b3={},b4={}", b1, b2, b3, b4);
    return static_cast<int>(b4 | b3 | b2 | b1);
}

void BufferedInputStream::unread() {
    index--;
}

char BufferedInputStream::read() {
    if (index < BUFFER_LEN) {
        return zsBuffer[index++];
    } else {
        index = 0;
        m_BytesRead = fread(zsBuffer, BUFFER_LEN * sizeof(char), 1, fp);
        return zsBuffer[index++];
    }
}

BufferedInputStream::~BufferedInputStream() {
    close();
}

BufferedInputStream::BufferedInputStream(const char *filename) {
    fp = fopen(filename, "rb");
    int err{};
    if (!fp) {
        spdlog::error("failed to open file={}", filename);
        assert(false);
    }

    m_BytesRead = fread(zsBuffer, 1, BUFFER_LEN * sizeof(char), fp);
    err = ferror(fp);
    if (err) {
        spdlog::error("failed to read file, err={}", err);
        assert(false);
    }
    index = 0;
}

void BufferedInputStream::close() {
    if (fp) {
        fclose(fp);
        auto err = ferror(fp);
        if (err) {
            spdlog::error("failed to close file, err={}", err);
            assert(false);
        }
        fp = nullptr;
    }
}
