//
// Created by tonglt on 4/16/19.
//

#ifndef TINYNOTE_MAINFRAME_H
#define TINYNOTE_MAINFRAME_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include <memory>

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

wxDECLARE_EVENT_TABLE();

    std::shared_ptr<wxMenu> m_menuFile;
    std::shared_ptr<wxMenu> m_menuHelp;
    std::shared_ptr<wxMenuBar> m_menuBar;

};

enum {
    ID_Hello = 1
};


#endif //TINYNOTE_MAINFRAME_H
