#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QApplication>

#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

#include <QFile>
#include <QTextEdit>

#include "Tiltewidget.hpp"
#include "../lib/Writer.hpp"

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

    /* Functions */
    void resetWindow(int newWidth, int newHeight);
    void setupMenu();
    void printMenu();

public slots:
    void printEncoding();
    void printDecoding();

    void encoding();
};
#endif // MAINWINDOW_HPP
