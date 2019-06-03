//
// Created by tonglt on 6/3/19.
//

#ifndef TINYNOTE_CNOTEBOOKELEMENT_H
#define TINYNOTE_CNOTEBOOKELEMENT_H

#include <vector>
#include <memory>

class CNotebookElement {
public:


private:
    std::vector<std::shared_ptr<CNotebookElement>> m_children;


};


#endif //TINYNOTE_CNOTEBOOKELEMENT_H
