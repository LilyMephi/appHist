#include "squareCalc.hpp"

DraggableAxisChartView::
DraggableAxisChartView(QChart *chart, QWidget *parent = nullptr)
                  : QChartView(chart, parent), isDragging(false){
    // Настраиваем линию для оси
    axisLine = new QLineSeries();
    axisLine->append(0, -1000); // Начальная точка (за пределами графика)
    axisLine->append(0, 1000);  // Конечная точка (за пределами графика)
    chart->addSeries(axisLine);

    // Привязываем линию к осям
    axisLine->attachAxis(chart->axisX());
    axisLine->attachAxis(chart->axisY());

    // Настраиваем стиль линии
    axisLine->setColor(Qt::red);
    axisLine->setPen(QPen(Qt::red, 2, Qt::DashLine));
}
void DraggableAxisChartView::
mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
    // Проверяем, находится ли курсор рядом с линией
        QPointF scenePos = chart()->mapToValue(event->pos());
        if (qAbs(scenePos.x() - axisLine->at(0).x()) < 0.5) { // Порог для захвата линии
            isDragging = true;
        }
    }
    QChartView::mousePressEvent(event);
}

void DraggableAxisChartView::
mouseMoveEvent(QMouseEvent *event) {
    if (isDragging) {
        // Обновляем позицию линии
        QPointF scenePos = chart()->mapToValue(event->pos());
        axisLine->replace(0, QPointF(scenePos.x(), -1000));
        axisLine->replace(1, QPointF(scenePos.x(), 1000));
        chart()->update();
    }
    QChartView::mouseMoveEvent(event);
}

void DraggableAxisChartView::
mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
    QChartView::mouseReleaseEvent(event);
}
