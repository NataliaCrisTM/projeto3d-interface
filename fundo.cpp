#include "fundo.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <iostream>

Fundo::Fundo(QWidget *parent)
    : QWidget{parent}
{

}

void Fundo::setDimensoes(int linhas, int colunas, int planos) {
    sculptor = new Sculptor(linhas, colunas, planos);
}

void Fundo::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    auto linhas = sculptor->getnx();
    auto colunas = sculptor->getny();
    auto planos = sculptor->getnz();

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(255,255,255));
    brush.setStyle(Qt::SolidPattern);

    pen.setColor(QColor(0,0,0));
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(0,0,width(),height());

    altura = (double)height() / linhas;
    largura = (double)width() / colunas;

    pen.setWidth(1);
    painter.setPen(pen);

    for (int i = 1; i<=linhas; i++){
        painter.drawLine(0, i * altura, width(), i * altura);
    }

    for (int i = 1; i<=colunas; i++){
        painter.drawLine(i * largura, 0, i * largura, height());
    }

//    brush.setColor(QColor(0,0,0));
//    painter.setBrush(brush);
    for (int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++){
            auto voxel = sculptor->getVoxel(i, j, plano);
            if (voxel.isOn){
                std::cout << "printing voxel " << i << ", " << j << ", " << plano << "\n";
                std::cout << "color: " << voxel.r << ", " << voxel.g << ", " << voxel.b <<  ", " << voxel.a << "\n";
                int pos_linha = i * altura;
                int pos_coluna = j * largura;

                brush.setColor(QColor(voxel.r * 255, voxel.g * 255, voxel.b * 255, voxel.a * 255));
                painter.setBrush(brush);
                painter.drawRect(pos_coluna,pos_linha,largura,altura);
            }
        }

    }
}

void Fundo::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() != Qt::LeftButton){
        return;
    }

    int pos_coluna = event->x();
    int pos_linha = event->y();

    int linha = pos_linha / altura;
    int coluna = pos_coluna / largura;

    switch (acao) {
        case Acao::PUT_VOXEL:
            PutVoxel(linha, coluna, plano, r, g, b, a).draw(*sculptor);
        break;
        case Acao::CUT_VOXEL:
            CutVoxel(linha, coluna, plano).draw(*sculptor);
        break;
        case Acao::PUT_BOX:
            std::cout << "cubo: " << linha << ", " << coluna << ", " << plano << ", " << linha + x << ", " << coluna + y << ", " << plano + z << "\n";
            PutBox(linha, linha + x,coluna, coluna + y, plano, plano + z, r, g, b, a).draw(*sculptor);
        break;
        case Acao::CUT_BOX:
            CutBox(linha, linha + x, coluna, coluna + y,  plano, plano + y).draw(*sculptor);
        break;
        case Acao::PUT_SPHERE:
            PutSphere(linha, coluna, plano, raio, r, g, b, a).draw(*sculptor);
        break;
        case Acao::CUT_SPHERE:
            CutSphere(linha, coluna, plano, raio).draw(*sculptor);
        break;
        case Acao::PUT_ELLIPSOID:
            PutEllipsoid(linha, coluna, plano, raiox, raioy, raioz, r, g, b, a).draw(*sculptor);
        break;
        case Acao::CUT_ELLIPSOID:
            CutEllipsoid(linha, coluna, plano, raiox, raioy, raioz).draw(*sculptor);
        break;
    }

    repaint();
}

void Fundo::setColor(float r, float g, float b, float a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Fundo::setAcao(Acao acao)
{
    this->acao = acao;
}

void Fundo::setDimCubo(float x, float y, float z)
{

    this->x = x;
    this->y = y;
    this->z = z;
}

void Fundo::setRaioEsfera(int raio)
{
    this->raio = raio;
}

void Fundo::setRaioEllipsoid(int raiox,int raioy,int raioz)
{
    this -> raiox = raiox;
    this -> raioy = raioy;
    this -> raioz = raioz;
}

void Fundo::setPlano(int plano)
{
    this-> plano = plano;
    std::cout << "set plano to " << plano << "\n";
}

void Fundo::writeOFF(const char *filename)
{
    sculptor->writeOFF(filename);
}

