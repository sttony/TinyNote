//
// Created by tonglt on 6/3/19.
//

#include "CNoteBook.h"

#include <string>
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "ErrorCode.h"
#ifdef _WIN32
#define  HOME "HOMEPATH"
#else
#define HOME "HOME"
#endif

namespace fs = boost::filesystem;
using namespace std;

CNoteBook* CNoteBook::s_currentNoteBook = nullptr;

int CNoteBook::Open(const std::string& root_folder) {
    if (s_currentNoteBook) {
        s_currentNoteBook->Close();
        delete s_currentNoteBook;
    }
    // check folder/index.json is exist
    fs::path dir(root_folder);
    fs::path file("index.json");
    fs::path full_path = dir / file;

    if (!boost::filesystem::exists(full_path)) {
        return ERR_FILE_NOT_FOUND;
    }

    s_currentNoteBook = new CNoteBook();
    boost::property_tree::ptree root;
    boost::property_tree::read_json(full_path.string(), root);
    s_currentNoteBook->m_NB_name = root.get<string>("title");
    s_currentNoteBook->m_file_name = root_folder;

    for (auto& page : root.get_child(PAGE_LIST_NAME)) {
        string name = page.second.data();
        cout << name << endl;
    }
    s_currentNoteBook->StoreNoteBookPath(root_folder);
    return 0;
}

int CNoteBook::Close() {
    return 0;
}

string CNoteBook::GetName() {
    return m_NB_name;
}

string CNoteBook::GetFileName() {
    return m_file_name;
}

void CNoteBook::StoreNoteBookPath(const string& root_folder) {
    fs::path dir(getenv(HOME));
    fs::path file(".tinynote");
    fs::path full_path = dir / file;

    ofstream ofs(full_path.string(), ios_base::out | ios_base::trunc);
    ofs << root_folder << endl;
}

int CNoteBook::ReopenNoteBook() {
    fs::path dir(getenv(HOME));
    fs::path file(".tinynote");
    fs::path full_path = dir / file;

    if (!boost::filesystem::exists(full_path)) {
        return ERR_FILE_NOT_FOUND;
    }

    ifstream ifs(full_path.string(), ios_base::in);
    string root_folder;
    ifs >> root_folder;

    return CNoteBook::Open(root_folder);
}