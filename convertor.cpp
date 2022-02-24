#include "convertor.h"

Convertor::Convertor(QList<QUrl> urls)
{
    this->m_urls = urls;
}

/**
 * @brief convertor::~convertor
 * nothing to destroy XD
 */
Convertor ::~Convertor()
{

}

/**
 * @brief convertor::run
 * we need to iterate over the urls, then we read files and decode them to windows-1256.
 * all input files are encoded in windows-1252.
 */
void Convertor::run() {
    QTextCodec* codec = QTextCodec::codecForName("windows-1256");
    if (codec != nullptr)
    {
        foreach (QUrl url, m_urls)
        {
            if (url.fileName().endsWith(".srt"))
            {
                QString nname= QFileInfo(url.toLocalFile()).absoluteDir().path() + R"(/[Edited])" + url.fileName();

                QFile* in = new QFile(url.toLocalFile());
                QFile* out= new QFile(nname);

                in->open(QIODevice::OpenModeFlag::ReadOnly);
                out->open(QIODevice::OpenModeFlag::WriteOnly);

                if (in->isOpen() and out->isOpen())
                {
                    QTextStream ostream {out};
                    QString encoded = codec->toUnicode(in->readAll());
                    ostream << encoded ;
                }
                in->close();
                out->close();
            }
        }
    }
}
