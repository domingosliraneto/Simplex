#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QProcess>
#include <iostream>

#include "SistemasdeControle/headers/restrictedOptimization/activeset.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    int qtd_variaveis = 0;
    int qtd_restricoes = 0;

private slots:
    void on_pushButton_continuar_clicked();

    void on_pushButton_calcular_clicked();

    void on_pushButton_reiniciar_clicked();

    void on_comboBox_objetivo_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
