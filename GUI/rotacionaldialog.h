#ifndef ROTACIONALDIALOG_H
#define ROTACIONALDIALOG_H

#include <QDialog>

namespace Ui {
class RotacionalDialog;
}

class RotacionalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RotacionalDialog(QWidget *parent = 0);
    ~RotacionalDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RotacionalDialog *ui;
};

#endif // ROTACIONALDIALOG_H
