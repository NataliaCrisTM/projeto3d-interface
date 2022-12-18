#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setDimensoes(int linhas, int colunas, int planos);
    void setColor();

private slots:
    void on_actionColorcar_Voxel_triggered();

    void on_actionApagar_Voxel_triggered();

    void on_actionColocar_Cubo_triggered();

    void on_actionApagar_Cubo_triggered();

    void on_actionColocar_Esfera_triggered();

    void on_actionApagar_Esfera_triggered();

    void on_actionColocar_Elipse_triggered();

    void on_actionApagar_Elipse_triggered();

    void on_raio_x_slider_valueChanged(int value);

    void on_raio_y_slider_valueChanged(int value);

    void on_raio_z_slider_valueChanged(int value);

    void on_raio_esfera_slider_valueChanged(int value);

    void on_cor_r_slider_valueChanged(int value);

    void on_cor_g_slider_valueChanged(int value);

    void on_cor_b_slider_valueChanged(int value);

    void on_cor_a_slider_valueChanged(int value);

    void on_cubo_x_slider_valueChanged(int value);

    void on_cubo_y_slider_valueChanged(int value);

    void on_cubo_z_slider_valueChanged(int value);

    void on_slider_plan_z_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
