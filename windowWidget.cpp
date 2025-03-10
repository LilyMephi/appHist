#include "windowWidget.hpp"

Window::Window(QWidget *parent) : QWidget(parent){
     QGroupBox *echoGroup = new QGroupBox(tr("Histogram"));
     
     // Создаем текст
     QLabel *label = new QLabel(
        QString("<b>Максимальные значения:</b><br>"
                "Максимальное значение X: %1<br>"
                "Максимальное значение Y: %2<br>"
                "Минимальное значение X: %3<br>"
                "Минимальное значение Y: %4")
            .arg(0)
            .arg(0)
            .arg(0)
            .arg(0)
    );
    
    // Выравниваем текст по левому краю
    label->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    
    drawEmptyHist();
     

}

void Window::drawEmptyHist(){
    chart = new QChart();

    chart->setTitle("Hist");

    // Настраиваем оси
    axisX = new QValueAxis();
    axisX->setTitleText("Ось X");
    axisX->setRange(-4, 4); // Диапазон по оси X
    axisX->setTickCount(11); // Количество делений
    axisX->setLabelFormat("%.1f"); // Формат меток

    axisY = new QValueAxis();
    axisY->setTitleText("Ось Y");
    axisY->setRange(-3, 3); // Диапазон по оси Y
    axisY->setTickCount(11); // Количество делений
    axisY->setLabelFormat("%.1f"); // Формат меток

    // Добавляем оси на график
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // Включаем сетку
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);
}

