#ifndef OWNCLOUDDOLPHINACTIONPLUGIN_H
#define OWNCLOUDDOLPHINACTIONPLUGIN_H

#include <KAbstractFileItemActionPlugin>
#include <KCoreDirLister>
#include <KFileItemListProperties>

class QAction;
class QWidget;

class OwncloudDolphinPluginAction : public KAbstractFileItemActionPlugin
{
    Q_OBJECT
public:
    explicit OwncloudDolphinPluginAction(QObject *parent, const QVariantList &args);

    QList<QAction *> actions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget) override;

private:
    QList<QAction *> legacyActions(const KFileItemListProperties &fileItemInfos, QWidget *parentWidget);
};

#endif // OWNCLOUDDOLPHINACTIONPLUGIN_H
