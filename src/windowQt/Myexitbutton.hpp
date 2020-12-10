#ifndef MYTEXITBUTTON_HPP
#define MYTEXITBUTTON_HPP

#include <QWidget>
#include <QPushButton>

#include <QIcon>
#include <QPixmap>

class MyExitButton : public QPushButton
{
    Q_OBJECT
private:

public:
    /* Constructor */
    MyExitButton(QWidget*);

    /* Functions */

    /* Destructor */
    ~MyExitButton();
};

#endif // MYTEXITBUTTON_HPP