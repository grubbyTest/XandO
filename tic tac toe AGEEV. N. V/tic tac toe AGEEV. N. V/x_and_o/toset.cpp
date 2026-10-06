#include "toset.h"
#include "ui_toset.h"

toSet::toSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::toSet)
{
    ui->setupUi(this);
}

toSet::~toSet()
{
    delete ui;
}
