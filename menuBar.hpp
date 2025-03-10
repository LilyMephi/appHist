#ifndef MENUBAR_HPP
#define MENUBAR_HPP
#include "headers.h"

class ResizeDialog : public QDialog {
    Q_OBJECT

public:
    ResizeDialog(QWidget *) ;
    // Получить введенные значения
    double xMin() const;   
    double xMax() const;
    double yMin() const;
    double yMax() const;

private:
    QLineEdit *xMinEdit;
    QLineEdit *xMaxEdit;
    QLineEdit *yMinEdit;
    QLineEdit *yMaxEdit;
};

#endif
