#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QFileSystemModel>




int main(int argc, char *argv[])
{
    // Create a Qt application
    QApplication app(argc, argv);

    // Create a main window
    QMainWindow mainWindow;
    auto *centralWidget = new QWidget(&mainWindow);
    mainWindow.setCentralWidget(centralWidget);
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

    // Show the main window
    mainWindow.show();

    // Run the application event loop
    return QApplication::exec();
}
