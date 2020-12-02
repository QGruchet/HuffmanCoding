#include "Mainwindow.hpp"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent, int winSizeX, int winSizeY)
    : QMainWindow(parent = nullptr)
{
    setWindowTitle("Huffman Coding");
    winWidth = winSizeX/4;
    winHeight = winSizeY/4;
    setFixedWidth(winWidth);
    setFixedHeight(winHeight);

    printMenu();
}

void MainWindow::printMenu() {
    //
    if(mainWidget) {
        resetWindow(winWidth, winHeight);
    }
    
    mainWidget = new TilteWidget(this, winWidth, winHeight);
    keypadLayout = new QGridLayout(mainWidget);
    setCentralWidget(mainWidget);

    //
    for(int i=0; i < 2; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
        keypadLayout->addWidget(newButton, 0, i);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    //
    listButton.at(0)->setText("Encoding");
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(printEncoding()));
    listButton.at(0)->setToolTip("Encoding a text");
    listButton.at(1)->setText("Decoding");
    connect(listButton.at(1), SIGNAL(clicked()), this, SLOT(printDecoding()));
    listButton.at(1)->setToolTip("Decoding a text");

}

void MainWindow::printEncoding()
{
    resetWindow(winWidth*2, winHeight*2);

    //
    mainWidget = new QWidget(this);

    //
    readerLayout = new QHBoxLayout(mainWidget);
    writerLayout = new QHBoxLayout;
    keypadLayout = new QGridLayout;

    //
    for(int i=0; i < 2; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
        keypadLayout->addWidget(newButton, i, 0);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    //
    listButton.at(0)->setText("Exit");
    connect(listButton.at(0), SIGNAL(clicked()), qApp, SLOT(quit()));
    listButton.at(0)->setToolTip("Leave the application");
    listButton.at(1)->setText("encoding");
    connect(listButton.at(1), SIGNAL(clicked()), this, SLOT(encoding()));
    listButton.at(1)->setToolTip("Encoding the current text");

    //
    reader = new QTextEdit();
    readerLayout->addWidget(reader);
    writer = new QTextEdit();
    writer->setReadOnly(true);
    writerLayout->addWidget(writer);
    readerLayout->addLayout(writerLayout);
    readerLayout->addLayout(keypadLayout);

    //
    setCentralWidget(mainWidget);
}

void MainWindow::encoding()
{
    //
    reader->setReadOnly(true);

    //
    QString read;
    read = reader->toPlainText();
    std::string strRead = read.toStdString();
    if(strRead.length() == 0) {
        QMessageBox::information(mainWidget, "Error message", "Too short message.\nBack to the menu.");
        printMenu();
        return;
    }

    //
    Writer writerInFile("src/txtQt/text.txt");
    writerInFile.textToCode(strRead);

    //
    QString fileName = "src/txtQt/code.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);
    QString code = flux.readAll();

    //
    writer->setText(code);
    writer->show();

    //
    file.close();
}

void MainWindow::printDecoding()
{
    resetWindow(winWidth*2, winHeight*2);
    mainWidget = new QWidget(this);
    QMessageBox::information(mainWidget, "Information", "Not implented yet.\nBack to the menu.");
    printMenu();
}

void MainWindow::resetWindow(int newWidth, int newHeight)
{
    //
    setFixedWidth(newWidth);
    setFixedHeight(newHeight);

    //
    if(mainWidget) {
        mainWidget = nullptr;
        setCentralWidget(nullptr);
    }

    if(keypadLayout) {
        keypadLayout = nullptr;
    }

    if(readerLayout) {
        readerLayout = nullptr;
    }

    if(writerLayout) {
        writerLayout = nullptr;
    }

    if(reader) {
        reader = nullptr;
    }

    if(writer) {
        writer = nullptr;
    }

    if(!listButton.empty()) {
        listButton.clear();
    }
}

MainWindow::~MainWindow() {}
