#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "headers.h"
#include "menuBar.hpp"
#include "windowWidget.hpp"
#include <QTimer>
#include <QFileSystemWatcher>
#include "fileRead.hpp"

QT_CHARTS_USE_NAMESPACE // Используем пространство имен Qt Charts

class MainWindow : public QMainWindow
{
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
    void onFileUpdated(const QMap<double, int> content);
    void onErrorOccurred(const QString &message);
    void saveHist();
    void resizeDialog();
    void setupMenuBar();
    void loadFromUSB();
    void loadFromUART();
    void setupAtmegaBar();
//    bool save();
//    bool saveAs();
//    void about();

private:

    Window *central;
    QMenuBar *menu;
    QWidget *centralWidget;
    QTimer *dataTimer;
    QMap<double, int> allData;
    FileReader *m_fileReader;
};
//#include "main.moc"
#endif // MAINWINDOW_H
