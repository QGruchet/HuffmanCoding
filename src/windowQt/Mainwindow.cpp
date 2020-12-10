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
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Empty
}

void MainWindow::setWidth(int sizeX) {
    winWidth = sizeX/4;
}

void MainWindow::setHeight(int sizeY) {
    winHeight = sizeY/4;
}

void MainWindow::setup() {
    setWindowTitle("Huffman Coding");
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
    for(int i=0; i<2; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    // Button 1 : Encoding menu.
    listButton.at(0)->setText("Encoding");
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menuEncoding()));
    listButton.at(0)->setToolTip("Encoding a text");
    keypadLayout->addWidget(listButton.at(0), 0, 0);
    
    // Button 2 : Exit
    MyExitButton* exitButton = new MyExitButton(mainWidget);
    listButton.append(exitButton);
    keypadLayout->addWidget(exitButton, 0, 2);
    connect(listButton.at(2), SIGNAL(clicked()), qApp, SLOT(quit()));

    // Button 3 : Decoding menu
    listButton.at(1)->setText("Decoding");
    connect(listButton.at(1), SIGNAL(clicked()), this, SLOT(menuDecoding()));
    listButton.at(1)->setToolTip("Decoding a text");
    keypadLayout->addWidget(listButton.at(1), 0, 3);
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
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    mainWidget->setAutoFillBackground(true);
    mainWidget->setPalette(pal);
    setCentralWidget(mainWidget);
    keypadLayout = new QGridLayout(mainWidget);

    // Create buttons.
    for(int i=0; i<4; ++i) {
        QPushButton* newButton = new QPushButton(mainWidget);
        newButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        listButton.append(newButton);
    }
    keypadLayout->setAlignment(Qt::AlignCenter);

    // Button 1 : menu
    listButton.at(0)->setText("Menu");
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menu()));
    listButton.at(0)->setToolTip("Back to the menu");
    keypadLayout->addWidget(listButton.at(0), 0, 0);

    // Button 2 : Encoding
    listButton.at(1)->setText("Encoding");
    connect(listButton.at(1), SIGNAL(clicked()), this, SLOT(encoding()));
    listButton.at(1)->setToolTip("Encoding the current text");
    keypadLayout->addWidget(listButton.at(1), 2, 2);

    // Button 3 : print tree
    listButton.at(2)->setText("Print tree");
    connect(listButton.at(2), SIGNAL(clicked()), this, SLOT(drawTree()));
    listButton.at(2)->setToolTip("Print the Huffman tree");
    keypadLayout->addWidget(listButton.at(2), 1, 2);

    // Button 4 : clear
    listButton.at(3)->setText("Clear");
    connect(listButton.at(3), SIGNAL(clicked()), this, SLOT(clearEncoding()));
    listButton.at(3)->setToolTip("Clean the window");
    keypadLayout->addWidget(listButton.at(3), 0, 2);

    // Button 5 : exit
    MyExitButton* exitButton = new MyExitButton(mainWidget);
    listButton.append(exitButton);
    keypadLayout->addWidget(exitButton, 0, 4);
    connect(listButton.at(4), SIGNAL(clicked()), qApp, SLOT(quit()));

    // Setup reader.
    reader = new MyTextEdit();
    reader->setInfo("Entry text");
    reader->writeInfo();
    keypadLayout->addWidget(reader, 2, 1);

    // Setup writer.
    writer = new MyTextEdit();
    writer->setReadOnly(true); // ! User can't write, QtextEdit for print the convert text.
    writer->setInfo("Encoding");
    writer->writeInfo();
    keypadLayout->addWidget(writer, 2, 3);

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
    if(read != reader->info()) {
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
            writer->setTextColor(Qt::black);
            writer->setText(code);
            writer->show();
            file.close();
            isEncoding = true;
        }
    }
    else {
        QMessageBox::information(mainWidget, "Information", "Any text to encoding.");
    }
}

/**
 * *Description : Clear reader and writer in the encoding menu.
 * */
void MainWindow::clearEncoding() {
    reader->clear();
    reader->setReadOnly(false); // ! User can write.
    reader->writeInfo();

    writer->clear();
    writer->writeInfo();
    writer->setReadOnly(true); // ! User can't write.
    
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
