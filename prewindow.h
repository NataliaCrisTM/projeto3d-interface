#ifndef PREWINDOW_H
#define PREWINDOW_H

#include "mainwindow.h"
#include "prewindow.h"
#include <QMainWindow>

namespace Ui {
class PreWindow;
}

class PreWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit PreWindow(QWidget *parent = nullptr);
  ~PreWindow();
  void setNext(MainWindow *next);

private slots:
  void on_pushButton_clicked();

  void on_linha_slider_valueChanged(int value);

  void on_coluna_slider_valueChanged(int value);

  void on_plano_slider_valueChanged(int value);

private:
  Ui::PreWindow *ui;
  MainWindow *next;
};

#endif // PREWINDOW_H
