#ifndef WINDOWWIDGET_HPP
#define WINDOWWIDGET_HPP
#include "headers.h"

QT_CHARTS_USE_NAMESPACE // Используем пространство имен QtCharts

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    void redrawPlot(const QVector<QPointF> &points);
private slots:
    void drawEmptyHist(); // рисуем пустой график
public:
    QChartView* chartView; // Виджет для отображения диаграммы
    QChart* chart; // диаграмма
    QValueAxis* axisX; // ось х
    QValueAxis* axisY; // ось у
private:
    QLineSeries* series;
    QVBoxLayout* mainbox;
    QGroupBox* information;
    QGroupBox* hist;
    QVBoxLayout* infbox;
    QHBoxLayout* histbox;
    QLabel* maxY; // текст с информацией
    QLabel* maxX; // текст с информацией
};

#endif // WINDOWWIDGET_HPP
