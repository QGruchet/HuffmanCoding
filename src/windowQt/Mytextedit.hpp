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
    bool clicDellText = true;

public:
    /* Constructor */
    MyTextEdit(QWidget* parent = nullptr);

    /* Functions */
    void writeInfo();

    /* Getter */
    QString info() const;

    /* Setters */
    void setInfo(QString);
    void setClicDellText(bool newClicDellText);

    /* Destructor */
    ~MyTextEdit();

public slots:
    void mousePressEvent(QMouseEvent*);
};

#endif // MYTEXTEDIT_HPP