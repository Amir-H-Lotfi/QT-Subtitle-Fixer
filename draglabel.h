#ifndef DRAGLABEL_H
#define DRAGLABEL_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMimeData>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QThreadPool>

class DragLabel : public QLabel
{
public:
    DragLabel(QWidget* parent = nullptr);
    ~DragLabel();
protected :
    void dropEvent(QDropEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
private :
    const QString m_text =
            R"(
<h5>
    This Application fixes subtitle unicode for Persian and Arabic
    subtitle files (.srt) that will be shown correctly on every DVD Player
</h5>
<h3>
    Drag and Drop your SRT files here!
</h3>
)";
};

#endif // DRAGLABEL_H
