#include "myglobalobject.h"
#include <QDebug>

#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>

#include <QtQuickControls2>

MyGlobalObject::MyGlobalObject(QObject *parent) : QObject(parent)
{

}


void MyGlobalObject::doSomething(const QString &text) {
    qDebug() << "MyGlobalObject doSomething called with" << text;

//    //https://forum.qt.io/topic/59547/loading-qml-file-as-a-component-from-c-to-qqmlapplicationengine/2
//    QObject *rootObject = engine->rootObjects().first();
//    QObject *container = rootObject->children()[1]->children()[1];
//    QQuickItem *parentItem = qvariant_cast<QQuickItem*>(container->property("contentItem"));
//    //QQuickItem *parentItem = qvariant_cast<QQuickItem*>(rootObject->property("contentItem"));
//    //QList<QObject *> rootObjects = engine.rootObjects();
//    //QQuickItem *parentItem = qvariant_cast<QQuickItem*>(rootObjects.first()->property("contentItem"));

//    //https://doc.qt.io/qt-5/qtqml-cppintegration-interactqmlfromcpp.html
//    //https://www.qtcentre.org/threads/69952-Loading-additional-QML-files
//    QQmlComponent component(engine,
//            QUrl::fromLocalFile("qrc:/Rectangle.qml"));

//    QObject *childObj = component.create();
//    QQuickItem *childItem = qobject_cast<QQuickItem*>(childObj);
//    childItem->setParentItem(parentItem);
//    QQmlEngine::setObjectOwnership(childItem, QQmlEngine::CppOwnership);


    QQuickView view;
    view.setSource(QUrl::fromLocalFile("Item.qml"));
    view.show();
    QObject *object = view.rootObject();
    object->setProperty("width", 500);
    QQmlProperty(object, "width").write(500);
}
