#ifndef MYTEXTEDIT_HPP
#define MYTEXTEDIT_HPP

#include <QWidget>
#include <QMouseEvent>
#include <QTextEdit>

#include <QDebug>

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
private:
    QString textInfo;

public:
    /* Constructor */
    MyTextEdit(QWidget* parent = nullptr);

    /* Functions */
    void setInfo(QString);
    void writeInfo();
    QString info() const;

    /* Destructor */
    ~MyTextEdit();

public slots:
    void mousePressEvent(QMouseEvent*);
};

#endif // MYTEXTEDIT_HPP