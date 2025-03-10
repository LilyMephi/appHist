#include "mainwindow.hpp"
#include <iostream>
MainWindow::MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
    
    setupUI(); 
    
    //setupMenuBar();    
    
    // Настраиваем окно
    setWindowTitle("Hist");
    resize(800, 600);
    
}

void MainWindow::setupMenuBar(){
 // Создаем менюбар
    menu = this->menuBar();
    // Добавляем вкладку "File"
    QMenu *fileMenu = menu->addMenu("Edit");
    
    // Добовлям стиль
    QApplication::setStyle("MacOs");
    
    // Добавляем действие "Open File"
    QAction *openFileAction = fileMenu->addAction("Open File");
    connect(openFileAction, &QAction::triggered, this, &MainWindow::openFile);
    
    // Добавляем действие "save hist"
    QAction *saveHistAction = fileMenu->addAction("save Hist");
    connect(saveHistAction, &QAction::triggered, this, &MainWindow::saveHist);

    // Добавляем действие "Resize"
    QAction *resizeAction = fileMenu->addAction("Resize");
    connect(resizeAction, &QAction::triggered, this, &MainWindow::resizeDialog); 
}
void MainWindow::setupUI(){
    // Создаем виджет и распологаем его по середине
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
        
    // Создаем текст
    label = new QLabel(
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
    
    drawemptyHist();
    
    // Создаем layout и добавляем в него текст и график
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label);
    layout->addWidget(chartView);
    
    layout->setStretch(0, 1); // Левая часть (текст)
    layout->setStretch(1, 3); // Правая часть (график)
    
    // Устанавливаем layout для центрального виджета
    centralWidget->setLayout(layout);
}
void MainWindow::openFile(){
    // Открываем диалог выбора файла
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не выбран!");
        return;
    }

    // Чтение данных из файла
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    QVector<QPointF> points;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(" ");
        if (values.size() == 2) {
            double y = values[0].toDouble();
            double x = values[1].toDouble();
            points.append(QPointF(x, y));
        }
    }
    file.close();

    // Если данные не прочитаны, выводим сообщение
    if (points.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не содержит данных!");
        return;
    }

    // Строим диаграмму
    buildChart(points);
}

void  MainWindow :: drawemptyHist(){
    // Создаем пустой график
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
    
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

}
void MainWindow::buildChart(const QVector<QPointF> &points){

    // Очищаем старые данные
    chart->removeAllSeries();

    // Создаем серию данных
    QLineSeries *series = new QLineSeries();
    for (const QPointF &point : points) {
        series->append(point.x(), point.y());
    }
    
    // Добавляем точки на график
    chart->addSeries(series);

    // Добавляем оси на график
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Включаем сетку
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

//void MainWindow::addMenuBar(){
//}
void MainWindow::saveHist(){
    // Открываем диалог выбора файла
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить график", "", "PNG файлы (*.png);;Все файлы (*)");

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не выбран!");
        return;
    }
    // Сохраняем график как изображение
    if (!chartView->grab().save(fileName)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл!");
    } else {
        QMessageBox::information(this, "Успех", "График сохранен!");
    }
}

void MainWindow::resizeDialog(){
    ResizeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Получаем новые значения диапазона
        double xMin = dialog.xMin();
        double xMax = dialog.xMax();
        double yMin = dialog.yMin();
        double yMax = dialog.yMax();

        // Обновляем диапазон осей
        axisX->setRange(xMin, xMax);
        axisY->setRange(yMin, yMax);
    }
}
/*
void MainWindow::logChart(const QVector<QPointF> &points){

    // Очищаем старые данные
    chart->removeAllSeries();

    // Создаем серию данных
    QLineSeries *series = new QLineSeries();
    for (const QPointF &point : points) {
        series->append(point.x(), point.y());
    }
    
    // Добавляем точки на график
    chart->addSeries(series);

    // Добавляем оси на график
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Включаем сетку
    axisX->setGridLineVisible(true);
    axisY->setGridLineVisible(true);

    
    chartView->setChart(chart);
}*/

