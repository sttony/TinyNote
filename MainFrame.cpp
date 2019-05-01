//
// Created by tonglt on 4/16/19.
//

#include "MainFrame.h"


wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
                EVT_MENU(ID_Open_Notebook, MainFrame::OnOpenNotebook)
                EVT_MENU(wxID_EXIT, MainFrame::OnExit)
                EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
wxEND_EVENT_TABLE()


MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {
    createMenu();
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    wxPanel *panel = new wxPanel(this, wxID_ANY);
    m_navTree = new wxTreeCtrl(panel, wxID_ANY,
                               wxDefaultPosition, wxSize(250, 200));
    wxTreeItemId rootId = m_navTree->AddRoot("Root");
    m_navTree->AppendItem(rootId, "Node 1");
    wxTreeItemId child2Id = m_navTree->AppendItem(rootId, "Node 2");
    m_navTree->AppendItem(child2Id, "Child of node 2");
    m_navTree->AppendItem(rootId, "Node 3");

    // Expand all the nodes
    m_navTree->ExpandAll();

    // TextArea
    wxTextCtrl *MainEditBox;
    MainEditBox = new wxTextCtrl(this, 1, "Hi!", wxDefaultPosition, wxDefaultSize,
                                 wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);


    // Set up the sizer for the panel
    wxBoxSizer *panelSizer = new wxBoxSizer(wxHORIZONTAL);
    panelSizer->Add(m_navTree, 1, wxEXPAND);
    panelSizer->Add(MainEditBox, 2, wxEXPAND);

    panel->SetSizer(panelSizer);

    // Set up the sizer for the frame and resize the frame
    // according to its contents
    wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);
    topSizer->Add(panel, 1, wxEXPAND);
    SetSizerAndFit(topSizer);
}

void MainFrame::createMenu() {
    m_menuFile = new wxMenu;
    m_menuFile->Append(ID_Open_Notebook, "&Open...\tCtrl-O",
                       "Open Notebook folder");
    m_menuFile->AppendSeparator();
    m_menuFile->Append(wxID_EXIT);
    m_menuHelp = new wxMenu;
    m_menuHelp->Append(wxID_ABOUT);
    m_menuBar = new wxMenuBar;
    m_menuBar->Append(m_menuFile, "&File");
    m_menuBar->Append(m_menuHelp, "&Help");
    SetMenuBar(m_menuBar);
}

void MainFrame::OnExit(wxCommandEvent &event) {
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnOpenNotebook(wxCommandEvent &event) {
    wxDirDialog dlg(NULL, "Choose input directory", "",
                    wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

    if (dlg.ShowModal() == wxID_CANCEL)
        return;
    this->SetTitle(dlg.GetPath());
}