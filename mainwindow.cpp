#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), brightness(70), isgameoflife(false), timer(new QTimer(this)), timer2(new QTimer(this)) { // Combined initialization
    connect(timer, &QTimer::timeout, this, &MainWindow::updateMatrix); // For other animations
    connect(timer2, &QTimer::timeout, this, &MainWindow::updateGrid);


    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create IP address entry
    layout->addWidget(new QLabel("IP Address:"));
    ipAddressEntry = new QLineEdit("192.168.232.214");
    layout->addWidget(ipAddressEntry);

    // Create port entry
    layout->addWidget(new QLabel("UDP Port:"));
    portEntry = new QLineEdit("6868");
    layout->addWidget(portEntry);

    // Create connect button
    QPushButton *connectButton = new QPushButton("Connect");
    layout->addWidget(connectButton);

    connect(connectButton, &QPushButton::clicked, this, &MainWindow::connectButtonClicked); // Correctly connected

    // Create brightness slider
    layout->addWidget(new QLabel("Brightness:"));
    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(0, 100);
    brightnessSlider->setValue(brightness);
    layout->addWidget(brightnessSlider);

    connect(brightnessSlider, &QSlider::valueChanged, this, &MainWindow::brightnessChanged);

    // Create clear button
    QPushButton *clearButton = new QPushButton("Clear");
    layout->addWidget(clearButton);

    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearMatrix);

    QPushButton *randomAnimationButton = new QPushButton("Random Animation");
    layout->addWidget(randomAnimationButton);
    connect(randomAnimationButton, &QPushButton::clicked, this, &MainWindow::animateRandom);

    QPushButton *startStopButton = new QPushButton("Start Game of Life");
        layout->addWidget(startStopButton);
    connect(startStopButton, &QPushButton::clicked, [this, startStopButton]() {
        if (isgameoflife) {
            // Stop the Game of Life
            timer2->stop();
            isgameoflife = false;
            startStopButton->setText("Start Game of Life");
            qDebug() << "Game of Life stopped.";
        } else {
            // Start the Game of Life
            gameoflife();
            timer2->start(500); // Start with a default interval for Game of Life (500 ms)
            isgameoflife = true;
            startStopButton->setText("Stop Game of Life");
            qDebug() << "Game of Life started.";
        }
    });



    QCheckBox *shiftLeftCheckbox = new QCheckBox("Shift Left");
    layout->addWidget(shiftLeftCheckbox);

    QCheckBox *shiftRightCheckbox = new QCheckBox("Shift Right");
    layout->addWidget(shiftRightCheckbox);

    // Create shifting time input
    layout->addWidget(new QLabel("Shifting Time (ms):"));
    QLineEdit *shiftingTimeInput = new QLineEdit("500");
    layout->addWidget(shiftingTimeInput);



    // Create Start/Stop Animation button
    QPushButton *startAnimationButton = new QPushButton("Start Animation");
    layout->addWidget(startAnimationButton);

    connect(startAnimationButton, &QPushButton::clicked, [this, startAnimationButton, shiftLeftCheckbox, shiftRightCheckbox, shiftingTimeInput]() {
        if (isAnimationRunning) {
            // Stop the animation
            if (timer) {
                timer->stop();
                delete timer;
                timer = nullptr;
            }
            isAnimationRunning = false;
            startAnimationButton->setText("Start Animation"); // Change the button text back to 'Start Animation'

            qDebug() << "Animation stopped. Current pattern is fixed.";

        } else {
            // Start the animation
            bool ok;
            int interval = shiftingTimeInput->text().toInt(&ok);

            if (ok && interval > 0) { // Ensure valid input
                startAnimation(shiftLeftCheckbox->isChecked(), shiftRightCheckbox->isChecked(), interval);
                isAnimationRunning = true;
                startAnimationButton->setText("Stop Animation"); // Change the button text to 'Stop Animation'
            } else {
                qDebug() << "Invalid shifting time entered!";
            }
        }
    });




    // Create matrix buttons
    QGridLayout *gridLayout = new QGridLayout();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            int buttonId = i * 8 + j;
            buttons[i][j] = new QPushButton();
            buttons[i][j]->setStyleSheet("background-color: black;");
            buttons[i][j]->setFixedSize(50, 50);
            gridLayout->addWidget(buttons[i][j], i, j);

            connect(buttons[i][j], &QPushButton::clicked, [this, buttonId]() {
                buttonCallback(buttonId);
            });

            buttonStates[buttonId] = false; // Initialize all buttons to false (off)
        }
    }

    layout->addLayout(gridLayout);
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    if (timer) {
        delete timer;
    }
}

void MainWindow::buttonCallback(int buttonId) {
    buttonStates[buttonId] = !buttonStates[buttonId]; // Toggle button state

    if (buttonStates[buttonId]) {
        buttons[buttonId / 8][buttonId % 8]->setStyleSheet("background-color: red;");
    } else {
        buttons[buttonId / 8][buttonId % 8]->setStyleSheet("background-color: black;");
    }

    updateMatrix();
}

void MainWindow::clearMatrix() {
    for (int i = 0; i < 64; ++i) {
        buttonStates[i] = false;
        buttons[i / 8][i % 8]->setStyleSheet("background-color: black;");
    }

    updateMatrix();
}

void MainWindow::updateMatrix() {
    QByteArray matrixData = generateMatrixData();
    sendMatrixData(matrixData);
}

void MainWindow::brightnessChanged(int value) {
    brightness = value;
    updateMatrix();
}

void MainWindow::startAnimation(bool shiftLeftEnabled, bool shiftRightEnabled, int interval) {
    // if (timer) {
    //     timer->stop(); // Stop any existing timer if it's running
    //     delete timer; // Clean up old timer
    //     for(int i=0;i<64;i++){
    //        buttonStates[i]=newbuttonStates[i];
    //     }
    // }

     timer = new QTimer(this);

    if (shiftLeftEnabled && !shiftRightEnabled) {
        connect(timer, &QTimer::timeout, this, &MainWindow::shiftLeft);
    } else if (shiftRightEnabled && !shiftLeftEnabled) {
        connect(timer, &QTimer::timeout, this, &MainWindow::shiftRight);
    }

    timer->start(interval); // Start the timer with user-defined interval
}




void MainWindow::animateRandom(){
    int animationId = rand() % 4;
    switch(animationId){
    case 0:
        animation1(); break;
    case 1:
        animation2(); break;
    case 2:
        animation3(); break;
    case 3:
        animation4(); break;
    }

    updateMatrix();
}


const int SIZE=8;

int MainWindow::countNeighbors(const QVector<QVector<int>>& grid, int x, int y) {
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Skip the cell itself
            int newX = (x + dx + SIZE) % SIZE; // Wrap around
            int newY = (y + dy + SIZE) % SIZE; // Wrap around
            count += grid[newX][newY];
        }
    }
    return count;
}

void MainWindow::updateGrid() {
    QVector<QVector<int>> newGrid(SIZE, QVector<int>(SIZE, 0)); // Create a new grid for the next state

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int liveNeighbors = countNeighbors(grid, i, j);

            if (grid[i][j] == 1) { // Cell is alive
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[i][j] = 0; // Cell dies
                } else {
                    newGrid[i][j] = 1; // Cell stays alive
                }
            } else { // Cell is dead
                if (liveNeighbors == 3) {
                    newGrid[i][j] = 1; // Cell becomes alive
                }
            }
        }
    }

    grid = newGrid;

    clearMatrix();

    // Update LED matrix based on current state of the grid
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == 1) {
                buttonCallback(i * SIZE + j);
            }
        }
    }
}

void MainWindow::gameoflife() {
    grid.resize(SIZE);
    for (auto &row : grid) {
        row.resize(SIZE);
        std::fill(row.begin(), row.end(), 0); // Initialize grid to 0
    }

// start patterns selection
    int patternId = rand() % 4;
    switch(patternId){
    case 0:
        grid[1][2] = 1;
        grid[2][3] = 1;
        grid[3][1] = 1;
        grid[3][2] = 1;
        grid[3][3] = 1;
        break;
    case 1:
        grid[1][1] = 1;
        grid[1][2] = 1;
        grid[2][1] = 1;
        grid[2][2] = 1;
        break;
    case 2:
        grid[2][1] = 1;
        grid[2][2] = 1;
        grid[2][3] = 1;
        break;
    case 3:
        srand(time(0)); // Seed random number generator

        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                grid[i][j] = rand() % 2; // Randomly assign 0 or 1 to each cell
            }
        }
        break;
    }







    if (!isgameoflife) {
        timer2->start(500);
        isgameoflife = true;
        qDebug() << "Game of Life initialized and started.";
    }
}


void MainWindow::animation1(){
    int heart[64]= { 0,0,0,0,0,0,0,0,
                     0,1,1,0,1,1,0,0,
                     1,0,0,1,0,0,1,0,
                     1,0,0,0,0,0,1,0,
                     0,1,0,0,0,1,0,0,
                     0,0,1,0,1,0,0,0,
                     0,0,0,1,0,0,0,0,
                     0,0,0,0,0,0,0,0
    };

    clearMatrix();
    for(int i=0;i<64;i++){
        buttonStates[i]=heart[i];
        setMatrix(i);

    }
}

void MainWindow::animation2() {
    clearMatrix();
   // buttonStates[2] = true;
    buttonCallback(2);
   // buttonStates[3] = true;
    buttonCallback(3);

}

void MainWindow::animation3() {
    clearMatrix();
    //buttonStates[4] = true;
    buttonCallback(4);

}
void MainWindow::animation4() {
    // Example: Set a pattern for animation 4
    clearMatrix();
    for(int i=0;i<64;i++){
   // buttonStates[i] = true;
    buttonCallback(i);
    }
}

void MainWindow::shiftLeft() {
    // Save the first column to wrap around
    bool firstColumn[8];
    for (int i = 0; i < 8; ++i) {
        firstColumn[i] = buttonStates[i * 8];  // Save the first column (first bit of each row)
    }

    // Shift each column to the left (moving the second column to the first, third to second, etc.)
    for (int j = 0; j < 7; ++j) {
        for (int i = 0; i < 8; ++i) {
            buttonStates[i * 8 + j] = buttonStates[i * 8 + j + 1];  // Shift column values
            setMatrix(i*8+j);

         }
    }

    // Move the saved first column to the last (eighth) column
    for (int i = 0; i < 8; ++i) {
        buttonStates[i * 8 + 7] = firstColumn[i];
        setMatrix(i*8+7);

    }

    updateMatrix();  // Update the LED matrix display
}



void MainWindow::shiftRight() {
    // Save the last column to wrap around
    bool lastColumn[8];
    for (int i = 0; i < 8; ++i) {
        lastColumn[i] = buttonStates[i * 8 + 7];  // Save the last column (last bit of each row)
    }

    // Shift each column to the right (moving the seventh column to the eighth, sixth to seventh, etc.)
    for (int j = 7; j > 0; --j) {
        for (int i = 0; i < 8; ++i) {
            buttonStates[i * 8 + j] = buttonStates[i * 8 + j - 1];  // Shift column values
            setMatrix(i * 8 + j);
        }
    }

    // Move the saved last column to the first column
    for (int i = 0; i < 8; ++i) {
        buttonStates[i * 8] = lastColumn[i];
        setMatrix(i*8);
    }

    updateMatrix();  // Update the LED matrix display
}

void MainWindow::setMatrix(int value){
    if (buttonStates[value]) {
        buttons[value / 8][value % 8]->setStyleSheet("background-color: red;");
    } else {
        buttons[value / 8][value % 8]->setStyleSheet("background-color: black;");
    }
}

void MainWindow::connectButtonClicked() {
    updateMatrix(); // Send initial matrix data on connect
}

void MainWindow::sendMatrixData(QByteArray data) {
    QString ipAddress = ipAddressEntry->text();
    quint16 port = static_cast<quint16>(portEntry->text().toInt());

    udpSocket.writeDatagram(data, QHostAddress(ipAddress), port);
    qDebug() << "Sent packet:" << data.toHex(); // Print sent data in hex format
}

QByteArray MainWindow::generateMatrixData() {
    QByteArray matrixData;

    for (int i = 0; i < 8; ++i) {
        uint8_t rowData = 0x00;
        for (int j = 0; j < 8; ++j) {
            if (buttonStates[i * 8 + j]) {
                rowData |= (1 << j); // Set bit if button is pressed
            }
        }
        matrixData.append(rowData); // Append row data to matrix data
    }

    uint8_t brightnessBits = qBound(0, brightness / 4, 63); // Scale brightness to range [0-63]
    matrixData.append(brightnessBits << 2); // Append scaled brightness

    return matrixData;
}
