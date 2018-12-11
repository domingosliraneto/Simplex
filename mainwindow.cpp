#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget_simplex->hide();
    ui->widget_3->hide();
    ui->label_otima->hide();

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

    std::string qqtdvariaveis;
    for (int i=1;i<=qtd_variaveis;i++){
        qqtdvariaveis += 'X'+ std::to_string(i) + ' ';
    }
    qqtdvariaveis += "≥ 0";
    ui->label_restricaotodos->setText(QString::fromStdString(qqtdvariaveis));


}

void MainWindow::on_pushButton_calcular_clicked()
{
    LinAlg::Matrix<double> A,b,func;
    QString stringfuncao;

    if (!ui->Funcao_x1->text().isEmpty()){
        stringfuncao += ui->Funcao_x1->text();
        stringfuncao += ";";
    }
    if (!ui->Funcao_x2->text().isEmpty()){
        stringfuncao += ui->Funcao_x2->text();
        stringfuncao += ";";
    }
    if (!ui->Funcao_x3->text().isEmpty()){
        stringfuncao += ui->Funcao_x3->text();
        stringfuncao += ";";
    }
    if (!ui->Funcao_x4->text().isEmpty()){
        stringfuncao += ui->Funcao_x4->text();
    }
    func= LinAlg::Matrix<double>(stringfuncao.toStdString()) ;

    A = LinAlg::Matrix<double>(ui->lineEdit_A->text().toStdString());
    b = LinAlg::Matrix<double>(ui->lineEdit_b->text().toStdString());

    MatrixRestrictionHandler::MatrixPositiveInequality<double> P = (A < b);
    MatrixRestrictionHandler::MatrixNegativeInequality<double> N;// = (A > b);
    MatrixRestrictionHandler::MatrixEquality<double> E; //= (A == b);

    if (ui->comboBox_inequacao->currentIndex() == 0){
        P = (A < b);
        std::cout << "inequacao de menor igual" << std::endl;
    } else if (ui->comboBox_inequacao->currentIndex() == 1){
        E = (A == b);
        std::cout << "inequacao de igualdade" << std::endl;
    } else if (ui->comboBox_inequacao->currentIndex() == 2){
        N = (A > b);
        std::cout << "inequacao de maior igual" << std::endl;
    }


    restrictedOptimizationHandler::simplex<double> simp;
    simp.setRestrictions(E,N,P);
    simp.setfunction2Optimize(func);
    simp.optimize();

    LinAlg::Matrix<double> resultado = simp.getOptimizatedValue();

    std::string variaveis;

    for (int i=1;i<=qtd_variaveis;i++){
        std::ostringstream ostr; ostr << resultado(i,1);
        variaveis += 'X'+ std::to_string(i) + '=' +  ostr.str() + ' ';
    }



    QString Qvariaveis = QString::fromStdString(variaveis);
    QLabel *Xs = new QLabel();
    Xs->setText(Qvariaveis);
    Xs->setStyleSheet("font: 12pt;");

    ui->horizontalLayout_5->addWidget(Xs,Qt::AlignCenter);

    int result = 0;

    for (int i=1;i<=qtd_restricoes;i++){
        result = result + (func(i,1)*resultado(i,1));
    }

    std::ostringstream strs;
    strs << result;
    std::string str = strs.str();
    ui->label_solucao_Z->setText(QString::fromStdString(str));
    ui->widget_3->show();
    ui->label_otima->show();

}

void MainWindow::on_pushButton_reiniciar_clicked()
{
    QProcess::startDetached(QApplication::applicationFilePath());
    exit(12);
}

void MainWindow::on_comboBox_objetivo_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Minimizar"){
        QMessageBox msg; msg.setText("Para Minimizar, necessário alterar no arquivo Simplex.hpp na linha 76!");
        msg.exec();
        ui->comboBox_objetivo->setCurrentIndex(0);
    }

}
