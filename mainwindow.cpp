#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Acao.h"
#include <cmath>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::setDimensoes(int linhas, int colunas, int planos) {
  ui->fundo->setDimensoes(linhas, colunas, planos);
  auto min = std::min({linhas, colunas, planos});
  ui->raio_esfera_slider->setMaximum(std::ceil((double)min / 2));
  ui->raio_x_slider->setMaximum(std::ceil((double)linhas / 2));
  ui->raio_y_slider->setMaximum(std::ceil((double)colunas / 2));
  std::cout << std::ceil(planos / 2) << '\n';
  ui->raio_z_slider->setMaximum(std::ceil((double)planos / 2));
  ui->cubo_x_slider->setMaximum(linhas);
  ui->cubo_y_slider->setMaximum(colunas);
  ui->cubo_z_slider->setMaximum(planos);

  ui->slider_plan_z->setMaximum(planos - 1);
  std::cout << "set dimensoes\n";
}

void MainWindow::setColor() {
  auto r = ui->cor_r_slider->value() / 255;
  auto g = ui->cor_g_slider->value() / 255;
  auto b = ui->cor_b_slider->value() / 255;
  auto a = ui->cor_a_slider->value() / 255;
  ui->fundo->setColor(r, g, b, a);
}

void MainWindow::on_actionColorcar_Voxel_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::PUT_VOXEL);
}

void MainWindow::on_actionApagar_Voxel_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::CUT_VOXEL);
}

void MainWindow::on_actionColocar_Cubo_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::PUT_BOX);

  auto x = ui->cubo_x_slider->value();
  auto y = ui->cubo_y_slider->value();
  auto z = ui->cubo_z_slider->value();

  ui->fundo->setDimCubo(x, y, z);
}

void MainWindow::on_actionApagar_Cubo_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::CUT_BOX);
  auto x = ui->cubo_x_slider->value();
  auto y = ui->cubo_y_slider->value();
  auto z = ui->cubo_z_slider->value();

  ui->fundo->setDimCubo(x, y, z);
}

void MainWindow::on_actionColocar_Esfera_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::PUT_SPHERE);
  auto raio = ui->raio_esfera_slider->value();

  ui->fundo->setRaioEsfera(raio);
}

void MainWindow::on_actionApagar_Esfera_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::CUT_SPHERE);
  auto raio = ui->raio_esfera_slider->value();

  ui->fundo->setRaioEsfera(raio);
}

void MainWindow::on_actionColocar_Elipse_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::PUT_ELLIPSOID);
  auto raiox = ui->raio_x_slider->value();
  auto raioy = ui->raio_y_slider->value();
  auto raioz = ui->raio_z_slider->value();

  ui->fundo->setRaioEllipsoid(raiox, raioy, raioz);
}

void MainWindow::on_actionApagar_Elipse_triggered() {
  setColor();
  ui->fundo->setAcao(Acao::CUT_ELLIPSOID);
  auto raiox = ui->raio_x_slider->value();
  auto raioy = ui->raio_y_slider->value();
  auto raioz = ui->raio_z_slider->value();

  ui->fundo->setRaioEllipsoid(raiox, raioy, raioz);
}

void MainWindow::on_raio_x_slider_valueChanged(int value) {
  ui->raio_x_label->setText(QString::number(value));
}

void MainWindow::on_raio_y_slider_valueChanged(int value) {
  ui->raio_y_label->setText(QString::number(value));
}

void MainWindow::on_raio_z_slider_valueChanged(int value) {
  ui->raio_z_label->setText(QString::number(value));
}

void MainWindow::on_raio_esfera_slider_valueChanged(int value) {
  ui->raio_esfera_label->setText(QString::number(value));
}

void MainWindow::on_cor_r_slider_valueChanged(int value) {
  ui->cor_r_label->setText(QString::number(value));
}

void MainWindow::on_cor_g_slider_valueChanged(int value) {
  ui->cor_g_label->setText(QString::number(value));
}

void MainWindow::on_cor_b_slider_valueChanged(int value) {
  ui->cor_b_label->setText(QString::number(value));
}

void MainWindow::on_cor_a_slider_valueChanged(int value) {
  ui->cor_a_label->setText(QString::number(value));
}

void MainWindow::on_cubo_x_slider_valueChanged(int value) {
  ui->cubo_x_label->setText(QString::number(value));
}

void MainWindow::on_cubo_y_slider_valueChanged(int value) {
  ui->cubo_y_label->setText(QString::number(value));
}

void MainWindow::on_cubo_z_slider_valueChanged(int value) {
  ui->cubo_z_label->setText(QString::number(value));
}

void MainWindow::on_slider_plan_z_valueChanged(int value) {
  ui->dim_plan_z->setText(QString::number(value));
  ui->fundo->setPlano(value);
  ui->fundo->repaint();
}

void MainWindow::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar arquivo off", QString(), "Arquivo off (*.off)");

    ui->fundo->writeOFF(fileName.toStdString().c_str());
}

