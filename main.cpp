#include "mainwindow.h"
#include "prewindow.h"

#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "imprimindo\n";
    QApplication a(argc, argv);
    PreWindow w;
    MainWindow w2;
    w.setNext(&w2);
    w.show();
    return a.exec();
}
