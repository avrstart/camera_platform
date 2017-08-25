#include "mainwindow.h"
#include "ui_mainwindow.h"

bool soket_opened = false;

JoyReader       *joy;
QUdpSocket      *socket;
Robo_proto      *robo_proto;
QTimer          *joy_timer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//set camera position
void MainWindow::camera_rotate(Robo_proto::directions directions)
{
    int port_n = ui->spinBox->value();

    if(soket_opened == true){
        QByteArray Data;
        Data.resize(7);
        robo_proto->move_camera(directions, (uint8_t *)Data.data());
        socket->writeDatagram(Data, QHostAddress::Broadcast, port_n);
    }
}

//connect to ip addr
void MainWindow::on_pushButton_6_clicked()
{
    if(soket_opened == false) {
        ui->pushButton_6->setText("Connected");
        ui->pushButton_6->setEnabled(false);

        socket = new QUdpSocket(this);
        socket->bind(QHostAddress::Broadcast, 2215);
        soket_opened = true;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    camera_rotate(robo_proto->move_left);
}

void MainWindow::on_pushButton_4_clicked()
{
    camera_rotate(robo_proto->move_down);
}

void MainWindow::on_pushButton_3_clicked()
{
    camera_rotate(robo_proto->move_right);
}

void MainWindow::on_pushButton_clicked()
{
    camera_rotate(robo_proto->move_up);
}


void MainWindow::updateTime()
{
    uint16_t tjoy_direction;
    tjoy_direction = joy->get_buttons();

    switch (tjoy_direction) {
        case JoyReader::joy_down:
            camera_rotate(robo_proto->move_down);
            break;
        case JoyReader::joy_right:
            camera_rotate(robo_proto->move_right);
            break;
        case JoyReader::joy_up:
            camera_rotate(robo_proto->move_up);
            break;
        case JoyReader::joy_left:
            camera_rotate(robo_proto->move_left);
            break;

        default:
            break;
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    //open_joy
    QString js_path = ui->lineEdit->text();
    QByteArray ba = js_path.toLatin1();
    char *tmp = ba.data();

    if(joy->joy_init(tmp) == true) {
        ui->pushButton_5->setText("Connected");
        ui->pushButton_5->setEnabled(false);

        joy_timer = new QTimer();
        joy_timer->setInterval(100);
        connect(joy_timer, SIGNAL(timeout()), this, SLOT(updateTime()));
        joy_timer->start();
        ui->label->setText("Gamepad connected");
    }
    else{
        ui->label->setText("No gamepad found");
    }
}
