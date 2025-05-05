#include "windowWidget.hpp"

#include <iostream>
#include <limits>

Window::Window(QWidget *parent) : QWidget(parent) {
  // Добавляем текст в окно
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

  // Добавляем график в окно
  customPlot = new QCustomPlot();
  customPlot->addGraph();
  // Рисуем пустой график на стартовом окне
  drawEmptyHist();

  hist = new QGroupBox("Hist", this);
  histbox = new QHBoxLayout;
  histbox->addWidget(customPlot);
  hist->setLayout(histbox);

  // Создаем layout и добавляем в него текст и график
  mainbox = new QVBoxLayout(this);
  mainbox->addWidget(hist);
  mainbox->addWidget(information);
  setLayout(mainbox);
}

void Window::drawEmptyHist() {
  bars = new QCPBars(customPlot->xAxis, customPlot->yAxis);
  // Устанавливаем названия осей
  customPlot->xAxis->setLabel("Категории");
  customPlot->yAxis->setLabel("Значения");
  // Настраиваем диапазон осей
  customPlot->xAxis->setRange(0, 5);  // 5 категорий (можно изменить)
  customPlot->yAxis->setRange(0, 10);  // Максимальное значение по Y
  bars->setName("Гистограмма");
  bars->setPen(QPen(Qt::blue));
  bars->setBrush(QBrush(QColor(0, 0, 255, 70)));  // Полупрозрачная заливка
}

void Window::updatePlot(const QMap<int, int> &data) {
  // 2. Подготавливаем векторы для графика
  QVector<double> x, y;
  for (auto it = data.begin(); it != data.end(); ++it) {
    x.append(it.key());
    y.append(it.value());
  }

  // 3. Полностью обновляем данные графика
  bars->data()->clear();
  bars->setData(x, y);

  // Автомасштабирование осей
  customPlot->rescaleAxes();

  // Добавляем небольшой отступ по Y (10% от максимума)
  // double yMax = *std::max_element(yData.begin(), yData.end());
  // customPlot->yAxis->setRangeUpper(yMax * 1.1);
  // std::cout<<"yMax: "<<yMax << std::endl;

  // double xMax = *std::max_element(xData.begin(), xData.end());
  // customPlot->yAxis->setRangeUpper(xMax * 1.1);
  // std::cout<<"xMax: "<<xMax << std::endl;

  // Автомасштабирование осей
  customPlot->rescaleAxes();
  // Перерисовываем график
  customPlot->replot();
}

Window::~Window() {
  delete customPlot;
  delete bars;
  delete information;
  delete hist;
  delete infbox;
  delete histbox;
  delete maxY;
  delete maxX;
  delete mainbox;
}
