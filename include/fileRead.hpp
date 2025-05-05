#ifndef FILEREAD_HPP
#define FILEREAD_HPP

#include <QFileInfo>
#include <QTextStream>
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QTimer>
#include <QDateTime>
#include <QtWidgets/QMessageBox>

class FileReader : public QObject {
    Q_OBJECT
public:
    explicit FileReader(QObject *);
    ~FileReader();

    bool openFile(const QString &filePath);
    void closeFile();
    bool isReading();
    QString currentFilePath() const;

    bool truePosition;

signals:
    void fileUpdated(const QMap<double, int> content);
    void errorOccurred(const QString &message);

public slots:
    void setUpdateInterval(int msec);
    void checkForUpdates();

private:
    void readFileContent();

    QFile m_file;
    QTimer m_timer;
    qint64 lastSize;
    qint64 lastPosition;
    QDateTime m_lastModified;
    int m_updateInterval = 1000;
};

#endif