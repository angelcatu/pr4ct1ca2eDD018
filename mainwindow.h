#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arbolbb.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{    
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getNombreArchivo();

private slots:

    void on_actionAbrir_triggered();

    void on_actionAcerca_de_triggered();

    void on_btnAnalizar_clicked();

    void on_actionMostrar_rbol_triggered();

    void on_actionEliminar_EDD_triggered();

    void on_actionEliminar_datos_triggered();

    void on_actionAnalizar_triggered();

    void on_actionCerrar_triggered();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
