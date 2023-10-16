#include <QApplication>

#include <QMainWindow>

#include <QTextEdit>

#include <QMenuBar>

#include <QMenu>

#include <QAction>

#include <QFileDialog>

 

class TextEditor : public QMainWindow {

   Q_OBJECT

 

public:

   TextEditor(QWidget *parent = 0) : QMainWindow(parent) {

       textEdit = new QTextEdit(this);

       setCentralWidget(textEdit);

 

       createActions();

       createMenus();

 

       setWindowTitle("Simple Text Editor");

       resize(800, 600);

   }

 

private slots:

   void newFile() {

       textEdit->clear();

       currentFile.clear();

   }

 

   void open() {

       QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");

       if (!fileName.isEmpty()) {

           QFile file(fileName);

           if (file.open(QFile::ReadOnly | QFile::Text)) {

               QTextStream in(&file);

               textEdit->setPlainText(in.readAll());

               currentFile = fileName;

           }

       }

   }

 

   void save() {

       if (currentFile.isEmpty()) {

           saveAs();

       } else {

           QFile file(currentFile);

           if (file.open(QFile::WriteOnly | QFile::Text)) {

               QTextStream out(&file);

               out << textEdit->toPlainText();

           }

       }

  }

 

   void saveAs() {

       QString fileName = QFileDialog::getSaveFileName(this, "Save As", "", "Text Files (*.txt);;All Files (*)");

       if (!fileName.isEmpty()) {

           currentFile = fileName;

           save();

       }

   }

 

private:

   void createActions() {

       newAction = new QAction(tr("&New"), this);

       newAction->setShortcuts(QKeySequence::New);

       connect(newAction, &QAction::triggered, this, &TextEditor::newFile);

 

       openAction = new QAction(tr("&Open..."), this);

       openAction->setShortcuts(QKeySequence::Open);

       connect(openAction, &QAction::triggered, this, &TextEditor::open);

 

       saveAction = new QAction(tr("&Save"), this);

       saveAction->setShortcuts(QKeySequence::Save);

      connect(saveAction, &QAction::triggered, this, &TextEditor::save);

 

       saveAsAction = new QAction(tr("Save &As..."), this);

       connect(saveAsAction, &QAction::triggered, this, &TextEditor::saveAs);

   }

 

   void createMenus() {

       fileMenu = menuBar()->addMenu(tr("&File"));

       fileMenu->addAction(newAction);

       fileMenu->addAction(openAction);

       fileMenu->addAction(saveAction);

       fileMenu->addAction(saveAsAction);

   }

 

   QTextEdit *textEdit;

   QString currentFile;

 

   QMenu *fileMenu;

   QAction *newAction;

   QAction *openAction;

   QAction *saveAction;

   QAction *saveAsAction;

};

 

int main(int argc, char *argv[]) {

   QApplication app(argc, argv);

 

   TextEditor editor;

   editor.show();

 

   return app.exec();

}