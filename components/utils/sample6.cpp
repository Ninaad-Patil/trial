#include <QtWidgets>
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QMainWindow mainWindow;    QWidget centralWidget;
    QPushButton button("Click Me", &centralWidget);

    QObject::connect(&button, &QPushButton::clicked, [&] {
        QMessageBox::information(&mainWindow, "Message", "Hello from RHEL 6.0 and lower!");
    });

    mainWindow.setCentralWidget(&centralWidget);
    mainWindow.show();

    return app.exec();
}