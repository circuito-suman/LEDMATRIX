#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QUdpSocket>
#include <QLineEdit>
#include <QSlider>
#include <QCheckBox>
#include <QTimer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttonCallback(int buttonId);
    void clearMatrix();
    void updateMatrix();
    void brightnessChanged(int value);
    void connectButtonClicked();
    void animateRandom();
    void animation1();
    void animation2();
    void animation3();
    void animation4();
    void startAnimation(bool shiftLeftEnabled, bool shiftRightEnabled, int interval);
    void shiftLeft();
    void shiftRight();
    void setMatrix(int value);


private:
    void sendMatrixData(QByteArray data);
    QByteArray generateMatrixData();

    QPushButton *buttons[8][8];
    QLineEdit *ipAddressEntry;
    QLineEdit *portEntry;
    QSlider *brightnessSlider;
    QUdpSocket udpSocket;

    bool buttonStates[64]; // Store the state of each button
    int brightness; // Store brightness level
    int newbuttonStates[64];

    bool isAnimationRunning = false; // Track if the animation is running
    QTimer *timer = nullptr;  // Timer for animation
};

#endif // MAINWINDOW_H
