#include "windowWidget.hpp"
#include <limits>

Window::Window(QWidget *parent) : QWidget(parent){
    
    information = new QGroupBox("information", this);
    
    // Создаем текст
    infbox = new QVBoxLayout;
    maxY = new QLabel(this);
    maxX = new QLabel(this);
    maxX->setText(QString("max x: "));
    maxY->setText(QString("max y: "));

    infbox->addWidget(maxY);
    infbox->addWidget(maxX);
    
    information->setLayout(infbox);
  
    // Рисуем пустой график на стартовом окне
    drawEmptyHist();
    chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);    
    
    // Устанавливаем фиксированный размер для QChartView
    chartView->setMinimumSize(600, 600); // Минимальный размер
    chartView->setMaximumSize(600, 600); // Максимальный размер (фиксированный размер) 

    
    hist = new QGroupBox("Hist", this);
    histbox= new QHBoxLayout;
    histbox->addWidget(chartView);
    hist->setLayout(histbox);
    
    // Создаем layout и добавляем в него текст и график
    mainbox = new QVBoxLayout(this);
    mainbox->addWidget(hist);
    mainbox->addWidget(information);  
    setLayout(mainbox);

}

void Window::drawEmptyHist(){
    chart = new QChart();

    chart->setTitle("Hist");

    // Настраиваем оси
    axisX = new QValueAxis();
    axisX->setTitleText("Events");
    axisX->setRange(-4, 4); // Диапазон по оси X
    axisX->setTickCount(11); // Количество делений
    axisX->setLabelFormat("%.1f"); // Формат меток

    axisY = new QValueAxis();
    axisY->setTitleText("s");
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

void Window::redrawPlot(const QVector<QPointF> &points){

    // Очищаем старые данные
    chart->removeAllSeries();
    //chat->removeAxis();
    // Создаем серию данных
    series = new QBarSeries();
    double max_Y = std::numeric_limits<double>::min();
    double max_X = std::numeric_limits<double>::min();
    for (const QPointF &point : points) {
        series->append(point.x(), point.y());
        if(max_Y < point.y()){
        	max_Y = point.y();
        }
        if(max_X < point.x()){
        	max_X = point.x();
        }	
    }
    
      
    // Обновляем оси графика
    chart->createDefaultAxes();
    // Добавляем точки на график
    chart->addSeries(series);

    chartView->update();
    //axisX->setRange(axisX->min()-1,axisX->max()+1);
    //axisY->setRange(axisY->min()-1,axisY->max()+1);
    maxX->setText(QString("max x: %1").arg(max_X));
    maxY->setText(QString("max y: %1").arg(max_Y));
}

Window::~Window() {
    delete series;
    delete mainbox;
    delete information;
    delete hist;
    delete infbox;
    delete histbox;
    delete maxY; // текст с информацией
    delete maxX; // текст с информацией
    delete chartView; // Виджет для отображения диаграммы
    delete chart; // диаграмма
    delete axisX; // ось х
    delete axisY; // ось у
}
