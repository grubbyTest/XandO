#ifndef TOSET_H
#define TOSET_H

#include <QDialog>

namespace Ui {
class toSet;
}

class toSet : public QDialog
{
    Q_OBJECT

public:
    explicit toSet(QWidget *parent = nullptr);
    ~toSet();

private:
    Ui::toSet *ui;
};

#endif // TOSET_H
