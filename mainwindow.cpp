#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_simplex->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_continuar_clicked()
{
    qtd_variaveis = ui->lineEdit_NumVariaveis->text().toInt();
    qtd_restricoes = ui->lineEdit_NumRestricoes->text().toInt();

    ui->Funcao_x1->hide();
    ui->Funcao_x2->hide();
    ui->Funcao_x3->hide();
    ui->Funcao_x4->hide();
    ui->label_plus_x1->hide();
    ui->label_plus_x2->hide();
    ui->label_plus_x3->hide();
    ui->label_x1->hide();
    ui->label_x2->hide();
    ui->label_x3->hide();
    ui->label_x4->hide();

    if (qtd_variaveis == 1){
        ui->Funcao_x1->show();
        ui->label_x1->show();
        ui->widget_simplex->show();
    } else if (qtd_variaveis == 2){
        ui->Funcao_x1->show();
        ui->label_x1->show();
        ui->label_plus_x1->show();
        ui->Funcao_x2->show();
        ui->label_x2->show();
        ui->widget_simplex->show();
    } else if (qtd_variaveis == 3){
        ui->Funcao_x1->show();
        ui->label_x1->show();
        ui->label_plus_x1->show();
        ui->Funcao_x2->show();
        ui->label_x2->show();
        ui->label_plus_x2->show();
        ui->Funcao_x3->show();
        ui->label_x3->show();
        ui->widget_simplex->show();
    } else if (qtd_variaveis == 4){
        ui->Funcao_x1->show();
        ui->label_x1->show();
        ui->label_plus_x1->show();
        ui->Funcao_x2->show();
        ui->label_x2->show();
        ui->label_plus_x2->show();
        ui->Funcao_x3->show();
        ui->label_x3->show();
        ui->label_plus_x3->show();
        ui->Funcao_x4->show();
        ui->label_x4->show();
        ui->widget_simplex->show();
    } else if (qtd_variaveis > 4 || qtd_variaveis < 1){
        QMessageBox msg; msg.setText("Quantidade de variáveis não permitida!");
        msg.exec();
    }

//    restrictedOptimizationHandler::linProg<double> *opt = new restrictedOptimizationHandler::simplex<double> ();

    LinAlg::Matrix<double> A,b;

    A = "20,30;1,0;0,1";
    b = "1200;40;30";

    MatrixRestrictionHandler::MatrixPositiveInequality<double> P = (A < b);
    MatrixRestrictionHandler::MatrixNegativeInequality<double> N;// = (A > b);
    MatrixRestrictionHandler::MatrixEquality<double> E; //= (A == b);
//    (*opt) = P;

    restrictedOptimizationHandler::simplex<double> simp;
    simp.setRestrictions(E,N,P);
    simp.setfunction2Optimize("1000;1800");
    simp.optimize();
    std::cout << simp.getOptimizatedValue() << std::endl;
//    opt->setfunction2Optimize("-1000;-1800");
//    opt->optimize();



//   std::cout << opt->getOptimizatedValue() << std::endl;
}
