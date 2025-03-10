#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "headers.h"
#include "menuBar.hpp"
#include "squareCalc.hpp"

QT_CHARTS_USE_NAMESPACE // Используем пространство имен Qt Charts

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *);

private slots:
    void openFile();
    void drawemptyHist();
    void saveHist();
    void resizeDialog();
    void buildChart(const QVector<QPointF> &points);
    void setupUI();
    void setupMenuBar();
//    bool save();
//    bool saveAs();
//    void about();

private:
    QChartView *chartView; // Виджет для отображения диаграммы
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QLabel *label;
    QMenuBar *menu;
    QWidget *centralWidget;
    //DraggableAxisChartView *chartView;
    //void createToolbar();
    //void createHist();
};
//#include "main.moc"
#endif // MAINWINDOW_H
