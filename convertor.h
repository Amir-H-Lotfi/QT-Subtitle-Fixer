#ifndef CONVERTOR_H
#define CONVERTOR_H

#include <QRunnable>
#include <QUrl>
#include <QList>
#include <QTextCodec>
#include <QFile>
#include <QFileInfo>
#include <QDir>

class Convertor : public QRunnable
{
public:
    Convertor(QList<QUrl>);
    virtual ~Convertor();

    void run() override;

private :
    QList<QUrl> m_urls;
};

#endif // CONVERTOR_H
