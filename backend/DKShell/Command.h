#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QProcess>
#include <QPointer>

class Command : public QObject
{
    Q_OBJECT

public:
    explicit Command(QObject *parent = 0);

signals:
    void newLine(const QString &line);

public slots:
    void run(const QString &program, const QStringList &arguments);
    void handleReadyRead();

private:
    QPointer<QProcess> m_process;
};

#endif // COMMAND_H
