#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QFileSystemModel>
#include "MainWindow.h"



int main(int argc, char *argv[])
{
    // Create a Qt application
    QApplication app(argc, argv);

    // Create a main window
    MainWindow mainWindow;



    // Show the main window
    mainWindow.show();

    // Run the application event loop
    return QApplication::exec();
}
