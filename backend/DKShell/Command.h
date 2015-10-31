#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>
#include <QProcess>
#include <QPointer>

class myCommand : public QObject
{
    Q_OBJECT

public:
    explicit myCommand(QObject *parent = 0);

signals:
    void newLine(const QString &line);

public slots:
    void run(const QString &program, const QStringList &arguments);
    void handleReadyRead();

private:
    QPointer<QProcess> m_process;
};

#endif // COMMAND_H
