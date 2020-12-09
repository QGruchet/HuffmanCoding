/**
 * Mainwindow.cpp : You can found here the Mainwindow class.
 * Author : Mickael.
 * */

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QApplication>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QScrollArea>

#include <QFile>
#include <QDialog>
#include <QTextEdit>

#include "Tiltewidget.hpp"
#include "Treewidget.hpp"
#include "../lib/Writer.hpp"
#include "../lib/Tree.hpp"
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
    TreeWidget* treeWidget = nullptr;

    QGridLayout* keypadLayout = nullptr;
    QHBoxLayout *readerLayout = nullptr, *writerLayout = nullptr;
    QTextEdit *reader = nullptr, *writer = nullptr;

    QList<QPushButton*> listButton;
    
    bool isEncoding = false;
    bool treeIsDrawing = false;
    int maxDepth = 5;
    QString readerSave, writerSave;

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
