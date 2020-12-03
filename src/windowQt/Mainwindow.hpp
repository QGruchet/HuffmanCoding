#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QApplication>

#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

#include <QFile>
#include <QDialog>
#include <QTextEdit>

#include "Tiltewidget.hpp"
#include "Treewidget.hpp"
#include "../lib/Writer.hpp"
#include "../lib/Parser.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Constructor */
    MainWindow(QWidget*, int, int);

    /* Destructor */
    ~MainWindow();

private:
    /* Data */
    int winWidth, winHeight; // sizeX, sizeY

    QWidget* mainWidget = nullptr;

    QGridLayout* keypadLayout = nullptr;

    QHBoxLayout *readerLayout = nullptr, *writerLayout = nullptr;
    QTextEdit *reader = nullptr, *writer = nullptr;
    
    QList<QPushButton*> listButton;
    
    bool isEncoding = false;
    bool treeIsDraw = false;
    QTextEdit *readerSave = nullptr, *writerSave = nullptr;

    /* Functions */
    void resetWindow(int newWidth, int newHeight);
    void setupMenu();
    void printMenu();

public slots:
    void menuEncoding();
    void clearEncoding();
    void menuDecoding();
    void menu();

    void encoding();
    void drawTree();
};
#endif // MAINWINDOW_HPP
