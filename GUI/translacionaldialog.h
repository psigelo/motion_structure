#ifndef TRANSLACIONALDIALOG_H
#define TRANSLACIONALDIALOG_H

#include <QDialog>

namespace Ui {
class TranslacionalDialog;
}

class TranslacionalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TranslacionalDialog(QWidget *parent = 0);
    ~TranslacionalDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TranslacionalDialog *ui;
};

#endif // TRANSLACIONALDIALOG_H
