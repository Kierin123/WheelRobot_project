#ifndef DIALOGLOAD_H
#define DIALOGLOAD_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class DialogLoad;
}

class DialogLoad : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLoad(QWidget *parent = nullptr);
    ~DialogLoad();

private:
    Ui::DialogLoad *ui;

    QFileSystemModel *fileSystemModel;

};

#endif // DIALOGLOAD_H
