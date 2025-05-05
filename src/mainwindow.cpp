#include "mainwindow.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent = nullptr) : QMainWindow(parent){
    
    m_fileReader = new FileReader(this);
    // Создаем виджет и распологаем его по середине
    central = new Window(this);
    setCentralWidget(central); 

    connect(m_fileReader, &FileReader::fileUpdated, 
        this, &MainWindow::onFileUpdated);
    connect(m_fileReader, &FileReader::errorOccurred, 
        this, &MainWindow::onErrorOccurred);

    setupMenuBar();  
    setupAtmegaBar();  
    
    // Настраиваем окно
    setWindowTitle("Hist");
    resize(800, 600);
    
}

MainWindow::~MainWindow()
{
    delete central;
    delete menu;
    delete m_fileReader;
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
    connect(openFileAction, &QAction::triggered, this, &MainWindow::onOpenFile);
    
    // Добавляем действие "save hist"
    QAction *saveHistAction = fileMenu->addAction("save Hist");
    connect(saveHistAction, &QAction::triggered, this, &MainWindow::saveHist);

    // Добавляем действие "Resize"
    QAction *resizeAction = fileMenu->addAction("Resize");
    connect(resizeAction, &QAction::triggered, this, &MainWindow::resizeDialog); 
}

void MainWindow::setupAtmegaBar(){
 // Создаем менюбар
    menu = this->menuBar();
    // Добавляем вкладку "File"
    QMenu *fileMenu = menu->addMenu("Atmega");
    
    // Добовлям стиль
    QApplication::setStyle("MacOs");
    
    // Добавляем действие "Open File"
    QAction *openFileAction = fileMenu->addAction("USB");
    connect(openFileAction, &QAction::triggered, this, &MainWindow::loadFromUSB);
    
    // Добавляем действие "save hist"
    QAction *saveHistAction = fileMenu->addAction("UART");
    connect(saveHistAction, &QAction::triggered, this, &MainWindow::saveHist);
 
}

void MainWindow::loadFromUSB(){
	
}

void MainWindow::loadFromUART(){
}

// void MainWindow::openFile(){
//     // Открываем диалог выбора файла
//     QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

//     if (fileName.isEmpty()) {
//         QMessageBox::warning(this, "Ошибка", "Файл не выбран!");
//         return;
//     }

//     // Чтение данных из файла
//     QFile file(fileName);
//     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//         QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл!");
//         return;
//     }

//     //QVector<QPointF> points;
//     QMap<double, int> eventN;
//     QTextStream in(&file);
//     while (!in.atEnd()) {
//         QString line = in.readLine();
//         bool flagRead = true;
//         double value = line.toDouble(&flagRead);
//         if(flagRead){
//             ++eventN[value];
//         }

//     }
//     file.close();

//     // Если данные не прочитаны, выводим сообщение
//     if (eventN.isEmpty()) {
//         QMessageBox::warning(this, "Ошибка", "Файл не содержит данных!");
//         return;
//     }

//     // Строим диаграмму
//     central->updatePlot(eventN);
// }

void MainWindow::onOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
    if (fileName.isEmpty())
        return;
    std::cout << "Opening file " << std::endl;
    if (!m_fileReader->openFile(fileName))
    {
        QMessageBox::warning(this, "Ошибка", "Ошибка чтении файла!");
        return;
    }
}

void MainWindow::onFileUpdated(const QMap<double, int> content)
{
    if(m_fileReader->truePosition == false){
        allData.clear();
    }

    //  Добавляем новые данные к существующим
    for (auto it = content.begin(); it != content.end(); ++it) {
        allData[it.key()] += it.value();
    }

    central->updatePlot(allData);
    std::cout << "update plot" << std:: endl;
}

void MainWindow::onErrorOccurred(const QString &message)
{
    QMessageBox::warning(this, "Ошибка", message);
}

// void MainWindow::addMenuBar(){
// }
void MainWindow::saveHist(){
    // Открываем диалог выбора файла
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить график", "", "PNG файлы (*.png);;Все файлы (*)");

    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Файл не выбран!");
        return;
    }
    // Сохраняем график как изображение
    if (!central->chartView->grab().save(fileName)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл!");
    } else {
        QMessageBox::information(this, "Успех", "График сохранен!");
    }
}

void MainWindow::resizeDialog(){
    ResizeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Получаем новые значения диапазона
        //double xMin = dialog.xMin();
        //double xMax = dialog.xMax();
        double yMin = dialog.yMin();
        double yMax = dialog.yMax();

        // Обновляем диапазон осей
        //central->axisX->setRange(xMin, xMax);
        central->axisY->setRange(yMin, yMax);
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

