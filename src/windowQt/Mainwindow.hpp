/**
 * Mainwindow.hpp : You can found here the Mainwindow class.
 * Author : Quentin.
 * */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QApplication>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

#include <QFile>
#include <QDialog>
#include <QTextEdit>
#include <QMouseEvent>
#include <QPalette>

// Include my files.
#include "Tiltewidget.hpp"
#include "Treewidget.hpp"
#include "Mytextedit.hpp"
#include "Mybutton.hpp"
#include "../lib/Writer.hpp"
#include "../lib/Tree.hpp"
#include "../lib/Parser.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Constructor */
    MainWindow(QWidget* parent = nullptr);

    /* Function */
    void setWidth(int);
    void setHeight(int);
    void setup();

    /* Destructor */
    ~MainWindow();

private:
    /* Data */
    int winWidth, winHeight; // sizeX, sizeY

    QWidget* mainWidget = nullptr;
    TreeWidget* treeWidget = nullptr;

    QGridLayout* keypadLayout = nullptr;
    QHBoxLayout *readerLayout = nullptr, *writerLayout = nullptr;
    MyTextEdit *reader = nullptr, *writer = nullptr;

    QList<QPushButton*> listButton;
    
    bool isEncoding = false; bool treeIsDrawing = false;
    int maxDepth = 5;
    QString readerSave, writerSave;

    std::vector<Data> tabFreq;

    /* Functions */
    void resetWindow(int newWidth, int newHeight);
    void setupMenu();
    void printMenu();

public slots:
    void menu();
    void menuEncoding();
    void menuDecoding();
    void clearTextEdit();

    void encoding();
    void decoding();
    void drawTree();
};
#endif // MAINWINDOW_HPP
