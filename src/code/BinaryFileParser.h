// BinaryFileParser.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_BINARYFILEPARSER_H
#define RAILGUN_BINARYFILEPARSER_H

#include "common.h"
#include "util/BufferedInputStream.h"
#include "util/ArrayList.h"
#include "object/HiObject.h"
#include "object/HiInteger.h"
#include "object/HiString.h"
#include "object/CodeObject.h"

class BinaryFileParser {
public:
    BinaryFileParser(BufferedInputStream *stream);

    CodeObject *parse();

private:
    CodeObject *get_code_object();

    HiString *get_byte_codes();

    HiString *get_no_table();

    int get_int();

    HiString *get_string();

    HiString *get_name();

    HiString *get_file_name();

    ArrayList<HiObject *> *get_consts();

    ArrayList<HiObject *> *get_names();

    ArrayList<HiObject *> *get_var_names();

    ArrayList<HiObject *> *get_free_vars();

    ArrayList<HiObject *> *get_cell_vars();

    ArrayList<HiObject *> *get_tuple();

private:
    BufferedInputStream *file_stream{};
    int cur{};
    ArrayList<HiString *> _string_table{};
};


#endif //RAILGUN_BINARYFILEPARSER_H