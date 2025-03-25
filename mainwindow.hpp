#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "headers.h"
#include "menuBar.hpp"
#include "windowWidget.hpp"

QT_CHARTS_USE_NAMESPACE // Используем пространство имен Qt Charts

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *);

protected:
//#ifndef QT_NO_CONTEXTMENU
//    void contextMenuEvent(QContextMenuEvent *event) override;
//#endif // QT_NO_CONTEXTMENU
private slots:
    void openFile();
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
    Window* central;
    QMenuBar *menu;
    QWidget *centralWidget;
};
//#include "main.moc"
#endif // MAINWINDOW_H
