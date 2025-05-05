#ifndef WINDOWWIDGET_HPP
#define WINDOWWIDGET_HPP
#include "headers.h"
#include "qcustomplot.h"

QT_CHARTS_USE_NAMESPACE // Используем пространство имен QtCharts

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

public slots:
    void updatePlot(const QMap<double, int> &points);
private slots:
    void drawEmptyHist(); // рисуем пустой график
public:
    QCustomPlot *customPlot;
    QCPBars *bars;
    QChartView* chartView; // Виджет для отображения диаграммы
    QChart* chart; // диаграмма
    QBarCategoryAxis* axisX; // ось х
    QValueAxis* axisY; // ось у
private:
    QTimer* *m_timer;
    QBarSeries* series;
    QVBoxLayout* mainbox;
    QGroupBox* information;
    QGroupBox* hist;
    QVBoxLayout* infbox;
    QHBoxLayout* histbox;
    QBarSet*  barSet;
    QLabel* maxY; // текст с информацией
    QLabel* maxX; // текст с информацией
    QStringList categories;   
};

#endif // WINDOWWIDGET_HPP
