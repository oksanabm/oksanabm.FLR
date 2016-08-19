#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "ourClass.h"
#include "cscene2dn.h"
#include <QWidget>

using namespace std;
static method FL;

namespace Ui { class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_10_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_54_clicked();

    void on_radioButton_55_clicked();

    void on_radioButton_56_clicked();

    void on_radioButton_57_clicked();

    void on_radioButton_58_clicked();

    void on_radioButton_59_clicked();

    void on_radioButton_60_clicked();

    void on_radioButton_61_clicked();

    void on_radioButton_62_clicked();

    void on_radioButton_63_clicked();

    void on_radioButton_64_clicked();


    void on_pushButton_2_clicked();

    void on_action_2_triggered();

                void on_pushButton_7_clicked();

                void on_pushButton_3_clicked();

                void on_pushButton_4_clicked();

                void on_pushButton_9_clicked();

                void on_pushButton_8_clicked();

                void on_pushButton_5_clicked();

                void on_pushButton_6_clicked();

private:
    void systemRules();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
