#include "RoomsDockWidget.h"
#include "ui_RoomsDockWidget.h"

RoomsDockWidget::RoomsDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::RoomsDockWidget)
{
    ui->setupUi(this);
}

RoomsDockWidget::~RoomsDockWidget()
{
    delete ui;
}
