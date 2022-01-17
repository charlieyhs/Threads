#ifndef DUTHREAD_H
#define DUTHREAD_H

#include <QThread>

class DuThread : public QThread
{
    Q_OBJECT // se debe incluir esto para poder tener señales
public:
    DuThread(int tiempo,QObject *parent = nullptr);
signals:
    void valorCambiado(int);
protected:
    void run()override;
private:
    int mTiempo; // milisegundos

};

#endif // DUTHREAD_H
