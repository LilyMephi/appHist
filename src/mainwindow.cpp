#include "mainwindow.hpp"

#include <iostream>

MainWindow::MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
  fileReader = new FileReader(this);
  // Создаем виджет и распологаем его по середине
  central = new Window(this);
  serial = new QSerialPort(this);
  setCentralWidget(central);

  connect(fileReader, &FileReader::fileUpdated, this,
          &MainWindow::onFileUpdated);
  connect(fileReader, &FileReader::errorOccurred, this,
          &MainWindow::onErrorOccurred);
          connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);

  setupMenuBar();
  setupAtmegaBar();

  // Настраиваем окно
  setWindowTitle("Hist");
  resize(800, 600);
}

MainWindow::~MainWindow() {
  delete central;
  delete menu;
  delete fileReader;
}

void MainWindow::setupMenuBar() {
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

void MainWindow::setupAtmegaBar() {
  // Создаем менюбар
  menu = this->menuBar();
  // Добавляем вкладку "File"
  QMenu *fileMenu = menu->addMenu("SerialPort");

  // Добовлям стиль
  QApplication::setStyle("MacOs");

  // Добавляем действие "Open File"
  QAction *connectAction = fileMenu->addAction("Connection");
  connect(connectAction, &QAction::triggered, this, &MainWindow::showPortDialog);
  // Действие для отключения
  QAction *disconnectAction = fileMenu->addAction("Disconnection");
  connect(disconnectAction, &QAction::triggered, this, &MainWindow::disconnectPort);
  // // Добавляем действие "save hist"
  // QAction *saveHistAction = fileMenu->addAction("UART");
  // connect(saveHistAction, &QAction::triggered, this, &MainWindow::saveHist);
}

void MainWindow::showPortDialog() {
  // Получаем список доступных портов
  QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
  
  if (ports.isEmpty()) {
      QMessageBox::warning(this, "Ошибка", "Не найдено доступных COM-портов!");
      return;
  }
  
  // Создаем диалог для выбора порта
  QMenu portMenu(this);
  portMenu.setTitle("Выберите порт");
  
  // Добавляем доступные порты в меню
  for (const QSerialPortInfo &portInfo : ports) {
      QString portName = portInfo.portName();
      QAction *portAction = new QAction(portName, this);
      portAction->setData(portName);
      portMenu.addAction(portAction);
      connect(portAction, &QAction::triggered, this, &MainWindow::connectToPort);
  }
  
  // Показываем меню под курсором
  portMenu.exec(QCursor::pos());
}

void MainWindow::connectToPort() {
  QAction *action = qobject_cast<QAction*>(sender());
  if (!action) return;
  
  QString portName = action->data().toString();
  
  // Настраиваем и открываем порт
  serial->setPortName(portName);
  serial->setBaudRate(QSerialPort::Baud9600);
  serial->setDataBits(QSerialPort::Data8);
  serial->setParity(QSerialPort::NoParity);
  serial->setStopBits(QSerialPort::OneStop);
  serial->setFlowControl(QSerialPort::NoFlowControl);
  
  if (serial->open(QIODevice::ReadWrite)) {
      QMessageBox::information(this, "Успех", 
                             QString("Успешно подключено к %1").arg(portName));
  } else {
      QMessageBox::critical(this, "Ошибка", 
                           QString("Не удалось подключиться к %1: %2")
                           .arg(portName).arg(serial->errorString()));
  }
}

void MainWindow::disconnectPort() {
  if (serial->isOpen()) {
      serial->close();
      QMessageBox::information(this, "Отключение", "Порт отключен");
  } else {
      QMessageBox::warning(this, "Ошибка", "Порт не был подключен");
  }
}

void MainWindow::readData() {
  // Чтение данных из порта
  static QByteArray buffer;
  QMap<int, int> content;    
  buffer += serial->readAll();
  
  // Обрабатываем все целые числа в буфере
  while (true) {
      // Ищем разделитель (например, пробел или перевод строки)
      int separatorPos = buffer.indexOf(' ');
      if (separatorPos == -1) {
          separatorPos = buffer.indexOf('\n');
      }
      if (separatorPos == -1) {
          separatorPos = buffer.indexOf('\r');
      }
      
      if (separatorPos == -1) break; // Нет полного числа
      
      QByteArray numberStr = buffer.left(separatorPos);
      bool ok;
      int value = numberStr.toInt(&ok);
      
      if (ok) {
        ++content[value];
      } 
      buffer = buffer.mid(separatorPos + 1);
  }

  for (auto it = content.begin(); it != content.end(); ++it) {
    allData[it.key()] += it.value();
  }

  central->updatePlot(allData);
}
// void MainWindow::openFile(){
//     // Открываем диалог выбора файла
//     QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл", "",
//     "Текстовые файлы (*.txt);;Все файлы (*)");

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
//     QMap<inr, int> eventN;
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

void MainWindow::onOpenFile() {
  QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
  if (fileName.isEmpty()) return;
  if (!fileReader->openFile(fileName)) {
    QMessageBox::warning(this, "Ошибка", "Ошибка чтении файла!");
    return;
  }
}

void MainWindow::onFileUpdated(const QMap<int, int> content) {
  //  Добавляем новые данные к существующим
  for (auto it = content.begin(); it != content.end(); ++it) {
    allData[it.key()] += it.value();
  }

  central->updatePlot(allData);
}

void MainWindow::onErrorOccurred(const QString &message) {
  QMessageBox::warning(this, "Ошибка", message);
}

// void MainWindow::addMenuBar(){
// }
void MainWindow::saveHist() {
  // Открываем диалог выбора файла
  QString fileName = QFileDialog::getSaveFileName(
      this, "Сохранить график", "", "PNG файлы (*.png);;Все файлы (*)");

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

void MainWindow::resizeDialog() {
  ResizeDialog dialog(this);
  if (dialog.exec() == QDialog::Accepted) {
    // Получаем новые значения диапазона
    // double xMin = dialog.xMin();
    // double xMax = dialog.xMax();
    double yMin = dialog.yMin();
    double yMax = dialog.yMax();

    // Обновляем диапазон осей
    // central->axisX->setRange(xMin, xMax);
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
