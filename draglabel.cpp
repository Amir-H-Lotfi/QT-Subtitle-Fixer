#include "draglabel.h"
#include "convertor.h"

/**
 * @brief DragLabel::DragLabel
 * @param parent
 * costomizing standard label
 */
DragLabel::DragLabel(QWidget* parent)
    :QLabel(parent)
{
    setText(m_text);
    setWordWrap(true);
    setAcceptDrops(true);
    setAlignment(Qt::AlignCenter);
    setFrameStyle(QFrame::Panel);
}

DragLabel::~DragLabel()
{

}
/**
 * @brief DragLabel::dropEvent
 * @param event
 */
void DragLabel::dropEvent(QDropEvent* event)
{
    const QMimeData* mimeData = event->mimeData();
    if (mimeData->hasUrls())
    {
        event->acceptProposedAction();
    }
}
/**
 * @brief DragLabel::dragEnterEvent
 * @param event
 */
void DragLabel::dragEnterEvent (QDragEnterEvent* event)
{
    QRunnable* runnable = new Convertor(event->mimeData()->urls());
    QThreadPool::globalInstance()->start(runnable);
    event->acceptProposedAction();
}
