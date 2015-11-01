#include <QtQml>
#include <QtQml/QQmlContext>
#include "backend.h"
#include "mytype.h"
#include "Command.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("DKShell"));

    qmlRegisterType<MyType>(uri, 1, 0, "MyType");
    qmlRegisterType<MyCommand>(uri, 1, 0, "MyCommand");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}

