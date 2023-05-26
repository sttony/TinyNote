//
// Created by sttony on 5/16/23.
//

#include <QVBoxLayout>
#include <QTreeWidgetItem>
#include <QFileDialog>
#include "MainWindow.h"
#include "CNoteBook.h"

void MainWindow::contextMenuEvent(QContextMenuEvent *event) {
    QMainWindow::contextMenuEvent(event);
}

MainWindow::MainWindow() {
    auto *widget = new QWidget;
    setCentralWidget(widget);

    auto *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    // Create a horizontal layout
    auto* layout = new QHBoxLayout;

    auto* treeWidget = new QTreeWidget;
    auto *item1 = new QTreeWidgetItem(treeWidget, QStringList("Item 1"));
    auto *item2 = new QTreeWidgetItem(treeWidget, QStringList("Item 2"));
    auto *item3 = new QTreeWidgetItem(item2, QStringList("Item 3"));
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabels(QStringList("Tree Widget"));

    auto* label = new QLabel("Label");

    layout->addWidget(treeWidget, 3);
    layout->addWidget(label, 7);
    centralWidget->setLayout(layout);
    createActions();
    createMenus();

//    QString message = tr("A context menu is available by right-clicking");
//    statusBar()->showMessage(message);

//    setWindowTitle(tr("Menus"));
//    setMinimumSize(160, 160);
    resize(480, 320);
}

void MainWindow::newFile() {

}

void MainWindow::open() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", "", "All Files (*.*)");
    // Check if a file was selected
    if (filePath.isEmpty()) {

    }
    CNoteBook::Open(filePath.toStdString());
}

void MainWindow::save() {

}

void MainWindow::createActions() {
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
//    fileMenu->addAction(saveAct);
//    fileMenu->addAction(printAct);
   fileMenu->addSeparator();
//    fileMenu->addAction(exitAct);
}

void MainWindow::undo() {

}

void MainWindow::print() {

}

void MainWindow::bold() {

}

void MainWindow::copy() {

}

void MainWindow::setParagraphSpacing() {

}

void MainWindow::aboutQt() {

}

void MainWindow::setLineSpacing() {

}

void MainWindow::rightAlign() {

}

void MainWindow::about() {

}

void MainWindow::center() {

}

void MainWindow::justify() {

}

void MainWindow::leftAlign() {

}

void MainWindow::italic() {

}

void MainWindow::paste() {

}

void MainWindow::redo() {

}

void MainWindow::cut() {

}
