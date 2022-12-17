#include "prewindow.h"
#include "ui_prewindow.h"

PreWindow::PreWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PreWindow)
{
    ui->setupUi(this);
}

PreWindow::~PreWindow()
{
    delete ui;
}

PreWindow::setNext(MainWindow* next) {
    this->next = next;
}

void PreWindow::on_pushButton_clicked()
{
    auto linhas = ui->linha_slider->value();
    auto colunas = ui->coluna_slider->value();
    auto planos = ui->plano_slider->value();

    this->next->setDimensoes(linhas, colunas, planos);

    this->hide();
    this->next->show();
}


void PreWindow::on_linha_slider_valueChanged(int value)
{
    ui->linha_label->setText(QString::number(value));
}



void PreWindow::on_coluna_slider_valueChanged(int value)
{
    ui->coluna_label->setText(QString::number(value));
}


void PreWindow::on_plano_slider_valueChanged(int value)
{
    ui->plano_label->setText(QString::number(value));
}

