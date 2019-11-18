#ifndef MYGLOBALOBJECT_H
#define MYGLOBALOBJECT_H

#include <QObject>
class QQmlApplicationEngine;

class MyGlobalObject : public QObject
{
    Q_OBJECT
public:
    explicit MyGlobalObject(QObject *parent = nullptr);
    QQmlApplicationEngine* engine;

signals:

public slots:
    void doSomething(const QString &text);
};

#endif // MYGLOBALOBJECT_H
