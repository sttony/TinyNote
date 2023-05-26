//
// Created by tonglt on 9/5/19.
//

#ifndef TINYNOTE_CNOTEPAGE_H
#define TINYNOTE_CNOTEPAGE_H


#include <vector>
#include <memory>
#include "CNotebookEntry.h"
#include "CNotebookElement.h"

class CNotePage : public CNotebookEntry {
private:
    std::vector<std::shared_ptr<CNotebookElement>> m_Elements;
};


#endif //TINYNOTE_CNOTEPAGE_H
