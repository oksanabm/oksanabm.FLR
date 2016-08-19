#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPoint>
#include <QString>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //установка иконки
    setWindowIcon(QIcon(":/resources/icon.png"));

    // Запрет изменения размеров формы
    this->setMinimumSize(this->size());
    this->setMaximumSize(this->size());

    // Перемещение в центр экрана
    QPoint center = QApplication::desktop()->availableGeometry().center();
    QPoint corner = QApplication::desktop()->availableGeometry().topLeft();
    center.setX(center.x() - this->width() / 2);
    center.setY(center.y() - this->height() / 2);
    if(center.x() <= corner.x() || center.y() <= corner.y())
        this->move(corner);
    else
        this->move(center);

    // Установим активной вкладку с исходными данными
    ui->tabWidget->setCurrentIndex(0);

    //максимальное значение количества наблюдений
    ui->spinBox->setMaximum(500);

    //максимальное и минимальное значения для ошибки
    ui->spinBox_6->setMinimum(0);
    ui->spinBox_6->setMaximum(100);

    //установка мин и макс для границ варьирования
    ui->doubleSpinBox_2->setMinimum(-10.0);
    ui->doubleSpinBox_2->setMaximum(10.0);
    ui->doubleSpinBox_3->setMinimum(-10.0);
    ui->doubleSpinBox_3->setMaximum(10.0);

    //установка мин и макс для количества ФП
    ui->spinBox_7->setMinimum(2);
    ui->spinBox_7->setMaximum(21);

    ui->radioButton->click();//активизация радиокнопки "1 фактор"
    ui->radioButton_12->setChecked(true);//активизация радиокнопки "1 правило"
    ui->spinBox_2->setValue(1);

        ui->radioButton_56->setEnabled(false);
        ui->radioButton_57->setEnabled(false);
        ui->radioButton_58->setEnabled(false);
        ui->radioButton_59->setEnabled(false);
        ui->radioButton_60->setEnabled(false);
        ui->radioButton_61->setEnabled(false);
        ui->radioButton_62->setEnabled(false);
        ui->radioButton_63->setEnabled(false);
        ui->radioButton_64->setEnabled(false);

    //--------установка начальных данных для 2ой вкладки

    ui->spinBox_10->setValue(2);
    ui->spinBox_10->setMinimum(2);
    ui->spinBox_11->setValue(2);
    ui->doubleSpinBox->setMinimum(0.01);
    ui->doubleSpinBox->setMaximum(0.5);
    ui->doubleSpinBox->setValue(0.000000001);
    ui->doubleSpinBox->setDecimals(10);
    ui->radioButton_3->click();
    //--------------------------------------

    //скрыть все правила, кроме первых для А
    ui->groupBox_8->setVisible(true);
    ui->label_5->setVisible(true);//A
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H

    //значение количества наблюдений по умолчанию
    ui->spinBox->setValue(100);

    // Задаем умолчательные значения границ факторов
    ui->doubleSpinBox_2->setValue(-1.0);
    ui->doubleSpinBox_3->setValue(1.0);

    //умолчательный вид ФП - треугольные
    ui->radioButton_10->setChecked(true);


    //проверка на количество правил
    systemRules();

    //подпись координатных осей у графика
    ui->widget->axisX = "X";
    ui->widget->axisY = "Y";

}

QTimer *tmr;

//деструктор
MainWindow::~MainWindow()
{
    delete ui;
}

//радиокнопка для х1 - radioButton
void MainWindow::on_radioButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        ui->radioButton_10->setChecked(true);
        FL.inData.dimFactor = 1;
        ui->radioButton_10->setEnabled(true);
        ui->radioButton_11->setEnabled(true);
        ui->radioButton_5->setEnabled(true);
        ui->radioButton_6->setEnabled(true);
        ui->radioButton_54->setEnabled(true);
        ui->radioButton_55->setEnabled(true);
        ui->radioButton_56->setEnabled(false);
        ui->radioButton_57->setEnabled(false);
        ui->radioButton_58->setEnabled(false);
        ui->radioButton_59->setEnabled(false);
        ui->radioButton_60->setEnabled(false);
        ui->radioButton_61->setEnabled(false);
        ui->radioButton_62->setEnabled(false);
        ui->radioButton_63->setEnabled(false);
        ui->radioButton_64->setEnabled(false);
    }
    systemRules();
}

//если выбрано два фактора
void MainWindow::on_radioButton_2_clicked()
{
    if(ui->radioButton_2->isChecked())
    {
        ui->radioButton_56->setChecked(true);//активизация радиокнопки "1 фактор"
        FL.inData.dimFactor = 2;
        ui->radioButton_56->setEnabled(true);
        ui->radioButton_57->setEnabled(true);
        ui->radioButton_58->setEnabled(true);
        ui->radioButton_59->setEnabled(true);
        ui->radioButton_60->setEnabled(true);
        ui->radioButton_61->setEnabled(true);
        ui->radioButton_10->setEnabled(false);
        ui->radioButton_11->setEnabled(false);
        ui->radioButton_5->setEnabled(false);
        ui->radioButton_6->setEnabled(false);
        ui->radioButton_54->setEnabled(false);
        ui->radioButton_55->setEnabled(false);
        ui->radioButton_62->setEnabled(false);
        ui->radioButton_63->setEnabled(false);
        ui->radioButton_64->setEnabled(false);
    }
}

void MainWindow::on_radioButton_7_clicked()
{
    if(ui->radioButton_7->isChecked())
    {
        ui->radioButton_62->setChecked(true);//активизация радиокнопки "1 фактор"
        FL.inData.dimFactor = 3;
        ui->radioButton_62->setEnabled(true);
        ui->radioButton_63->setEnabled(true);
        ui->radioButton_64->setEnabled(true);
        ui->radioButton_10->setEnabled(false);
        ui->radioButton_11->setEnabled(false);
        ui->radioButton_5->setEnabled(false);
        ui->radioButton_6->setEnabled(false);
        ui->radioButton_54->setEnabled(false);
        ui->radioButton_55->setEnabled(false);
        ui->radioButton_56->setEnabled(false);
        ui->radioButton_57->setEnabled(false);
        ui->radioButton_58->setEnabled(false);
        ui->radioButton_59->setEnabled(false);
        ui->radioButton_60->setEnabled(false);
        ui->radioButton_61->setEnabled(false);
    }
}

//показать/скрыть нужное правило
void MainWindow::systemRules()
{
    if(ui->radioButton->isChecked())//если 1 фактор
    {
        if(ui->radioButton_10->isChecked())//если A
        {
             ui->label_5->setVisible(true);//A
        }
    }
}

//радиокнопка система правил А
void MainWindow::on_radioButton_10_clicked()
{
    ui->label_5->setVisible(true);//A
    FL.inData.numberFunction = 1;
    ui->doubleSpinBox_2->setValue(-1.0);
    ui->doubleSpinBox_3->setValue(1.0);
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил B
void MainWindow::on_radioButton_11_clicked()
{
    ui->label_6->setVisible(true);//B
    FL.inData.numberFunction = 2;
    ui->doubleSpinBox_2->setValue(-1.0);
    ui->doubleSpinBox_3->setValue(3.0);
    ui->label_5->setVisible(false);//A
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил C
void MainWindow::on_radioButton_5_clicked()
{
    ui->label_7->setVisible(true);//C
    FL.inData.numberFunction = 3;
    ui->doubleSpinBox_2->setValue(-1.0);
    ui->doubleSpinBox_3->setValue(1.0);
    ui->label_5->setVisible(false);//A
    ui->label_6->setVisible(false);//B
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил D
void MainWindow::on_radioButton_6_clicked()
{
    ui->label_8->setVisible(true);//D
    FL.inData.numberFunction = 4;
    ui->doubleSpinBox_2->setValue(-1.0);
    ui->doubleSpinBox_3->setValue(1.0);
    ui->label_5->setVisible(false);//A
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил E
void MainWindow::on_radioButton_54_clicked()
{
    ui->label_9->setVisible(true);//E
    FL.inData.numberFunction = 5;
    ui->doubleSpinBox_2->setValue(-1.0);
    ui->doubleSpinBox_3->setValue(1.0);
    ui->label_5->setVisible(false);//A
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил F
void MainWindow::on_radioButton_55_clicked()
{
    ui->label_11->setVisible(true);//F
    FL.inData.numberFunction = 6;
    ui->doubleSpinBox_2->setValue(0.0);
    ui->doubleSpinBox_3->setValue(2.0);
    ui->label_5->setVisible(false);//A
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_15->setVisible(false);//G
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил G
void MainWindow::on_radioButton_56_clicked()
{
    ui->label_15->setVisible(true);//G
    FL.inData.numberFunction = 7;
    ui->doubleSpinBox_2->setValue(0.5);
    ui->doubleSpinBox_3->setValue(4.0);
    ui->label_5->setVisible(false);//A
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_16->setVisible(false);//H
}

//радиокнопка система правил H
void MainWindow::on_radioButton_57_clicked()
{
    ui->label_16->setVisible(true);//H
    FL.inData.numberFunction = 8;
    ui->doubleSpinBox_2->setValue(0.0);
    ui->doubleSpinBox_3->setValue(2.0);
    ui->label_5->setVisible(false);//A
    ui->label_6->setVisible(false);//B
    ui->label_7->setVisible(false);//C
    ui->label_8->setVisible(false);//D
    ui->label_9->setVisible(false);//E
    ui->label_11->setVisible(false);//F
    ui->label_15->setVisible(false);//G
}


void MainWindow::on_radioButton_58_clicked()
{
FL.inData.numberFunction = 9;
}

void MainWindow::on_radioButton_59_clicked()
{
FL.inData.numberFunction = 10;
}

void MainWindow::on_radioButton_60_clicked()
{
FL.inData.numberFunction = 11;
}

void MainWindow::on_radioButton_61_clicked()
{
FL.inData.numberFunction = 12;
}

void MainWindow::on_radioButton_62_clicked()
{
FL.inData.numberFunction = 13;
}

void MainWindow::on_radioButton_63_clicked()
{
FL.inData.numberFunction = 14;
}

void MainWindow::on_radioButton_64_clicked()
{
FL.inData.numberFunction = 15;
}

//кнопка "сгенерировать данные"
void MainWindow::on_pushButton_3_clicked()
{
    //очищаем старые данные, если они есть
    FL.clear();

    FL.inData.dimExp = FL.cluster.N = ui->spinBox->value();//количество экспериментов
    FL.inData.level_noise = ui->spinBox_6->value();//Процентная доля помехи от мощности сигнала

    //количество факторов
    if (ui->radioButton->isChecked()) FL.inData.dimFactor = 1;
    if (ui->radioButton_2->isChecked()) FL.inData.dimFactor = 2;
    if (ui->radioButton_7->isChecked()) FL.inData.dimFactor = 3;

    short nm;
    if(ui->radioButton->isChecked()) nm = 1;
    else nm = 2;
    if(ui->spinBox->value() < nm || ui->spinBox->value()< nm)//если кол-во наблюдений меньше кол-ва факторов
    {
        QMessageBox lbl;
        lbl.setWindowTitle("Attention");
        lbl.setText(trUtf8("Ошибка! Количество наблюдений меньше количества факторов!"));
        lbl.setStandardButtons(QMessageBox::Ok);
        lbl.exec();
    }

    //уровни варьирования
    FL.inData.granic[0][0] = ui->doubleSpinBox_2->value();
    FL.inData.granic[0][1] = ui->doubleSpinBox_3->value();
    // Если границы заданы неверно
   /* if((FL.inData.granic[0][1] < FL.inData.granic[0][0]) || (FL.inData.granic[1][1] < FL.inData.granic[1][0]))
    {
        QMessageBox lb;
        lb.setWindowTitle("Attention");
        lb.setText(trUtf8("Неверно введённые границы"));
        lb.setStandardButtons(QMessageBox::Ok);
        lb.exec();
        return;
    }*/

    if (ui->radioButton_10->isChecked())
        FL.inData.numberFunction = 1;
    if (ui->radioButton_11->isChecked())
        FL.inData.numberFunction = 2;
    if (ui->radioButton_5->isChecked()) FL.inData.numberFunction = 3;
    if (ui->radioButton_6->isChecked()) FL.inData.numberFunction = 4;
    if (ui->radioButton_54->isChecked()) FL.inData.numberFunction = 5;
    if (ui->radioButton_55->isChecked()) FL.inData.numberFunction = 6;
    if (ui->radioButton_56->isChecked()) FL.inData.numberFunction = 7;
    if (ui->radioButton_57->isChecked()) FL.inData.numberFunction = 8;
    if (ui->radioButton_58->isChecked()) FL.inData.numberFunction = 9;
    if (ui->radioButton_59->isChecked()) FL.inData.numberFunction = 10;
    if (ui->radioButton_60->isChecked()) FL.inData.numberFunction = 11;
    if (ui->radioButton_61->isChecked()) FL.inData.numberFunction = 12;
    if (ui->radioButton_62->isChecked()) FL.inData.numberFunction = 13;
    if (ui->radioButton_63->isChecked()) FL.inData.numberFunction = 14;
    if (ui->radioButton_64->isChecked()) FL.inData.numberFunction = 15;


    if (ui->checkBox->isChecked()) srand(time(NULL));//обновлять выборку
    else srand(0xEE11DD22U);

FL.inData.numberRules = 1;

    FL.initialization_one();//инициализация данных	(этап моделирования данных)


}

//кнопка "Расчет" без кластеров
void MainWindow::on_pushButton_clicked()
{
    FL.flag_about_clustering = 0;//0-no cluster, 1-with cluster

    //вид функций принадлежности
    if (ui->radioButton_12->isChecked()) FL.inData.choiceFunction = 1;//треугольники
    if (ui->radioButton_13->isChecked()) FL.inData.choiceFunction = 2;//трапеции

    FL.number_mu = ui->spinBox_7->value();//количество функций принадлежности


FL.inData.flag_about_free = 0;

    if(ui->radioButton->isChecked())//если 1 фактор
    {
        if (ui->radioButton_12->isChecked())//если треугольники
        {
            if(FL.inData.numberFunction == 1 || FL.inData.numberFunction == 3 || FL.inData.numberFunction == 4 ||
                    FL.inData.numberFunction == 5 || FL.inData.numberFunction == 6)//если промежуток -1 1
            {
                FL.inData.granic[0][0] = -1;
                FL.inData.granic[0][1] = 1;

            switch(FL.number_mu)
            {
                case 2:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne1.txt");
                    FL.input_grid1 >> FL.n_x;
                break;
                case 3:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne2.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 4:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne3.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 5:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne4.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 6:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne5.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 7:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne6.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 8:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne7.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 9:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne8.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 10:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTriOne9.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
            }
            }
            else
                if (FL.inData.numberFunction == 2)//если промежуток -1 3
                {
                    FL.inData.granic[0][0] = -1;
                    FL.inData.granic[0][1] = 3;

                switch(FL.number_mu)
                {
                    case 2:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne1.txt");
                        FL.input_grid1 >> FL.n_x;
                    break;
                    case 3:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne2.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 4:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne3.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 5:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne4.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 6:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne5.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 7:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne6.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 8:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne7.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 9:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne8.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 10:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTriOne9.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                }
                }
                else
                    if (FL.inData.numberFunction == 6 || FL.inData.numberFunction == 8)//если промежуток 0 2
                    {
                        FL.inData.granic[0][0] = 0;
                        FL.inData.granic[0][1] = 2;

                    switch(FL.number_mu)
                    {
                        case 2:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne1.txt");
                            FL.input_grid1 >> FL.n_x;
                        break;
                        case 3:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne2.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 4:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne3.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 5:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne4.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 6:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne5.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 7:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne6.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 8:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne7.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 9:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne8.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 10:
                            FL.input_grid1.open("setka_0_2/setkaFactorTriOne9.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                    }
                    }
                    else
                    {
                        FL.inData.granic[0][0] = 0.5;
                        FL.inData.granic[0][1] = 4;

                        switch(FL.number_mu)
                        {
                            case 2:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne1.txt");
                                FL.input_grid1 >> FL.n_x;
                            break;
                            case 3:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne2.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 4:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne3.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 5:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne4.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 6:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne5.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 7:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne6.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 8:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne7.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 9:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne8.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 10:
                                FL.input_grid1.open("setka_05_4/setkaFactorTriOne9.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                        }
                    }

        }
        else//если трапеции
        {


            if(FL.inData.numberFunction == 1 || FL.inData.numberFunction == 3 || FL.inData.numberFunction == 4 ||
                    FL.inData.numberFunction == 5 || FL.inData.numberFunction == 6)//если промежуток -1 1
            {
                FL.inData.granic[0][0] = -1;
                FL.inData.granic[0][1] = 1;

            switch(FL.number_mu)
            {
                case 2:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne1.txt");
                    FL.input_grid1 >> FL.n_x;
                break;
                case 3:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne2.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 4:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne3.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 5:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne4.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 6:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne5.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 7:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne6.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 8:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne7.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 9:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne8.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
                case 10:
                    FL.input_grid1.open("setka_-1_1/setkaFactorTraOne9.txt");
                    FL.input_grid1 >> FL.n_x;
                    break;
              }
            }
            else
                if (FL.inData.numberFunction == 2)//если промежуток -1 3
                {
                    FL.inData.granic[0][0] = -1;
                    FL.inData.granic[0][1] = 3;

                switch(FL.number_mu)
                {
                    case 2:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne1.txt");
                        FL.input_grid1 >> FL.n_x;
                    break;
                    case 3:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne2.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 4:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne3.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 5:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne4.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 6:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne5.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 7:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne6.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 8:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne7.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 9:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne8.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                    case 10:
                        FL.input_grid1.open("setka_-1_3/setkaFactorTraOne9.txt");
                        FL.input_grid1 >> FL.n_x;
                        break;
                }
                }
                else
                    if (FL.inData.numberFunction == 6 || FL.inData.numberFunction == 8)//если промежуток 0 2
                    {
                        FL.inData.granic[0][0] = 0;
                        FL.inData.granic[0][1] = 2;

                    switch(FL.number_mu)
                    {
                        case 2:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne1.txt");
                            FL.input_grid1 >> FL.n_x;
                        break;
                        case 3:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne2.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 4:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne3.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 5:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne4.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 6:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne5.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 7:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne6.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 8:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne7.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 9:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne8.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                        case 10:
                            FL.input_grid1.open("setka_0_2/setkaFactorTraOne9.txt");
                            FL.input_grid1 >> FL.n_x;
                            break;
                    }
                    }
                    else//если промежуток 0.5 4
                    {
                        FL.inData.granic[0][0] = 0.4;
                        FL.inData.granic[0][1] = 5;

                        switch(FL.number_mu)
                        {
                            case 2:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne1.txt");
                                FL.input_grid1 >> FL.n_x;
                            break;
                            case 3:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne2.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 4:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne3.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 5:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne4.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 6:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne5.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 7:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne6.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 8:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne7.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 9:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne8.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                            case 10:
                                FL.input_grid1.open("setka_05_4/setkaFactorTraOne9.txt");
                                FL.input_grid1 >> FL.n_x;
                                break;
                        }
                    }
         }
    }

    if(FL.inData.dimFactor == 1)
    {
        FL.buildGridFactorOne();//построение сетки для одномерного случая
        if (FL.inData.choiceFunction == 1) FL.constructMatrixX_one_tri();//построение матрицы наблюдений в случае треугольников
        if (FL.inData.choiceFunction == 2) FL.constructMatrixX_one_tra();//построение матрицы наблюдений в случае трапеций
        FL.Tetta();//нахождение параметров модели по МНК
        FL.RSS_one();//вычисление остатков
    }

if(ui->radioButton_2->isChecked())//если 2 фактор
   {
    if (FL.inData.dimFactor==2)//если модель двумерная
    {
            FL.initialization_two();//инициализация данных	(этап моделирования данных)
            FL.buildGridFactorTwo();//построение сетки для двумерного случая
            if (FL.inData.choiceFunction == 1) FL.constructMatrixX_two_tri();//построение матрицы наблюдений в случае треугольников
            FL.Tetta();//нахождение параметров модели по МНК
            FL.RSS_two();//вычисление остатков
    }
}
    FL.coefDetermination();//критерий качества - коэффициент детерминации (косинус векторов у_ист, у_оценен)
    FL.averageError_no_cluster();

    ui->label_61->setText(QString::number(FL.R));
    ui->label_60->setText(QString::number(FL.delta));
    ui->label_63->setText(QString::number(FL.mse));


    for (int i=0; i<FL.inData.m_loc; i++)
    {
        delete [] FL.X_t[i];
        //delete [] FL.mult_xt_x[i];
        //delete [] FL.xInvers[i];
        //delete [] FL.mult_obr_xt[i];
    }
    delete [] FL.X_t;
    //delete [] FL.mult_xt_x;
   // delete [] FL.xInvers;
    //delete [] FL.mult_obr_xt;

    //delete [] FL.tetta;
    //for (int i=0; i<FL.inData.dimExp; i++)//валится ((
    //		delete [] FL.Xmat[i];

    //delete [] FL.Xmat;
    if (FL.inData.dimFactor==1)
    {
        for (int i=0; i<FL.sector_n; i++)
            delete [] FL.mu_numbers_x[i];
        delete [] FL.D;
    }
    else
    {
        for (int i=0; i<FL.rect_n; i++) {
            delete [] FL.mu_numbers_x[i];
            delete [] FL.mu_numbers_y[i]; }

        delete [] FL.C;
    }
    delete [] FL.mu_numbers_x;
    if (FL.inData.dimFactor==2) delete [] FL.mu_numbers_y;

}

//кнопка "отрисовка"
void MainWindow::on_pushButton_2_clicked()
{
    double x_min=2E20, x_max=2E-20, y_min=2E20, y_max=2E-20;

        if(ui->radioButton->isChecked())//если 1 фактор в модели
        {
            ui->widget->masX1.resize(FL.inData.dimExp);
            ui->widget->masY.resize(FL.inData.dimExp);
            ui->widget->masY1.resize(FL.inData.dimExp);
            for (int i = 0; i< FL.inData.dimExp; i++)
            {
                if (FL.x_var[i][0]<x_min) x_min = FL.x_var[i][0];
                if (FL.x_var[i][0]>x_max) x_max = FL.x_var[i][0];
                if (FL.y_oc[i]<y_min) y_min = FL.y_oc[i];
                if (FL.y_oc[i]>y_max) y_max = FL.y_oc[i];
               // if (FL.y_main[i]<y_min) y_min = FL.y_main[i];
                //if (FL.y_main[i]>y_max) y_max = FL.y_main[i];

                ui->widget->masX1[i] = FL.x_var[i][0];
                ui->widget->masY[i] = FL.y_oc[i];
                ui->widget->masY1[i] = FL.y_main[i];

            }
            ui->widget->NumGraph = 1;//количество графиков = 1
        }

        if(ui->radioButton_2->isChecked())//если два фактора в модели
            {
                ui->widget->masX1.resize(FL.inData.dimExp);
                ui->widget->masX2.resize(FL.inData.dimExp);
                ui->widget->masY.resize(FL.inData.dimExp);
                ui->widget->masY1.resize(FL.inData.dimExp);

                for (int i = 0; i< FL.inData.dimExp; i++)
                {
                    if (FL.x_var[i][0]<x_min) x_min = FL.x_var[i][0];
                    if (FL.x_var[i][0]>x_max) x_max = FL.x_var[i][0];
                    if (FL.y_oc[i]<y_min) y_min = FL.y_oc[i];//оцененный вектор отклика
                    if (FL.y_oc[i]>y_max) y_max = FL.y_oc[i];
                    //if (FL.y[i]<y_min) y_min = FL.y[i];//истинная зависимость отклика от наблюдений
                    //if (FL.y[i]>y_max) y_max = FL.y[i];

                    if (FL.x_var[i][1]<x_min) x_min = FL.x_var[i][1];
                    if (FL.x_var[i][1]>x_max) x_max = FL.x_var[i][1];
                    if (FL.y_oc[i]<y_min) y_min = FL.y_oc[i];//оцененный вектор отклика
                    if (FL.y_oc[i]>y_max) y_max = FL.y_oc[i];
                    //if (FL.y[i]<y_min) y_min = FL.y[i];//истинная зависимость отклика от наблюдений
                    //if (FL.y[i]>y_max) y_max = FL.y[i];

                    ui->widget->masX1[i] = FL.x_two[i][0];
                    ui->widget->masX2[i] = FL.x_two[i][1];
                    ui->widget->masY[i] = FL.y_oc[i];//оцененный вектор отклика
                    ui->widget->masY1[i] = FL.y_main[i];//истинная зависимость отклика от наблюдений
                }
                ui->widget->NumGraph = 2;//количество графиков = 2
            }

        ui->widget->min_x = x_min;
        ui->widget->min_y = y_min;
        ui->widget->max_x = x_max;
        ui->widget->max_y = y_max;

        ui->widget->precond();
        ui->widget->updateGL();
}

//окошко "о программе"
void MainWindow::on_action_2_triggered()
{
    QMessageBox lbl;
    lbl.setWindowTitle("About programm");
    lbl.setText(trUtf8("Программа реализует метод построения регрессии на основе нечетких правил."));
    lbl.setStandardButtons(QMessageBox::Ok);
    lbl.exec();
}

//очистка окошка с графиком
void Cscene2dn::clear()
{
    masX1.clear();
    masX2.clear();
    masY.clear();
    masY1.clear();
}

//кнопка "использование кластеризации"
void MainWindow::on_pushButton_7_clicked()
{
    ui->tabWidget->setCurrentIndex(1);// Установим активной вкладку с кластеризацией
}

//кнопка "выполнить кластеризацию"
void MainWindow::on_pushButton_4_clicked()
{
    QTime time_start, time_stop;

    FL.cluster.Nc = ui->spinBox_10->value();//количество кластеров
    FL.cluster.N = FL.inData.dimExp;
    FL.cluster.w = ui->spinBox_11->value();
    FL.cluster.eps = ui->doubleSpinBox->value();

    FL.flag_about_clustering = 1;//0-no cluster, 1-with cluster

    FL.initialization_one_multi();//построение матрицы наблюдений

    //----------------------------------отсюда кластеризация данных
    FL.cluster.newData();//выделение памяти для кластеризации

    for (int i=0; i<FL.inData.dimExp; i++)
        for (int j=0; j<FL.inData.dimFactor; j++)
            FL.cluster.x[i][j] = FL.x_var[i][j];

    FL.cluster.begin_U();//начальная генерация матрицы U
    FL.cluster.summ = 0.0;

    for(int k=0;k<FL.cluster.Nc;k++)//по каждому кластеру
        for ( int j=0; j<FL.inData.dimFactor+1; j++ )
                FL.tetta_matrix[j][k] = 0.0;

    //метод FCM
    if (ui->radioButton_3->isChecked())
    {
        time_start = QTime::currentTime();

        //проверяем условие выхода
                do
                {
                    FL.cluster.centerCluster();							//подсчет центров кластеров - шаг 3
                    FL.cluster.distanse_fcm();							//подсчет расстояния - шаг 4
                    FL.cluster.Mu_Calc_fcm();							//подсчет новой матрицы U - шаг 5

                    FL.cluster.summ = 0.0;
                    for (int i=0; i<FL.cluster.N; i++)
                        for (int k = 0; k<FL.cluster.Nc; k++)			//считаем норму разницы матриц U для выхода!!! - шаг 6
                            if (i == k)
                                FL.cluster.summ += sqrt(pow(FL.cluster.mu_next[i][k] - FL.cluster.mu_prev[i][k],(double)2));
                    cout << "summ = " << FL.cluster.summ << endl;

                    for (int i=0; i<FL.cluster.N; i++)
                        for (int k = 0; k<FL.cluster.Nc; k++)
                            FL.cluster.mu_prev[i][k] = FL.cluster.mu_next[i][k];//перезапись значений матрицы U
                    }
                    while (FL.cluster.summ > FL.cluster.eps);
                    //-------------------------------до сюда кластеризация данных

        time_stop = QTime::currentTime();
    }

//метод густафсона-кесселя
    if (ui->radioButton_4->isChecked())
    {
        time_start = QTime::currentTime();
        //проверяем условие выхода
                do
                {
                    FL.cluster.centerCluster();							//подсчет центров кластеров - шаг 3
                        FL.cluster.matrix_covariance_GK();					//вычислить матрицу ковариации - шаг 4
                        FL.cluster.matrix_scale_GK();							//подсчет расстояния - шаг 5
                        FL.cluster.distance_GK();
                        FL.cluster.Mu_Calc_GK();							//подсчет новой матрицы U - шаг 6


                        FL.cluster.summ = 0.0;
                        for (int k = 0; k<FL.cluster.Nc; k++)
                            for (int i=0; i<FL.cluster.N; i++)				//считаем норму разницы матриц U для выхода!!! - шаг 6
                                    FL.cluster.summ += fabs(FL.cluster.mu_next[i][k] - FL.cluster.mu_prev[i][k]);

                        for (int i=0; i<FL.cluster.N; i++)
                            for (int k = 0; k<FL.cluster.Nc; k++)
                                FL.cluster.mu_prev[i][k] = FL.cluster.mu_next[i][k];//перезапись значений матрицы U

                        /*cout << "muuu_current" << endl;
                        for(int i = 0; i < FL.inData.dimExp; i++)
                        {
                            for(int j = 0; j < FL.cluster.Nc; j++)
                                printf("%.16lf   ", FL.cluster.mu_prev[i][j]);
                            cout << endl;
                        }*/

                        printf("\ndelta = %.16lf\n", FL.cluster.summ);
                }
                    while (FL.cluster.summ > FL.cluster.eps);
                    //-------------------------------до сюда кластеризация данных

        time_stop = QTime::currentTime();
    }

    double time = (double)time_start.msecsTo(time_stop) / 1000.0;
            ui->lineEdit->setText(QString::number(time));
}

//кнопка "расчет" при кластеризации
void MainWindow::on_pushButton_9_clicked()
{
    //далее
        for(int k=0;k<FL.cluster.Nc;k++)//по каждому кластеру
        {
            //получение оценок
            FL.Tetta_cluster(k);

            //запись оценок по каждому кластеру в общую матрицу
            for ( int j=0; j<FL.inData.dimFactor+1; j++ )
                FL.tetta_matrix[j][k] = FL.tetta[j];

            ofstream out_tet("tetta.txt");
                out_tet << "tetta" << endl;
                for(int i = 0; i < FL.inData.dimFactor+1; i++){
                    for ( int j=0; j<FL.cluster.Nc; j++ )
                        out_tet << FL.tetta_matrix[i][j] << "  \t";
                out_tet << endl;}
                out_tet.close();

        }

        for(int k=0;k<FL.cluster.Nc;k++)//по каждому кластеру
            for(int i=0; i<FL.inData.dimExp; i++)
                FL.y_matrix[i][k] = 0.0;

        for(int k=0;k<FL.cluster.Nc;k++)//по каждому кластеру
        {
            //значение отклика - матрица
            for(int i=0; i<FL.inData.dimExp; i++)
                for(int j=0; j<FL.inData.dimFactor+1; j++)
                    FL.y_matrix[i][k] += FL.Xmat[i][j] * FL.tetta_matrix[j][k];
        }

        ofstream out_y_matrix("y_matrix.txt");
        out_y_matrix << "y_matrix" << endl;
        for(int i = 0; i < FL.inData.dimExp; i++){
            for ( int j=0; j<FL.cluster.Nc; j++ )
                out_y_matrix << FL.y_matrix[i][j] << "  \t";
        out_y_matrix << endl;}
        out_y_matrix.close();


        FL.Deffazification();

        FL.averageError_with_cluster();
        FL.coefDetermination();

        ui->label_55->setText(QString::number(FL.R));
        ui->label_54->setText(QString::number(FL.delta_fin));
        ui->label_58->setText(QString::number(FL.mse));


            /*for (int i=0; i<FL.inData.dimFactor+1; i++)
            {
                delete [] FL.X_t[i];
                delete [] FL.mult_xt_w[i];
                delete [] FL.Invers[i];
                delete [] FL.mult_xt_w_x[i];
                delete [] FL.mult_invers_xt[i];
                delete [] FL.mult_all_on_W[i];
            }

            delete [] FL.X_t;
            delete [] FL.mult_xt_w;
            delete [] FL.Invers;
            delete [] FL.mult_xt_w_x;
            delete [] FL.mult_invers_xt;
            delete [] FL.mult_all_on_W;
            delete [] FL.rezMult_onY;
            delete [] FL.tetta;
            delete [] FL.y_oc;*/
}

//кнопка "отрисовка" для кластеризации
void MainWindow::on_pushButton_8_clicked()
{
    ui->widget_2->NumberGraph = 1;
    ui->widget_2->updateGL();

    double x_min=2E20, x_max=2E-20, y_min=2E20, y_min_oc=2E20, y_max=2E-20, y_max_oc=2E-20;

        ui->widget_2->masX1.resize(FL.inData.dimExp);
        ui->widget_2->masY.resize(FL.inData.dimExp);
        ui->widget_2->masY1.resize(FL.inData.dimExp);
        int j = FL.inData.dimFactor-1;
        for (int i = 0; i< FL.inData.dimExp; i++)
        {
            if (FL.x_var[i][j]<x_min) x_min = FL.x_var[i][j];
            if (FL.x_var[i][j]>x_max) x_max = FL.x_var[i][j];
            if (FL.y_oc[i]<y_min_oc) y_min_oc = FL.y_oc[i];
            if (FL.y_oc[i]>y_max_oc) y_max_oc = FL.y_oc[i];
            if (FL.y_main[i]<y_min) y_min = FL.y_main[i];
            if (FL.y_main[i]>y_max) y_max = FL.y_main[i];

            ui->widget_2->masX1[i] = FL.x_var[i][j];
            ui->widget_2->masY[i] = FL.y_oc[i];
            ui->widget_2->masY1[i] = FL.y_main[i];

        }
        ui->widget_2->NumGraph = 1;//количество графиков = 1

    for(int i = 0; i< FL.inData.dimExp; i++)
    {
        printf("%f ", ui->widget_2->masY[i]);
        printf("%f ", ui->widget_2->masY1[i]);
    }

    ui->widget_2->min_x = x_min;
        printf("%f min_x", ui->widget_2->min_x);
    ui->widget_2->min_y = y_min;
        printf("%f min_y",  ui->widget_2->min_y);
    ui->widget_2->min_y_oc = y_min_oc;
        printf("%f min_y_oc", ui->widget_2->min_y_oc);
    ui->widget_2->max_x = x_max;
        printf("%f max_x", ui->widget_2->max_x);
    ui->widget_2->max_y = y_max;
        printf("%f max_y", ui->widget_2->max_y);
    ui->widget_2->max_y_oc = y_max_oc;
        printf("%f max_y_oc", ui->widget_2->max_y_oc);

    ui->widget_2->precond();
    ui->widget_2->updateGL();
}

//очистка всех данных
void MainWindow::on_pushButton_5_clicked()
{
    method();
    ui->label_61->setVisible(false);
    ui->label_60->setVisible(false);
    ui->label_63->setVisible(false);
    ui->widget->setVisible(false);
}

//очистка всех данных (окно с кластеризацией)
void MainWindow::on_pushButton_6_clicked()
{
    method();
    ui->label_55->setVisible(false);
    ui->label_54->setVisible(false);
    ui->label_58->setVisible(false);
    ui->widget_2->setVisible(false);
}



