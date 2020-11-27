#include "Mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent, int winSizeX, int winSizeY)
    : QMainWindow(parent = nullptr)
{
    setWindowTitle("Huffman Coding");
    setFixedWidth((winWidth = winSizeX/4));
    setFixedHeight((winHeight = winSizeY/4));

    printMenu();
}

void MainWindow::printMenu() {
    mainWidget = new TilteWidget(this, winWidth, winHeight);

    //
    keypadLayout = new QGridLayout(mainWidget);

    //
    numButton = 2;
    for(int i=0; i < numButton; ++i) {
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

    //
    setCentralWidget(mainWidget);
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
    numButton = 2;
    for(int i=0; i < numButton; ++i) {
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

    //
    // Writer writer("../txtQt/textToCode.txt");
    // writer.
}

void MainWindow::printDecoding()
{
    resetWindow(winWidth*2, winHeight*2);
}

void MainWindow::resetWindow(int newWidth, int newHeight)
{
    //
    setFixedWidth((winWidth = newWidth));
    setFixedHeight((winHeight = newHeight));

    //
    numButton = 0;
    listButton.clear();
    keypadLayout = nullptr;

    //
    setCentralWidget(nullptr);
}

MainWindow::~MainWindow() {}
