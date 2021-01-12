/**
 * Mainwidow.cpp : You can found here all functions implemented for
 * the Mainwidow class.
 * Author : Quentin.
 **/

#include "Mainwindow.hpp"

#include <QDebug>

// Icon path
#define iconClear "src/windowQt/icons/clear.png"
#define iconExit "src/windowQt/icons/exit.png"
#define iconHome "src/windowQt/icons/home.png"
#define iconTree "src/windowQt/icons/tree.png"
#define iconEncoding "src/windowQt/icons/encoding.jpg"

//
#define version "v3.3"

/**
 * *Description : Constructor with parameter.
 * @param parent, the widget parent.
 * */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Empty
}

/**
 * *Description : Set a new width.
 * @param sizeX, the widget sizeX.
 * */
void MainWindow::setWidth(int sizeX) {
    winWidth = sizeX/4;
}

/**
 * *Description : Set a new height.
 * @param sizeY, the widget sizeY.
 * */
void MainWindow::setHeight(int sizeY) {
    winHeight = sizeY/4;
}

/**
 * *Description : Setup the main window.
 * */
void MainWindow::setup() {
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
    
    // Init title.
    std::string title = "Huffman coding ";
    title += version;
    QString qtitle(title.c_str());
    setWindowTitle(qtitle);
    mainWidget = new TitleWidget(this, winWidth, winHeight);
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
    MyButton* exit = new MyButton(mainWidget, iconExit);
    exit->setToolTip("Leave the application.");
    listButton.append(exit);
    keypadLayout->addWidget(exit, 0, 2);
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
    isDecoding = false;
    printMenu();
}

/**
 * *Description : Setup buttons for encoding and decoding menu.
 * */
void MainWindow::setupButton() {

    // Button 2 : Print tree.
    MyButton* tree = new MyButton(mainWidget, iconTree);
    tree->setToolTip("Print the Huffman tree.");
    listButton.append(tree);
    keypadLayout->addWidget(tree, 1, 2);
    connect(tree, SIGNAL(clicked()), this, SLOT(drawTree()));

    // Button 3 : Clear.
    MyButton* clear = new MyButton(mainWidget, iconClear);
    clear->setToolTip("Clean the window.");
    listButton.append(clear);
    keypadLayout->addWidget(clear, 0, 2);
    connect(clear, SIGNAL(clicked()), this, SLOT(clearTextEdit()));

    // Button 4 : Menu.
    MyButton* home = new MyButton(mainWidget, iconHome);
    home->setToolTip("Back to the menu.");
    listButton.append(home);
    keypadLayout->addWidget(home, 0, 0);
    connect(home, SIGNAL(clicked()), this, SLOT(menu()));

    // Button 5 : Exit.
    MyButton* exit = new MyButton(mainWidget, iconExit);
    exit->setToolTip("Leave the application.");
    listButton.append(exit);
    keypadLayout->addWidget(exit, 0, 4);
    connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

/**
 * *Description : Print the encoding menu.
 * */
void MainWindow::menuEncoding() {

    //
    setWindowTitle("Encoding menu");
    
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
    keypadLayout->setAlignment(Qt::AlignCenter);

    // Button 1 : Encoding.
    MyButton* encoding = new MyButton(mainWidget, iconEncoding);
    encoding->setToolTip("Encoding the current text");
    listButton.append(encoding);
    keypadLayout->addWidget(encoding, 2, 2);
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(encoding()));

    //
    setupButton();

    // Setup reader.
    reader = new MyTextEdit();
    reader->setInfo("Exemple :\nbonjour");
    reader->writeInfo();
    keypadLayout->addWidget(reader, 2, 1);

    // Setup writer.
    writer = new MyTextEdit();
    writer->setReadOnly(true);
    writer->setInfo("011100100011000011");
    writer->setClicDellText(false);
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
 * *Description : Print the decoding manu.
 * */
void MainWindow::menuDecoding() {

    //
    setWindowTitle("Decoding menu");

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
    keypadLayout->setAlignment(Qt::AlignCenter);

    // Button 1 : Encoding.
    MyButton* decoding = new MyButton(mainWidget, iconEncoding);
    decoding->setToolTip("Decoding the current text");
    listButton.append(decoding);
    keypadLayout->addWidget(decoding, 2, 2);
    connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(decoding()));

    //
    setupButton();

    // Setup reader.
    reader = new MyTextEdit();
    reader->setInfo("Exemple :\n111110101000100011010001000\na1,u1, 1,e1,v1,o1,i1,r2");
    reader->writeInfo();
    keypadLayout->addWidget(reader, 2, 1);

    // Setup writer.
    writer = new MyTextEdit();
    writer->setReadOnly(true);
    writer->setInfo("au revoir");
    writer->setClicDellText(false);
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
bool checkASCII(std::string str, int& posError) {
    for(int i=0; i<str.length(); ++i) {
        char c = str[i];
        if(!(int(c) >= 0 && int(c) <= 127)) {
            posError = i;
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
    int sumEqChar = 0;
    for(int i=1; i<str.length(); ++i) {
        if(str[i-1] == str[i]) {
          sumEqChar++;
        }
    }

    return sumEqChar == (str.length() - 1);
}

/**
 * *Description : Read the current text and convert him.
 * */
void MainWindow::encoding() {
    // Setup read the text
    QString read;
    read = reader->toPlainText();
    if(read != reader->info()) {
        std::string strRead = read.toStdString();
        int posError = -1;

        //
        if(strRead.length() <= 1) { // ! Not enought char for create the tree.
            QMessageBox::information(mainWidget, "Error message", "Too short message.");
            reader->setReadOnly(false);
        }
        else if(!checkASCII(strRead, posError)) { // ! Text write by the user don't respect ASCII encoding.
            std::string errorMsg = "Caractere not supported,\nerror in positon : ";
            errorMsg += std::to_string(posError);
            errorMsg += " ('"; errorMsg += strRead[posError]; errorMsg += "')";
            QString qerrorMsg(errorMsg.c_str());
            QMessageBox::information(mainWidget, "Error message", qerrorMsg);
            reader->setReadOnly(false); 
        }
        else if(isOnlyOneChar(strRead)) { // ! Not enought char.
            QMessageBox::information(mainWidget, "Error message", "Not enought different caracters.");
            reader->setReadOnly(false);
        }
        else {
            // Write the current text.
            Writer writerInFile("src/txtQt/text.txt");
            writerInFile.textToCode(strRead);
            Parser parser;
            tabFreq = parser.freqChar("src/txtQt/text.txt");

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
 * *Description : check if str is a binary code
 * @param str : string we need to check.
 * @param posError : position of error if she exists.
 * @return false if it's not a binary code else true.
 * */
bool isOnlyBytes(std::string str, int& posError) {
    for(int i=0; i<str.length(); ++i) {
        char c = str[i];
        if(c != '0' && c != '1') {
            posError = i;
            return false;
        }
    }
    return true;
}

/**
 * *Description : check if table of frequence is good.
 * @tabFreqText, the table we have to check.
 * @posError, the position of the error if she exists.
 * */
bool tabFreqIsGood(std::vector<Data> tabFreqText, int& posError) {
    for(int i=0; i<(int)tabFreqText.size(); ++i) {
        Data data = tabFreqText[i];
        if(!((int)data.car >= 0 && (int)data.car <= 127)
        || !(data.freq > 0 && data.freq < INT64_MAX)) {
            posError = i;
            return false;
        }
    }
    return true;
}

/**
 * *Description : add a value in the vector given in parameters.
 * @param : tabFreq, the vector of frequence.
 * @param : newDate, the value we have to add.
 * */
void addInVectorData(std::vector<Data>& tabFreq, Data newData) {
    bool found = false;
    for(Data& data : tabFreq) {
        if(data.car == newData.car) {
            data.freq++;
            found = true;
        }
    }
    if(!found) {
        tabFreq.push_back(newData);
    }
}

/**
 * *Description : read the decoded text.
 * @param : text, the text we read at the end.
 * @param : binText, the binary code that we have to decode
 * @param : tabFreq, the frequence of car in the coded text.
 * */
void readDecoding(std::string text, std::string& binText, std::vector<Data>& tabFreq) {
    std::string firstLine = "\0";
    std::string secondLine = "\0";
    size_t i;
    for(i = 0; i < text.size() && text[i] != '\n'; i++) {
        firstLine += text[i];
    }
    i++; // skip the \n
    for(i; i < text.size() && text[i] != '\n'; i++) {
        secondLine += text[i];
    }
    
    // qDebug() << "firstLine : " << firstLine.c_str();
    // qDebug() << "secondLine : " << secondLine.c_str();

    binText = firstLine;

    char car;
    std::string freq;
    i = 0;
    while(i < secondLine.size()) {
        freq = "\0";
        car = secondLine[i];
        i++;
        while(secondLine[i] != ',') {
            freq += secondLine[i];
            i++;
        }
        i++; // skip ,
        Data data;
        std::string::size_type sz;
        data.car = car;
        data.freq = std::stoi(freq, &sz); //stoi convertir string en int
        // qDebug() << data.car << ", " << data.freq;
        addInVectorData(tabFreq, data);
    }
}

bool goodDecoding(std::vector<Data> tabFreqs, std::string code) {
  int sumRightChar = 0;
  if(tabFreqs.size() != code.length()) {
    return false;
  }
  for(char c : code) {
    for(Data data : tabFreqs) {
      if(c == data.car) {
        sumRightChar++;
      }
    }
  }
  return sumRightChar == code.length();
}

/**
 * *Description : Read the current text and convert him.
 * */
void MainWindow::decoding() {
    // Setup read the text
    QString read;
    read = reader->toPlainText();
    if(read != reader->info()) {
        std::string strRead = read.toStdString();

        //
        std::vector<Data> tabFreqText;
        if(!tabFreqText.empty()) {
            tabFreqText.clear();
        }
        std::string binText;
        readDecoding(strRead, binText, tabFreqText);
        int posError = -1;

        //
        if(strRead.length() <= 1) { // ! Not enought char for create the tree.
            QMessageBox::information(mainWidget, "Error message", "Too short message.");
            reader->setReadOnly(false);
        }
        else if(!isOnlyBytes(binText, posError)) { // ! Wrong format in the binary text.
            std::string errorMsg = "Wrong format, error in positon : ";
            errorMsg += std::to_string(posError);
            QString qerrorMsg(errorMsg.c_str());
            QMessageBox::information(mainWidget, "Error message", qerrorMsg);
            reader->setReadOnly(false);
        }
        else if(!tabFreqIsGood(tabFreqText, posError)) { // ! Wrong format in the vector frenquency.
            std::string errorMsg = "Wrong format, error in positon : ";
            errorMsg += std::to_string(posError);
            QString qerrorMsg(errorMsg.c_str());
            QMessageBox::information(mainWidget, "Error message", qerrorMsg);
            reader->setReadOnly(false);
        }
        else if(tabFreqText.size() == 0) { // ! Missing frequencies while decoding.
            QMessageBox::information(mainWidget, "Error message", "Missing frequencies.");
            reader->setReadOnly(false);
        }
        else {
            // Write the current text.
            Writer write("src/txtQt/text.txt");
            tabFreq = tabFreqText;

            write.codeToText(binText, tabFreq);

            // Read the convert text.
            QString fileName = "src/txtQt/code.txt";
            QFile file(fileName);
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream flux(&file);
            QString code = flux.readAll();

            if(goodDecoding(tabFreqText, code.toStdString())) {
              // Print the convert text.
                writer->setTextColor(Qt::black);
                writer->setText(code);
                writer->show();
                isDecoding = true;
            }
            else {
                QMessageBox::information(mainWidget, "Error", "Error in the encoding.");
                reader->setReadOnly(false);
            }
            file.close();
        }
    }
    else {
        QMessageBox::information(mainWidget, "Information", "Any text to encoding.");
    }
}

/**
 * *Description : Clear reader and writer in the encoding menu.
 * */
void MainWindow::clearTextEdit() {
    reader->setClicDellText(true);
    reader->clear();
    reader->writeInfo();
    reader->setReadOnly(false);

    writer->clear();
    writer->writeInfo();
    writer->setReadOnly(true);
    
    isEncoding = false; isDecoding = false; treeIsDrawing = false;
}

/**
 * *Description : Drawing the huffman tree.
 * */
void MainWindow::drawTree() {
    if(!isEncoding && !isDecoding) { // ! Any text endocing yet.
        QMessageBox::information(mainWidget, "Information", "Any text encoding or decoding yet.");
    }
    else {
        // Create the tree.
        Parser parser;
        ArbreB huffmanTree = parser.creatHuffmanTree(tabFreq);

        // Save the old text if user back at the menu.
        treeIsDrawing = true;
        readerSave = reader->toPlainText(); writerSave = writer->toPlainText();
        if(huffmanTree.getRoot()->countDepth() >= maxDepth ) { // ! Too many elements for be drawing.
            QMessageBox::information(mainWidget, "Error message", "HuffmanTree is too big to be drawing");
        }
        else {
            //
            setWindowTitle("Tree");

            // Setup the main window.
            resetWindow(winWidth*2, winHeight*2);
            mainWidget = new QWidget(this);
            QPalette pal = palette();
            pal.setColor(QPalette::Background, Qt::white);
            mainWidget->setAutoFillBackground(true);
            mainWidget->setPalette(pal);

            // Setup tree and layout
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
            listButton.at(0)->setToolTip("Back to the encoding menu");
            writerLayout->addLayout(keypadLayout);
            setCentralWidget(mainWidget);

            if(isEncoding) {
                connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menuEncoding()));
            }
            if(isDecoding) {
                connect(listButton.at(0), SIGNAL(clicked()), this, SLOT(menuDecoding()));
            }
        }
    }
}

/**
 * *Description : Reset the main window and change the size.
 * */
void MainWindow::resetWindow(int newWidth, int newHeight) {
    // Change the size.
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
MainWindow::~MainWindow() {
    // Empty
}
