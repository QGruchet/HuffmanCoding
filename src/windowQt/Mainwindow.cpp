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
    for(int i=0; i<3; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
        keypadLayout->addWidget(newButton, 0, i);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    //
    listButton.at(0)->setText("Encoding");
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menuEncoding()));
    listButton.at(0)->setToolTip("Encoding a text");
    listButton.at(1)->setText("Exit");
    connect(listButton.at(1), SIGNAL(clicked()), qApp, SLOT(quit()));
    listButton.at(1)->setToolTip("Leave the application");
    listButton.at(2)->setText("Decoding");
    connect(listButton.at(2), SIGNAL(clicked()), this, SLOT(menuDecoding()));
    listButton.at(2)->setToolTip("Decoding a text");
}

void MainWindow::menu() {
    isEncoding = false;
    printMenu();
}

void MainWindow::menuEncoding()
{
    //
    resetWindow(winWidth*2, winHeight*2);
    mainWidget = new QWidget(this);
    readerLayout = new QHBoxLayout(mainWidget);
    writerLayout = new QHBoxLayout;
    keypadLayout = new QGridLayout;

    //
    for(int i=0; i<5; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
        keypadLayout->addWidget(newButton, i, 0);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    //
    listButton.at(0)->setText("Menu");
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menu()));
    listButton.at(0)->setToolTip("Back to the menu");
    listButton.at(1)->setText("Exit");
    connect(listButton.at(1), SIGNAL(clicked()), qApp, SLOT(quit()));
    listButton.at(1)->setToolTip("Leave the application");
    listButton.at(2)->setText("Encoding");
    connect(listButton.at(2), SIGNAL(clicked()), this, SLOT(encoding()));
    listButton.at(2)->setToolTip("Encoding the current text");
    listButton.at(3)->setText("Clear");
    connect(listButton.at(3), SIGNAL(clicked()), this, SLOT(clearEncoding()));
    listButton.at(3)->setToolTip("Clean the window");
    listButton.at(4)->setText("Print tree");
    connect(listButton.at(4), SIGNAL(clicked()), this, SLOT(drawTree()));
    listButton.at(4)->setToolTip("Print the Huffman tree");

    //
    reader = new QTextEdit();
    readerLayout->addWidget(reader);
    writer = new QTextEdit();
    writer->setReadOnly(true);
    writerLayout->addWidget(writer);
    readerLayout->addLayout(writerLayout);
    readerLayout->addLayout(keypadLayout);

    //
    if(treeIsDrawing) {
        treeIsDrawing = false;
        reader->setText(readerSave);
        readerSave = "\0";
        reader->show();
        writer->setText(writerSave);
        writerSave = "\0";
        writer->show();
    }

    //
    setCentralWidget(mainWidget);
}

bool checkASCII(std::string str) {
    for(char c : str) {
        if(!(int(c) >= 0 && int(c) <= 127)) {
            return false;
        }
    }
    return true;
}

bool isOnlyOneChar(std::string str) {
    for(int i=1; i<int(str.size()); ++i) {
        if(str[i-1] != str[i]) {
            return false;
        }
    }
    return true;
}

void MainWindow::encoding()
{
    //
    QString read;
    read = reader->toPlainText();
    std::string strRead = read.toStdString();
    if(strRead.length() <= 1) {
        QMessageBox::information(mainWidget, "Error message", "Too short message.");
        reader->setReadOnly(false);
    }
    else if(!checkASCII(strRead)) {
        QMessageBox::information(mainWidget, "Error message", "Caractere not supported.");
        reader->setReadOnly(false); // User can write now;
    }
    else if(isOnlyOneChar(strRead)) {
        QMessageBox::information(mainWidget, "Error message", "Not enought different caracters.");
        reader->setReadOnly(false);
    }
    else {
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
        
        file.close(); //
        isEncoding = true; //
    }
}

void MainWindow::clearEncoding() {
    reader->clear();
    reader->setReadOnly(false);
    writer->clear();
    reader->setReadOnly(false);
    isEncoding = false; treeIsDrawing = false;
}

void MainWindow::drawTree() {
    if(!isEncoding) {
        QMessageBox::information(mainWidget, "Information", "Any text endocing yet.");
    }
    else {
        //
        Parser parser;
        ArbreB huffmanTree = parser.creatHuffmanTree(parser.freqChar("src/txtQt/text.txt"));

        //
        treeIsDrawing = true;
        readerSave = reader->toPlainText(); writerSave = writer->toPlainText();
        if(huffmanTree.getRoot()->countDepth() >= maxDepth ) {
            QMessageBox::information(mainWidget, "Error message", "HuffmanTree is too big to be drawing");
        }
        else {
            resetWindow(winWidth*2, winHeight*2); //
            mainWidget = new QWidget(this);
            treeWidget = new TreeWidget();
            treeWidget->setTree(huffmanTree);

            writerLayout = new QHBoxLayout(mainWidget);
            writerLayout->addWidget(treeWidget);
            
            keypadLayout = new QGridLayout();
            QPushButton* newButton = new QPushButton("Back");
            newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
            listButton.append(newButton);
            keypadLayout->addWidget(newButton, 0, 0);
            connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menuEncoding()));
            listButton.at(0)->setToolTip("Back to the encoding menu");

            writerLayout->addLayout(keypadLayout);
            setCentralWidget(mainWidget);
        }
    }
}

void MainWindow::menuDecoding()
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
