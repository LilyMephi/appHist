#include "menuBar.hpp"

ResizeDialog :: ResizeDialog(QWidget *parent = nullptr) : QDialog(parent) {
    setWindowTitle("Изменить диапазон осей");

    // Создаем поля для ввода
    QFormLayout *layout = new QFormLayout(this);
    xMinEdit = new QLineEdit(this);
    xMaxEdit = new QLineEdit(this);
    yMinEdit = new QLineEdit(this);
    yMaxEdit = new QLineEdit(this);

    layout->addRow("Минимум X:", xMinEdit);
    layout->addRow("Максимум X:", xMaxEdit);
    layout->addRow("Минимум Y:", yMinEdit);
    layout->addRow("Максимум Y:", yMaxEdit);

    // Кнопка "Применить"
    QPushButton *applyButton = new QPushButton("Применить", this);
    layout->addRow(applyButton);

    // Подключаем кнопку к слоту
    connect(applyButton, &QPushButton::clicked, this, &ResizeDialog::accept);
}

    // Получить введенные значения
double ResizeDialog :: xMin() const {
    return xMinEdit->text().toDouble();
}
double ResizeDialog :: xMax() const { 
    return xMaxEdit->text().toDouble(); 
}
double ResizeDialog :: yMin() const {
    return yMinEdit->text().toDouble();
}
double ResizeDialog :: yMax() const { 
    return yMaxEdit->text().toDouble();
}
