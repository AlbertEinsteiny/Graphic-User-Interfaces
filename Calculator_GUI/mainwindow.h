#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_pushbutton_decimal_released();
    void unary_operation_pressed();
    void on_pushbutton_clear_released();
    void on_binary_operation_pressed();
    void on_pushbutton_equal_released();

};

#endif // MAINWINDOW_H
