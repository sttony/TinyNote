#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>

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

    // Add some widgets to the layout
    auto* button1 = new QPushButton("Button 1");
    auto* label = new QLabel("Label");
    auto* button2 = new QPushButton("Button 2");
    layout->addWidget(button1);
    layout->addWidget(label);
    layout->addWidget(button2);
    centralWidget->setLayout(layout);

    // Show the main window
    mainWindow.show();

    // Run the application event loop
    return QApplication::exec();
}
