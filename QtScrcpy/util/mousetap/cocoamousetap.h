#ifndef COCOAMOUSETAP_H
#define COCOAMOUSETAP_H
#include <QThread>
#include <QSemaphore>

#include "mousetap.h"

struct MouseEventTapData;
class QWidget;
class CocoaMouseTap : public MouseTap, public QThread
{
private:
    CocoaMouseTap(QObject *parent = Q_NULLPTR);
    virtual ~CocoaMouseTap();

public:
    void initMouseEventTap() override;
    void quitMouseEventTap() override;
    void enableMouseEventTap(QWidget* widget, bool enabled) override;

protected:
    void run() override;

private:
    MouseEventTapData *m_tapData = Q_NULLPTR;
    QSemaphore m_runloopStartedSemaphore;
};

#endif // COCOAMOUSETAP_H
