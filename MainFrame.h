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
#include <wx/treectrl.h>

class MainFrame : public wxFrame {

public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnHello(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnAbout(wxCommandEvent &event);

wxDECLARE_EVENT_TABLE();

    wxMenu *m_menuFile;
    wxMenu *m_menuHelp;
    wxMenuBar *m_menuBar;
    wxTreeCtrl *m_navTree;

    void createMenu();
};

enum {
    ID_Hello = 1
};


#endif //TINYNOTE_MAINFRAME_H
