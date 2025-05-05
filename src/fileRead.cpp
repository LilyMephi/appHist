#include "fileRead.hpp"
#include <iostream>

FileReader::FileReader(QObject *parent = nullptr) : QObject(parent), lastSize(0), m_updateInterval(1000), lastPosition(0){
  connect(&m_timer, &QTimer::timeout, this, &FileReader::checkForUpdates);
  m_timer.setInterval(m_updateInterval);
}

FileReader::~FileReader() {
  closeFile();
}

bool FileReader::openFile(const QString &filePath) {
  closeFile();
  m_file.setFileName(filePath);
  if (!m_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      emit errorOccurred(tr("Не удалось открыть файл: %1").arg(filePath));
      return false;
  }

  // Сбрасываем позицию и флаг при открытии нового файла
  lastPosition = 0;
  truePosition = true;

  // Инициализируем отслеживание изменений
  QFileInfo fi(m_file);
  m_lastModified = fi.lastModified();
  lastSize = fi.size();  

  readFileContent();
  m_timer.start();
  return true;
}

void FileReader::closeFile() {
  if (m_file.isOpen())
  {
      m_timer.stop();
      m_file.close();
  }
}

bool FileReader::isReading() {
  return m_file.isOpen();
}

QString FileReader::currentFilePath() const {
  return m_file.fileName();
}

void FileReader::checkForUpdates() {
  if (!m_file.isOpen()) {
      std::cout << "File is not open" << endl;
      return;
  }

  QFileInfo fileInfo(m_file);
  qint64 currentSize = fileInfo.size();
  QDateTime currentModified = fileInfo.lastModified();

  // Если файл был изменен (перезаписан или дополнен)
  if (currentModified != m_lastModified || currentSize != lastSize) {
      // Если файл уменьшился или был перезаписан, сбрасываем позицию
      if (currentSize < lastPosition || currentModified != m_lastModified) {
          lastPosition = 0;
          truePosition = true;
      }

      lastSize = currentSize;
      m_lastModified = currentModified;
      readFileContent(); // Читаем с актуальной позиции (0 или предыдущей)
  }
}

// void FileReader::checkForUpdates()
// {
//   if (!m_file.isOpen()){
//     std :: cout << "cant open file " << endl;
//     return;
//   }

//   if (m_file.size() < lastPosition) {
//     truePosition = false;
//     lastPosition = 0;
//   }

//   QFileInfo fileInfo(m_file);
//   QDateTime modified = fileInfo.lastModified();
//   qint64 size = fileInfo.size();
//   if (modified != m_lastModified || size > lastSize){
//     lastSize = size;
//     m_lastModified = modified;
//     readFileContent();
//   }
// }

void FileReader::readFileContent() {
  if (!m_file.isOpen()) {
      emit errorOccurred("File is not open");
      return;
  }

  // Если позиция некорректна (например, файл перезаписан), сбрасываем в 0
  if (lastPosition > m_file.size()) {
      lastPosition = 0;
      truePosition = false;
  }

  if (!m_file.seek(lastPosition)) {
      emit errorOccurred("Seek failed: cannot move to position " + QString::number(lastPosition));
      lastPosition = 0; // Пытаемся начать с начала
      truePosition = false;
      if (!m_file.seek(lastPosition)) {
          emit errorOccurred("Failed to reset file position");
          return;
      }
  }

  QMap<double, int> content;
  QTextStream in(&m_file);
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

  lastPosition = m_file.pos(); // Сохраняем новую позицию
  truePosition = true;

  if (!content.isEmpty()) {
      emit fileUpdated(content);
  }
}

// void FileReader::readFileContent(){

//   if (lastPosition > m_file.size()) {
//     lastPosition = 0; // Сброс позиции, если она превышает размер файла
//     truePosition = false;
//   }
//   if(!m_file.seek(lastPosition)){
//   emit errorOccurred("Seek failed");
//   std :: cout << "Seek failed" << endl;
//   return;
//   }

//   QMap<double, int> content;
//   QTextStream in(&m_file);
//   while (!in.atEnd()) {
//       QString line = in.readLine();
//       if (line.isEmpty()) continue;
//       bool flagRead = true;
//       double value = line.toDouble(&flagRead);
//       if(flagRead){
//           ++content[value];
//       }
//   }

//   if (in.status() != QTextStream::Ok){
//     std :: cout << "Ошибка чтения файла" << endl;
//     emit errorOccurred(tr("Ошибка чтения файла"));
//     return;
//   }

//   //обновлем позицию на последнюю считанную строку
//   std :: cout << lastPosition << std :: endl;
//   lastPosition = m_file.pos();
//   truePosition = true;
//   // Если данные прочитаны
//   if (!content.isEmpty()) {
//     emit fileUpdated(content); // Отправляем только новые данные
//   }
// }

void FileReader::setUpdateInterval(int msec){
  m_updateInterval = msec;
  m_timer.setInterval(msec);
}

// void FileReader::checkForUpdates()
// {
//     static int retryCount = 0;
    
//     try {
//         // Основная логика проверки
//         if (!m_file.isOpen()) throw std::runtime_error("File not open");
        
//         QFileInfo fi(m_file);
//         if (fi.size() < m_lastPosition) {
//             m_lastPosition = 0;
//         }
        
//         if (fi.size() > m_lastPosition) {
//             readNewData();
//             retryCount = 0; // Сброс счетчика при успехе
//         }
//     }
//     catch (...) {
//         if (++retryCount > 3) {
//             emit errorOccurred("Multiple read failures");
//             m_timer.stop();
//             return;
//         }
        
//         // Попытка восстановления
//         QString path = m_file.fileName();
//         closeFile();
//         if (!path.isEmpty()) {
//             openFile(path);
//         }
//     }
// }