/**
 * Mainwidow.cpp : You can found here all functions implemented for
 * the Mainwidow class.
 * Author : Mickael.
 **/

#include "Mainwindow.hpp"

#include <QDebug>

/**
 * *Description : Constructor with parameter.
 * @param parent, the widget parent.
 * @param winSizeX, the window width.
 * @param winSizeY, the window height.
 * */
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

/**
 * *Description : Print the main menu.
 * */
void MainWindow::printMenu() {
    // Check if it's the first time we init the menu.
    if(mainWidget) {
        resetWindow(winWidth, winHeight);
    }
    
    // Init tilte.
    mainWidget = new TilteWidget(this, winWidth, winHeight);
    keypadLayout = new QGridLayout(mainWidget);
    setCentralWidget(mainWidget);

    // Create buttons.
    for(int i=0; i<3; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
        keypadLayout->addWidget(newButton, 0, i);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    // Setup buttons.
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

/**
 * *Description : Get back to the menu.
 * */
void MainWindow::menu() {
    isEncoding = false;
    printMenu();
}

/**
 * *Description : Print the encoding menu.
 * */
void MainWindow::menuEncoding()
{
    // Setup the main window.
    resetWindow(winWidth*2, winHeight*2);
    mainWidget = new QWidget(this);
    setCentralWidget(mainWidget);
    readerLayout = new QHBoxLayout(mainWidget);
    writerLayout = new QHBoxLayout;
    keypadLayout = new QGridLayout;

    // Create buttons.
    for(int i=0; i<5; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
        keypadLayout->addWidget(newButton, i, 0);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    // Setup buttons.
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

    // Setup writer and reader.
    reader = new QTextEdit();
    readerLayout->addWidget(reader);
    writer = new QTextEdit();
    writer->setReadOnly(true);
    writerLayout->addWidget(writer);
    readerLayout->addLayout(writerLayout);
    readerLayout->addLayout(keypadLayout);

    // If we drawing the tree and back to the menu.
    if(treeIsDrawing) {
        treeIsDrawing = false;
        reader->setText(readerSave);
        readerSave = "\0";
        reader->show();
        writer->setText(writerSave);
        writerSave = "\0";
        writer->show();
    }
}

/**
 * *Description : check if str recpect the ASCCI encoding.
 * @param str, need to check.
 * @return true/false.
 * */
bool checkASCII(std::string str) {
    for(char c : str) {
        if(!(int(c) >= 0 && int(c) <= 127)) {
            return false;
        }
    }
    return true;
}

/**
 * *Description : check if str is compose with only one char.
 * @param str, need to check.
 * @return true/false.
 * */
bool isOnlyOneChar(std::string str) {
    for(int i=1; i<int(str.size()); ++i) {
        if(str[i-1] != str[i]) {
            return false;
        }
    }
    return true;
}

/**
 * *Description : Read the current text and convert him.
 * */
void MainWindow::encoding()
{
    // Setup read the text
    QString read;
    read = reader->toPlainText();
    std::string strRead = read.toStdString();

    //
    if(strRead.length() <= 1) { // ! Not enought char for create the tree.
        QMessageBox::information(mainWidget, "Error message", "Too short message.");
        reader->setReadOnly(false); // User can write now;
    }
    else if(isOnlyOneChar(strRead)) { // ! Not enought char.
        QMessageBox::information(mainWidget, "Error message", "Not enought different caracters.");
        reader->setReadOnly(false);
    }
    else if(!checkASCII(strRead)) { // ! Text write by the user don't respect ASCII encoding.
        QMessageBox::information(mainWidget, "Error message", "Caractere not supported.");
        reader->setReadOnly(false); 
    }
    else {
        // Write the current text.
        Writer writerInFile("src/txtQt/text.txt");
        writerInFile.textToCode(strRead);

        // Read the convert text.
        QString fileName = "src/txtQt/code.txt";
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream flux(&file);
        QString code = flux.readAll();

        // Print the convert text.
        writer->setText(code);
        writer->show();
        file.close();
        isEncoding = true;
    }
}

/**
 * *Description : Clear reader and writer in the encoding menu.
 * */
void MainWindow::clearEncoding() {
    reader->clear();
    reader->setReadOnly(false);
    writer->clear();
    reader->setReadOnly(false);
    isEncoding = false; treeIsDrawing = false;
}

/**
 * *Description : Drawing the huffman tree.
 * */
void MainWindow::drawTree() {
    if(!isEncoding) { // ! Any text endocing yet.
        QMessageBox::information(mainWidget, "Information", "Any text endocing yet.");
    }
    else {
        // Create the tree.
        Parser parser;
        ArbreB huffmanTree = parser.creatHuffmanTree(parser.freqChar("src/txtQt/text.txt"));

        // Save the old text if user back at the menu.
        treeIsDrawing = true;
        readerSave = reader->toPlainText(); writerSave = writer->toPlainText();
        if(huffmanTree.getRoot()->countDepth() >= maxDepth ) { // ! Too many elements for be drawing.
            QMessageBox::information(mainWidget, "Error message", "HuffmanTree is too big to be drawing");
        }
        else {
            // Setup the main window.
            resetWindow(winWidth*2, winHeight*2);
            mainWidget = new QWidget(this);
            treeWidget = new TreeWidget();
            treeWidget->setTree(huffmanTree);
            writerLayout = new QHBoxLayout(mainWidget);
            writerLayout->addWidget(treeWidget);
            
            // Create and setup buttons.
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

/**
 * *Description : Print the decoding manu.
 * */
void MainWindow::menuDecoding()
{
    QMessageBox::information(mainWidget, "Information", "Not implented yet.\nBack to the menu.");
}

/**
 * *Description : Reset the main window and change the size.
 * */
void MainWindow::resetWindow(int newWidth, int newHeight)
{
    // CHange the size.
    setFixedWidth(newWidth);
    setFixedHeight(newHeight);

    // Reset all pointers.
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

/**
 * *Description : Destructor.
 * */
MainWindow::~MainWindow() 
{
    // Empty
}
