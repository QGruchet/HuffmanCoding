#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QApplication>
#include <QDebug>

#include <QGridLayout>
#include <QPushButton>

#include <QTextEdit>


#include "Tiltewidget.hpp"

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

    QWidget* mainWidget;

    QGridLayout* keypadLayout;

    QHBoxLayout *readerLayout, *writerLayout;
    QTextEdit *reader, *writer;

    int numButton;
    QList<QPushButton*> listButton;

    /* Functions */
    void resetWindow(int newWidth, int newHeight);
    void printMenu();

public slots:
    void printEncoding();
    void printDecoding();

    void encoding();
};
#endif // MAINWINDOW_HPP
