#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <qstring>

double firstNum;
bool secondnumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   connect(ui->pushbutton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
   connect(ui->pushbutton_unary,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
   connect(ui->pushbutton_divide,SIGNAL(released()),this,SLOT(on_binary_operation_pressed()));
   connect(ui->pushbutton_multiply,SIGNAL(released()),this,SLOT(on_binary_operation_pressed()));
   connect(ui->pushbutton_minus,SIGNAL(released()),this,SLOT(on_binary_operation_pressed()));
   connect(ui->pushbutton_add,SIGNAL(released()),this,SLOT(on_binary_operation_pressed()));
    connect(ui->seven,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->eight,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->nine,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->four,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->five,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->six,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->one,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->two,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->three,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->zero,SIGNAL(released()),this,SLOT(digit_pressed()));

    ui->pushbutton_add->setCheckable(true);
    ui->pushbutton_minus->setCheckable(true);
    ui->pushbutton_multiply->setCheckable(true);
    ui->pushbutton_divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
  QPushButton * button = (QPushButton*)sender();

  double main_label_number;
  QString newLabel;

  if ((ui->pushbutton_add->isChecked() || ui->pushbutton_minus->isChecked() ||
     ui->pushbutton_multiply->isChecked() || ui->pushbutton_divide->isChecked()) &&
          !secondnumber)
  {
      main_label_number = button->text().toDouble();
      secondnumber = true;
      newLabel = QString::number(main_label_number,'g', 15);
  }

  else
  {
      if (ui->main_label->text().contains('.') && button->text() =="0")
      {
          newLabel = ui->main_label->text() + button->text();
      }
      else
      {
          main_label_number = (ui->main_label->text() + button->text()).toDouble();
          newLabel = QString::number(main_label_number,'g', 15);
      }
  }
  ui->main_label->setText(newLabel);
}

void MainWindow::on_pushbutton_decimal_released()
{
   ui->main_label->setText(ui->main_label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
     double main_label_number;
     QString newLabel;

    if (button->text() == "+/-")
    {
        main_label_number = ui->main_label->text().toDouble();
        main_label_number = main_label_number * -1;
        newLabel = QString::number(main_label_number,'g', 15);
        ui->main_label->setText(newLabel);
    }

    if (button->text() == "%")
    {
        main_label_number = ui->main_label->text().toDouble();
        main_label_number = main_label_number * 0.01;
        newLabel = QString::number(main_label_number,'g', 15);
        ui->main_label->setText(newLabel);
    }
}

void MainWindow::on_binary_operation_pressed()
{
     QPushButton * button = (QPushButton*)sender();

     // get the first number
     firstNum = ui->main_label->text().toDouble();
     button->setChecked(true);
}

void MainWindow::on_pushbutton_equal_released()
{
    double main_label_number;
    double secondNum;
     QString newLabel;
    secondNum = ui->main_label->text().toDouble();

     if(ui->pushbutton_add->isChecked())
     {
          main_label_number = firstNum + secondNum;
          newLabel = QString::number(main_label_number,'g', 15);
          ui->main_label->setText(newLabel);
          ui->pushbutton_add->setChecked(false);
     }

     else if(ui->pushbutton_minus->isChecked())
     {
         main_label_number = firstNum - secondNum;
         newLabel = QString::number(main_label_number,'g', 15);
         ui->main_label->setText(newLabel);
         ui->pushbutton_minus->setChecked(false);
     }

     else if(ui->pushbutton_multiply->isChecked())
     {
         main_label_number = firstNum * secondNum;
         newLabel = QString::number(main_label_number,'g', 15);
         ui->main_label->setText(newLabel);
         ui->pushbutton_multiply->setChecked(false);
     }

     else if(ui->pushbutton_divide->isChecked())
     {
         main_label_number = firstNum / secondNum;
         newLabel = QString::number(main_label_number,'g', 15);
         ui->main_label->setText(newLabel);
         ui->pushbutton_divide->setChecked(false);
     }

     secondnumber = false;
}


void MainWindow::on_pushbutton_clear_released()
{

    ui->pushbutton_add->setChecked(false);
    ui->pushbutton_minus->setChecked(false);
    ui->pushbutton_multiply->setChecked(false);
    ui->pushbutton_divide->setChecked(false);
    secondnumber = false;
    ui->main_label->setText("0");
}
