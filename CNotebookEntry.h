//
// Created by tonglt on 6/3/19.
//

#ifndef TINYNOTE_CNOTEBOOKENTRY_H
#define TINYNOTE_CNOTEBOOKENTRY_H

#include <chrono>
#include <fstream>
#include <string>

class CNotebookEntry {
public:
    virtual std::string Name() = 0;

    virtual std::chrono::system_clock::time_point CreateTime() = 0;

    virtual std::chrono::system_clock::time_point LastModifiedTime() = 0;

    virtual std::chrono::system_clock::time_point LastAccessTime() = 0;

    virtual std::string Author() = 0;


    virtual void Save(std::string &output_para) = 0;

    virtual void Load(std::ifstream &ifs) = 0;

private:

    std::string m_file_full_path;


};


#endif //TINYNOTE_CNOTEBOOKENTRY_H
