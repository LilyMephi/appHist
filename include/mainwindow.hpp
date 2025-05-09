#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QFileSystemWatcher>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "fileRead.hpp"
#include "headers.h"
#include "menuBar.hpp"
#include "windowWidget.hpp"

QT_CHARTS_USE_NAMESPACE  // Используем пространство имен Qt Charts

    class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *);
  ~MainWindow();

 protected:
  //#ifndef QT_NO_CONTEXTMENU
  //    void contextMenuEvent(QContextMenuEvent *event) override;
  //#endif // QT_NO_CONTEXTMENU
 private slots:
  // void openFile();
  void onOpenFile();
  void onFileUpdated(const QMap<int, int> content);
  void onErrorOccurred(const QString &message);
  void saveHist();
  void resizeDialog();
  void setupMenuBar();
  void showPortDialog();
  void readData();
  void connectToPort();
  void disconnectPort();
  void setupAtmegaBar();
  //    bool save();
  //    bool saveAs();
  //    void about();

 private:
  Window *central;
  QMenuBar *menu;
  QWidget *centralWidget;
  QTimer *dataTimer;
  QMap<int, int> allData;
  FileReader *fileReader;
  QSerialPort *serial;
};
//#include "main.moc"
#endif  // MAINWINDOW_H
