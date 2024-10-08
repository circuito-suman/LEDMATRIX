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
#include <QVector> // Include for QVector
#include <unistd.h>
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
        explicit MainWindow(QWidget *parent = nullptr); // Constructor declaration
    ~MainWindow();

private slots:
    void buttonCallback(int buttonId);
    void clearMatrix();
    void updateMatrix();
    void brightnessChanged(int value);
    void connectButtonClicked();
    void animateRandom();
    void gameoflife();
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
    bool isgameoflife= false;
    QTimer *timer = nullptr;  // Timer for animation
    QTimer *timer2 = nullptr;  // Timer for animation
    QVector<QVector<int>> grid;
    int countNeighbors(const QVector<QVector<int>>& grid, int x, int y) ;

 void updateGrid();
};

#endif // MAINWINDOW_H
