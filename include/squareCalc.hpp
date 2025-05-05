#ifndef SQUARECALC_HPP
#define SQUARECALC_HPP

#include "headers.h"

QT_CHARTS_USE_NAMESPACE

class DraggableAxisChartView : public QChartView {
  Q_OBJECT

 public:
  DraggableAxisChartView(QChart *, QWidget *);

 protected:
  //функция
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  QLineSeries *axisLine;  // Линия, которая будет двигаться
  bool isDragging;  // Флаг для отслеживания перетаскивания
};

#endif  // SQUARECALC_HPP
