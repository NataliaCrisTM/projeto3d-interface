#ifndef FUNDO_H
#define FUNDO_H

#include <QWidget>
#include <QMouseEvent>
#include "Acao.h"
#include "sculptor.h"

class Fundo : public QWidget
{
    Q_OBJECT
private:
    double altura, largura;
    int plano;
    Acao acao;
    float r, g, b, a;
    Sculptor* sculptor;
    float x, y, z;
    int raio;
    int raiox,raioy,raioz;
public:
    explicit Fundo(QWidget *parent = nullptr);
    void setDimensoes(int linhas, int colunas, int planos);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setColor(float r, float g, float b, float a);
    void setAcao(Acao acao);
    void setDimCubo(float x, float y, float z);
    void setRaioEsfera(int raio);
    void setRaioEllipsoid(int raiox, int raioy, int raioz);
    void setPlano(int plano);
    void writeOFF(const char* filename);
signals:

};

#endif // FUNDO_H
