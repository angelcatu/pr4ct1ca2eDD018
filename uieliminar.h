#ifndef UIELIMINAR_H
#define UIELIMINAR_H

#include <QDialog>

namespace Ui {
class uiEliminar;
}

class uiEliminar : public QDialog
{
    Q_OBJECT

public:
    explicit uiEliminar(QWidget *parent = nullptr);
    ~uiEliminar();




    void setPath(QString path_);
    QString getPath();

private slots:


    void on_table_cellClicked(int row, int column);

    void on_btn_Eliminar_clicked();

private:
    Ui::uiEliminar *ui;
    void cargarDatos();
    int longitudVector();
    QString path;
};

#endif // UIELIMINAR_H
