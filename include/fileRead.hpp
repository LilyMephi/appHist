#ifndef FILEREAD_HPP
#define FILEREAD_HPP

#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QObject>
#include <QTextStream>
#include <QTimer>
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

 signals:
  void fileUpdated(const QMap<int, int> content);
  void errorOccurred(const QString &message);

 public slots:
  void setUpdateInterval(int msec);
  void checkForUpdates();

 private:
  void readFileContent();

  QFile file;
  QTimer m_timer;
  qint64 lastSize;
  qint64 lastPosition;
  QDateTime m_lastModified;
  int m_updateInterval = 1000;
};

#endif