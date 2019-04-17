// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include "MainFrame.h"

class TinyNodeApp : public wxApp {
public:
    bool OnInit() override;
};


wxIMPLEMENT_APP(TinyNodeApp);

bool TinyNodeApp::OnInit() {
    MainFrame *frame = new MainFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}


