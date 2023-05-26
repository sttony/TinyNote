//
// Created by tonglt on 6/3/19.
//

#ifndef TINYNOTE_CNOTEBOOK_H
#define TINYNOTE_CNOTEBOOK_H

static const char* const PAGE_LIST_NAME = "PageList";

#include <string>
#include <memory>
#include "CNotePage.h"

class CNoteBook {
public:
    static int Open(const std::string& root_folder);
    static int ReopenNoteBook();

    static CNoteBook* getCurrentInstance() {
        return s_currentNoteBook;
    };

    int Close();
    std::string GetName();
    std::string GetFileName();

private:

    std::string m_file_name;
    std::string m_NB_name;

    std::vector<std::shared_ptr<CNotePage> > m_Pages;

    static CNoteBook* s_currentNoteBook;

    void StoreNoteBookPath(const std::string& root_folder);

};

#endif //TINYNOTE_CNOTEBOOK_H
