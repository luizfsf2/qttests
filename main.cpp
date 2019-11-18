#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickItem>

#if 0
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/Item.qml")));

    QList<QObject *> rootObjects = engine.rootObjects();
    //QObject *parentItem = rootObjects.first();
    QQuickItem *parentItem = qvariant_cast<QQuickItem*>(rootObjects.first()->property("contentItem"));

    //childItem->setParent(parentItem);
    QObject *childObj = component.create();
    QQuickItem *childItem = qobject_cast<QQuickItem*>(childObj);
    childItem->setParentItem(parentItem);

    QQmlEngine::setObjectOwnership(childItem, QQmlEngine::CppOwnership);

    return app.exec();
}
#else
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQmlComponent component(&engine, QUrl(QStringLiteral("qrc:/MyTextField.qml")));

    QList<QObject *> rootObjects = engine.rootObjects();
    //QObject *parentItem = rootObjects.first();
    QQuickItem *parentItem = qvariant_cast<QQuickItem*>(rootObjects.first()->property("contentItem"));

    //childItem->setParent(parentItem);
    QObject *childObj = component.create();
    QQuickItem *childItem = qobject_cast<QQuickItem*>(childObj);
    childItem->setParentItem(parentItem);

    QQmlEngine::setObjectOwnership(childItem, QQmlEngine::CppOwnership);

    return app.exec();
}
#endif
