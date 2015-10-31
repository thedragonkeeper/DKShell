#include "Command.h"

myCommand::myCommand(QObject *parent) : QObject(parent)
{
    m_process = new QProcess(this);
    connect(m_process, &QProcess::readyReadStandardOutput, this, &myCommand::handleReadyRead);
}

void myCommand::run(const QString &program, const QStringList &arguments)
{
    if (program.isEmpty()) {
        return;
    }
    m_process->execute(program, arguments);
}

void myCommand::handleReadyRead()
{
    m_process->setReadChannel(QProcess::StandardOutput);
    while(m_process->canReadLine()) {
        QString line = QString::fromLocal8Bit(m_process->readLine());
        emit newLine(line);
    }
}
