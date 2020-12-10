#ifndef MYBUTTON_HPP
#define MYBUTTON_HPP

#include <QWidget>
#include <QPushButton>

#include <QIcon>
#include <QPixmap>

class MyButton : public QPushButton
{
    Q_OBJECT

private:
    /* Data */
    QString pathIcon;

public:
    /* Constructor */
    MyButton(QWidget*, QString);

    /* Function */
    void createIcon() const;

    /* Setters */
    void setPathIcon(QString);

    /* Destructor */
    ~MyButton();
};

#endif // MYBUTTON_HPP