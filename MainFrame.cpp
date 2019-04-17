//
// Created by tonglt on 4/16/19.
//

#include "MainFrame.h"

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
                EVT_MENU(ID_Hello, MainFrame::OnHello)
                EVT_MENU(wxID_EXIT, MainFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    m_menuFile = std::make_shared<wxMenu>();
    m_menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                       "Help string shown in status bar for this menu item");
    m_menuFile->AppendSeparator();
    m_menuFile->Append(wxID_EXIT);
    m_menuHelp = std::make_shared<wxMenu>();
    m_menuHelp->Append(wxID_ABOUT);
    m_menuBar = std::make_shared<wxMenuBar>();
    m_menuBar->Append(m_menuFile.get(), "&File");
    m_menuBar->Append(m_menuHelp.get(), "&Help");
    SetMenuBar(m_menuBar.get());
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnHello(wxCommandEvent &event) {
    wxLogMessage("Hello world from wxWidgets!");
}