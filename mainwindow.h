#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
