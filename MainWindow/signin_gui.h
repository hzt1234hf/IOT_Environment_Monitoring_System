#ifndef SIGNIN_GUI_H
#define SIGNIN_GUI_H

#include <QDialog>

namespace Ui {
class Signin_GUI;
}

class Signin_GUI : public QDialog
{
    Q_OBJECT
    
public:
    explicit Signin_GUI(QWidget *parent = 0);
    ~Signin_GUI();
    
private:
    Ui::Signin_GUI *ui;
private slots:
    void signIn(void);
};

#endif // SIGNIN_GUI_H
