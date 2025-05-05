#include "fileRead.hpp"

#include <iostream>

FileReader::FileReader(QObject *parent)
    : QObject(parent), lastSize(0), m_updateInterval(1000), lastPosition(0) {
  connect(&m_timer, &QTimer::timeout, this, &FileReader::checkForUpdates);
  m_timer.setInterval(m_updateInterval);
}

FileReader::~FileReader() { closeFile(); }

bool FileReader::openFile(const QString &filePath) {
  closeFile();
  file.setFileName(filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    emit errorOccurred(tr("Не удалось открыть файл: %1").arg(filePath));
    return false;
  }

  QFileInfo fi(file);
  m_lastModified = fi.lastModified();
  lastSize = fi.size();
  lastPosition = 0;  // Всегда начинаем с начала при открытии

  // Читаем начальное содержимое
  readFileContent();
  m_timer.start();
  return true;
}

void FileReader::closeFile() {
  if (file.isOpen()) {
    m_timer.stop();
    file.close();
  }
}

void FileReader::checkForUpdates() {
  if (!file.isOpen()) {
    return;
  }

  // Обновляем информацию о файле
  file.reset();  // Сбрасываем флаги файла
  QFileInfo fileInfo(file.fileName());  // Важно: создаем новый QFileInfo!

  qint64 currentSize = fileInfo.size();
  QDateTime currentModified = fileInfo.lastModified();

  // Если файл был изменен или его размер увеличился
  if (currentModified > m_lastModified || currentSize > lastSize) {
    // Если файл был перезаписан (модифицирован и размер изменился)
    if (currentModified > m_lastModified && currentSize < lastSize) {
      lastPosition = 0;
    }

    m_lastModified = currentModified;
    lastSize = currentSize;
    readFileContent();
  }
}

void FileReader::readFileContent() {
  if (!file.isOpen()) {
    emit errorOccurred("File is not open");
    return;
  }

  // Переоткрываем файл, чтобы убедиться, что мы видим актуальное содержимое
  file.close();
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    emit errorOccurred("Failed to reopen file for reading");
    return;
  }

  // Устанавливаем позицию чтения
  if (!file.seek(lastPosition)) {
    emit errorOccurred("Failed to seek to position " +
                       QString::number(lastPosition));
    lastPosition = 0;
    file.seek(0);
  }

  QMap<int, int> content;
  QTextStream in(&file);

  while (!in.atEnd()) {
    QString line = in.readLine();
    if (line.isEmpty()) continue;
    bool ok;
    double value = line.toDouble(&ok);
    if (ok) {
      ++content[value];
    }
  }

  if (in.status() != QTextStream::Ok) {
    emit errorOccurred("Ошибка чтения файла");
    return;
  }

  qint64 newPosition = file.pos();
  if (newPosition > lastPosition) {
    if (!content.isEmpty()) {
      emit fileUpdated(content);
    }
    lastPosition = newPosition;
  }
}

void FileReader::setUpdateInterval(int msec) {
  m_updateInterval = msec;
  m_timer.setInterval(msec);
}