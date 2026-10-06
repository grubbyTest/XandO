#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "stylehelper.h"
#include <QStyleOption>
#include <QFontDatabase>
#include <QGridLayout>
#include <time.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui -> pB_3, SIGNAL(clicked()), this, SLOT(game_mod()));
    connect(ui -> pB_5, SIGNAL(clicked()), this, SLOT(game_mod()));

    addFonts();
    configTabWidget();
    setInterfaceStyle();
    configGameAreaButtons();
    configGameAreaButtons5();
    setSoundEffect();
    startMusic();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::onComputerSlot);
    timer5 = new QTimer(this);
    connect(timer5, &QTimer::timeout, this, &Widget::onComputerSlot5);
    timerForStartMusic = new QTimer(this);
    //timerForStartMusic -> start(3000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style() -> drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void Widget::setInterfaceStyle()
{
    this -> setStyleSheet(StyleHelper::setMainWidgetStyle());
    ui -> pB_about -> setStyleSheet(StyleHelper::getStartButtonStyle());
    ui -> pB_play -> setStyleSheet(StyleHelper::getStartButtonStyle());
    ui -> pB_X -> setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
    ui -> pB_0 -> setStyleSheet(StyleHelper::getRightButtonStyle());
    ui -> pB_3 -> setStyleSheet(StyleHelper::getLeftModeButtonActiveStyle());
    ui -> pB_5 -> setStyleSheet(StyleHelper::getRightModeButtonStyle());
    ui -> tabWidget -> setStyleSheet(StyleHelper::getTabWidgetStyle());
    ui -> game_3 -> setStyleSheet(StyleHelper::getTabStyle());
    ui -> game_5 -> setStyleSheet(StyleHelper::getTabStyle());
    ui -> about -> setStyleSheet(StyleHelper::getTabStyle());
    ui -> pB_set -> setStyleSheet(StyleHelper::getStartButtonStyle());
    ui -> pB_MUZ -> setStyleSheet(StyleHelper::getStartButtonActiveStyle());


    ui -> msg_lbl -> setText("");
    ui -> msg_lbl -> setStyleSheet(StyleHelper::getEmptyMsgStyle());

    setGameAreaBtnStyle();
    setGameAreaBtnStyle5();
}

void Widget::changeButtonsStatus(int n)
{
    if(n == 0){
        ui -> pB_X -> setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
        ui -> pB_0 -> setStyleSheet(StyleHelper::getRightButtonStyle());
    }else{
        ui -> pB_X -> setStyleSheet(StyleHelper::getLeftButtonStyle());
        ui -> pB_0 -> setStyleSheet(StyleHelper::getRightButtonActiveStyle());
    }
}

void Widget::configTabWidget()
{
    ui -> tabWidget -> tabBar() -> hide();
    ui -> tabWidget -> setCurrentIndex(0);
}

void Widget::addFonts()
{
    QFontDatabase::addApplicationFont(":/resources/fonts/Roboto-Medium.ttf");                        //Roboto-Medium
    int id = QFontDatabase::addApplicationFont(":/resources/fonts/Roboto-MediumItalic.ttf");         //Roboto-MediumItalic
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug() << family;
}

void Widget::changeButtonStyle(int row, int column, QString style)
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui -> game_3 -> layout());
    QPushButton *btn = qobject_cast <QPushButton*>(grid -> itemAtPosition(row, column) -> widget());
    btn -> setStyleSheet(style);
}

void Widget::setGameAreaBtnStyle()
{
    QString style = StyleHelper::getBlankButtonStyle();
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
            changeButtonStyle(row, column, style);
}

void Widget::configGameAreaButtons()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui -> game_3 -> layout());
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++){
            QPushButton *btn = qobject_cast <QPushButton*>(grid -> itemAtPosition(row, column) -> widget());
            btn -> setProperty("row", row);
            btn -> setProperty("column", column);
            connect(btn, &QPushButton::clicked, this, &Widget::onGameAreaButtonClicked);
        }
}
void Widget::setSoundEffect()
{
    effect.setSource(QUrl::fromLocalFile(":/resources/sounds/sound.wav"));
    effect.setLoopCount(QSoundEffect::Loop(1));
    effect.setVolume(0.25f);

    soundEffectEnemy.setSource(QUrl::fromLocalFile(":/resources/sounds/enemy.wav"));
    soundEffectEnemy.setLoopCount(QSoundEffect::Loop(1));
    soundEffectEnemy.setVolume(0.25f);

    soundEffectSet.setSource(QUrl::fromLocalFile(":/resources/sounds/setSound.wav"));
    soundEffectSet.setLoopCount(QSoundEffect::Loop(1));
    soundEffectSet.setVolume(0.25f);

    soundEffectBtns.setSource(QUrl::fromLocalFile(":/resources/sounds/play.wav"));
    soundEffectBtns.setLoopCount(QSoundEffect::Loop(1));
    soundEffectBtns.setVolume(0.25f);

    soundEffectBtnsToLost.setSource(QUrl::fromLocalFile(":/resources/sounds/btnLost.wav"));
    soundEffectBtnsToLost.setLoopCount(QSoundEffect::Loop(1));
    soundEffectBtnsToLost.setVolume(0.25f);

    soundWin.setSource(QUrl::fromLocalFile(":/resources/sounds/soundWin.wav"));
    soundWin.setLoopCount(QSoundEffect::Loop(1));
    soundWin.setVolume(0.25f);

    soundLost.setSource(QUrl::fromLocalFile(":/resources/sounds/soundLose.wav"));
    soundLost.setLoopCount(QSoundEffect::Loop(1));
    soundLost.setVolume(0.25f);

//    fonMusic.setSource(QUrl::fromLocalFile(":/resources/sounds/fonMus.wav"));
//    fonMusic.setLoopCount(QSoundEffect::Loop());
//    fonMusic.setVolume(0.25f);
    fonMusic = new QMediaPlayer;
    audioOutput = new QAudioOutput;
    fonMusic -> setAudioOutput(audioOutput);
    // ...
    fonMusic -> setSource(QUrl::fromLocalFile("qrc:/resources/sounds/fonMus.mp3"));
    audioOutput -> setVolume(70);
    fonMusic -> setLoops(QMediaPlayer::Infinite);

    //fonMusic -> play();
}

void Widget::startMusic()
{
    //timerForStartMusic -> stop();
    if (playMusic){
        fonMusic -> play();
    }else{
        fonMusic -> stop();
    }
}
//======================================================================Для зоны 5х5===============================================
void Widget::changeButtonStyle5(int row, int column, QString style)
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui -> game_5 -> layout());
    QPushButton *btn = qobject_cast <QPushButton*>(grid -> itemAtPosition(row, column) -> widget());
    btn -> setStyleSheet(style);
}

void Widget::setGameAreaBtnStyle5()
{
    QString style = StyleHelper::getBlankButtonStyle();
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 5; column++)
            changeButtonStyle5(row, column, style);
}

void Widget::configGameAreaButtons5()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui -> game_5 -> layout());
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 5; column++){
            QPushButton *btn = qobject_cast <QPushButton*>(grid -> itemAtPosition(row, column) -> widget());
            btn -> setProperty("row", row);
            btn -> setProperty("column", column);
            connect(btn, &QPushButton::clicked, this, &Widget::onGameAreaButtonClicked5);
        }
}


//====================================================================================================================================
void Widget::start()
{
    setGameAreaBtnStyle();
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
            gameArea3[row][column] = '-';
    setGameAreaBtnStyle();
    for (int row = 0; row < 5; row++)
        for (int column = 0; column < 5; column++)
            gameArea5[row][column] = '-';
    setGameAreaBtnStyle5();
    progress = 0;
    gameStart = true;
    stop = false;

    if (ui -> tabWidget -> currentIndex() == 0){
        if (player != 'X')
            computerInGame();
    }else if (ui -> tabWidget -> currentIndex() == 1){
        if (player != 'X')
            computerInGame5();
    }

}

void Widget::lockPlayer()
{
    if(player == 'X'){
        playerLocked = false;
    }else{
        playerLocked = true;
    }

}

void Widget::computerInGame()
{
    if (!stop){
        srand(time(0));
        int index = rand() % 5;
        QStringList list = {"Секундочку...", "Щас..", "Погоди-ка.", "Так так так...", "Так, я хожу!"};
        ui -> msg_lbl -> setText(list.at(index));
        timer -> start(2000);
        //onComputerSlot5();
    }
}

void Widget::chekGameStop()
{
    winner = '-';
    char symbol[2] = {'X', '0'};
    if (ui -> tabWidget -> currentIndex() == 0){
        for (int i = 0; i < 2; i++){
            for (int row = 0; row < 3; row++){
                if (gameArea3[row][0] == symbol[i] and gameArea3[row][1] == symbol[i] and gameArea3[row][2] == symbol[i]){
                    stop = true;
                    winner = symbol[i];

                    changeButtonStyle(row, 0 , finalEffectButton());
                    changeButtonStyle(row, 1 , finalEffectButton());
                    changeButtonStyle(row, 2 , finalEffectButton());

                    return;
                }
            }
            for (int col = 0; col < 3; col++){
                if (gameArea3[0][col] == symbol[i] and gameArea3[1][col] == symbol[i] and gameArea3[2][col] == symbol[i]){
                    stop = true;
                    winner = symbol[i];

                    changeButtonStyle(0, col , finalEffectButton());
                    changeButtonStyle(1, col , finalEffectButton());
                    changeButtonStyle(2, col , finalEffectButton());

                    return;
                }
            }
            if (gameArea3[0][0] == symbol[i] and gameArea3[1][1] == symbol[i] and gameArea3[2][2] == symbol[i]){
                stop = true;
                winner = symbol[i];

                changeButtonStyle(0, 0 , finalEffectButton());
                changeButtonStyle(1, 1 , finalEffectButton());
                changeButtonStyle(2, 2 , finalEffectButton());

                return;
            }
            if (gameArea3[0][2] == symbol[i] and gameArea3[1][1] == symbol[i] and gameArea3[2][0] == symbol[i]){
                stop = true;
                winner = symbol[i];

                changeButtonStyle(0, 2 , finalEffectButton());
                changeButtonStyle(1, 1 , finalEffectButton());
                changeButtonStyle(2, 0 , finalEffectButton());

                return;
            }
        }
        progress++;
        if (progress == 9){
            stop = true;
        }
    }/*else if(ui -> tabWidget -> currentIndex() == 1){
        for (int i = 0; i < 2; i++){
            for (int row = 0; row < 5; row++){
                if (gameArea5[row][0] == symbol[i] and gameArea5[row][1] == symbol[i] and gameArea5[row][2] == symbol[i] and gameArea5[row][3] == symbol[i] and gameArea5[row][4] == symbol[i]){
                    stop = true;
                    winner = symbol[i];

                    changeButtonStyle5(row, 0 , finalEffectButton());
                    changeButtonStyle5(row, 1 , finalEffectButton());
                    changeButtonStyle5(row, 2 , finalEffectButton());
                    changeButtonStyle5(row, 3 , finalEffectButton());
                    changeButtonStyle5(row, 4 , finalEffectButton());

                    return;
                }
            }
            for (int col = 0; col < 5; col++){
                if (gameArea5[0][col] == symbol[i] and gameArea5[1][col] == symbol[i] and gameArea5[2][col] == symbol[i] and gameArea5[3][col] == symbol[i] and gameArea5[4][col] == symbol[i]){
                    stop = true;
                    winner = symbol[i];

                    changeButtonStyle5(0, col , finalEffectButton());
                    changeButtonStyle5(1, col , finalEffectButton());
                    changeButtonStyle5(2, col , finalEffectButton());
                    changeButtonStyle5(3, col , finalEffectButton());
                    changeButtonStyle5(4, col , finalEffectButton());

                    return;
                }
            }
            if (gameArea5[0][0] == symbol[i] and gameArea5[1][1] == symbol[i] and gameArea5[2][2] == symbol[i] and gameArea5[3][3] == symbol[i] and gameArea5[4][4] == symbol[i]){
                stop = true;
                winner = symbol[i];

                changeButtonStyle5(0, 0 , finalEffectButton());
                changeButtonStyle5(1, 1 , finalEffectButton());
                changeButtonStyle5(2, 2 , finalEffectButton());
                changeButtonStyle5(3, 3 , finalEffectButton());
                changeButtonStyle5(4, 4 , finalEffectButton());

                return;
            }
            if (gameArea5[0][4] == symbol[i] and gameArea5[1][3] == symbol[i] and gameArea5[2][2] == symbol[i] and gameArea5[3][1] == symbol[i] and gameArea5[4][0] == symbol[i]){
                stop = true;
                winner = symbol[i];

                changeButtonStyle5(0, 4 , finalEffectButton());
                changeButtonStyle5(1, 3 , finalEffectButton());
                changeButtonStyle5(2, 2 , finalEffectButton());
                changeButtonStyle5(3, 1 , finalEffectButton());
                changeButtonStyle5(4, 0 , finalEffectButton());

                return;
            }
        }
        progress++;
        if (progress == 25){
            stop = true;
        }
    }
*/

}

void Widget::checkFinal()
{
    winner = '-';
    int k;
    char symbol[2] = {'X', '0'};
    char indicator = '-';
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 3; j++){
            if (gameArea5[i][j] == symbol[0] or gameArea5[i][j] == symbol[1]){
                indicator = gameArea5[i][j];
                    if (gameArea5[i][j+1] == indicator and gameArea5[i][j+2] == indicator){
                        stop = true;
                        winner = indicator;
                        for (k = 0; k < 3; k++){
                            changeButtonStyle5(i, j + k , finalEffectButton());
                        }
                        return;
                    }
            }
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (gameArea5[i][j] == symbol[0] or gameArea5[i][j] == symbol[1]){
                indicator = gameArea5[i][j];
                if (gameArea5[i + 1][j] == indicator and gameArea5[i + 2][j] == indicator){
                    stop = true;
                    winner = indicator;
                    for (k = 0; k < 3; k++){
                        changeButtonStyle5(i + k, j, finalEffectButton());
                    }
                    return;
                }
            }
        }
    }

    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 4; j++){
            if (gameArea5[i][j] == symbol[0] or gameArea5[i][j] == symbol[1]){
                indicator = gameArea5[i][j];
                if (gameArea5[i - 1][j - 1] == indicator and gameArea5[i + 1][j + 1] == indicator){
                    stop = true;
                    winner = indicator;
                    for (k = -1; k < 2; k++){
                        changeButtonStyle5(i + k, j + k , finalEffectButton());
                    }
                    return;
                }
                if (gameArea5[i - 1][j + 1] == indicator and gameArea5[i + 1][j - 1] == indicator){
                    stop = true;
                    winner = indicator;
                    for (k = -1; k < 2; k++){
                        changeButtonStyle5(i + k, j - k , finalEffectButton());
                    }
                    return;
            }
        }
    }
    }
    progress++;
    if (progress == 25){
        stop = true;
    }
}

void Widget::endGame()
{

    if (stop){
        if (winner == player){
            soundWin.play();
            wins++;
            ui -> lblWin -> setText(QString::number(wins));
            ui -> msg_lbl -> setText("Победа!!!");
            ui -> msg_lbl -> setStyleSheet(StyleHelper::getVinMsgStyle());
        }else if (winner == '-'){
            ui -> msg_lbl -> setText("Ничья.");
        }else{
            soundLost.play();
            defs++;
            ui -> lblLose -> setText(QString::number(defs));
            ui -> msg_lbl -> setText("Поражение.");
            ui -> msg_lbl -> setStyleSheet(StyleHelper::getLoseMsgStyle());
        }


    ui -> pB_play -> setText("Играть");
    ui -> pB_play -> setStyleSheet(StyleHelper::getStartButtonStyle());
    ui -> pB_X -> setDisabled(false);
    ui -> pB_0 -> setDisabled(false);
    ui -> pB_3 -> setDisabled(false);
    ui -> pB_5 -> setDisabled(false);
    ui -> pB_about -> setDisabled(false);
    gameStart = false;
    }

}

QString Widget::finalEffectButton()
{
    QString style;
    if (winner == player){
        if (player == 'X')
            style = StyleHelper::getCrossVinStyle();
        else
            style = StyleHelper::getZeroVinStyle();
    }else{
        if (player == 'X'){
            style = StyleHelper::getZeroLoseStyle();
        }else{
            style = StyleHelper::getCrossLoseStyle();
        }
    }
    return style;
}

void Widget::onComputerSlot()
{
    if (stop)
        return;
    char comp;
    QString style;
    if (player == 'X'){
        comp = '0';
        style = StyleHelper::getZeroNormalStyle();
    }else {
        comp = 'X';
        style = StyleHelper::getCrossNormalStyle();
    }
    timer -> stop();
    soundEffectEnemy.play();
//    for (int row = 0; row < 3; row++)
//        for (int column = 0; column < 3; column++){
//            if (gameArea3[row][column] == '-'){
//                gameArea3[row][column] = comp;
//                changeButtonStyle(row, column, style);
//            }
//        }
    while(true){
        int row = rand() % 3;
        int column = rand() % 3;
        if (gameArea3[row][column] == '-'){
            gameArea3[row][column] = comp;
            changeButtonStyle(row, column, style);
            ui -> msg_lbl -> setText("Твой ход!");
            chekGameStop();
            endGame();

            playerLocked = false;
            break;
        }
    }
}


void Widget::on_pB_X_clicked()
{
    soundEffectSet.play();
    changeButtonsStatus(0);
    player = 'X';
}


void Widget::on_pB_0_clicked()
{
    soundEffectSet.play();
    changeButtonsStatus(1);
    player = '0';
}


void Widget::on_pB_play_clicked()
{
    //ui -> tabWidget -> setCurrentIndex(0);
    if (gameStart){
        soundEffectBtnsToLost.play();
        playerLocked = true;
        defs++;
        ui -> lblLose -> setText(QString::number(defs));
        ui -> pB_play -> setText("Играть");
        ui -> pB_play -> setStyleSheet(StyleHelper::getStartButtonStyle());
        ui -> pB_X -> setDisabled(false);
        ui -> pB_0 -> setDisabled(false);
        ui -> pB_3 -> setDisabled(false);
        ui -> pB_5 -> setDisabled(false);
        ui -> pB_about -> setDisabled(false);
        gameStart = false;
        ui -> msg_lbl -> setText("Поражение...");
        ui -> msg_lbl -> setStyleSheet(StyleHelper::getLoseMsgStyle());
    }else{
        soundEffectBtns.play();
        ui -> msg_lbl -> setText("Игра началась!");
        ui -> msg_lbl -> setStyleSheet(StyleHelper::getNormalMsgStyle());
        start();
        lockPlayer();
        ui -> pB_play -> setText("Сдаться...");
        ui -> pB_play -> setStyleSheet(StyleHelper::getStartButtonActiveStyle());  //====================================!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        ui -> pB_X -> setDisabled(true);
        ui -> pB_0 -> setDisabled(true);
        ui -> pB_3 -> setDisabled(true);
        ui -> pB_5 -> setDisabled(true);
        ui -> pB_about -> setDisabled(true);
    }
}

void Widget::onGameAreaButtonClicked()
{
    effect.play();
    if (stop) playerLocked = true;
    if (!playerLocked){
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        int row = btn -> property("row").toInt();
        int column = btn -> property("column").toInt();
        qDebug() << row << ":" << column;
        if (gameArea3[row][column] == '-'){
            QString style;
            if (player == 'X'){
                style = StyleHelper::getCrossNormalStyle();
                gameArea3[row][column] = 'X';
            }else{
                style = StyleHelper::getZeroNormalStyle();
                gameArea3[row][column] = '0';
            }
            changeButtonStyle(row, column, style);
            playerLocked = true;
            chekGameStop();
            endGame();
            computerInGame();
        }else return;
    }
}
//========================================================slots for 5 area============================================
void Widget::onGameAreaButtonClicked5()
{
    effect.play();
    if (stop) playerLocked = true;
    if (!playerLocked){
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        int row = btn -> property("row").toInt();
        int column = btn -> property("column").toInt();
        qDebug() << row << ":" << column;
        if (gameArea5[row][column] == '-'){
            QString style;
            if (player == 'X'){
                style = StyleHelper::getCrossNormalStyle();
                gameArea5[row][column] = 'X';
            }else{
                style = StyleHelper::getZeroNormalStyle();
                gameArea5[row][column] = '0';
            }
            changeButtonStyle5(row, column, style);
            playerLocked = true;
            //chekGameStop();
            checkFinal();
            endGame();
            computerInGame5();
        }else return;
    }
}

void Widget::computerInGame5()
{
    if (!stop){
        srand(time(0));
        int index = rand() % 5;
        QStringList list = {"Секундочку...", "Щас..", "Погоди-ка.", "Так так так...", "Так, я хожу!"};
        ui -> msg_lbl -> setText(list.at(index));
        timer5 -> start(2000);
        //onComputerSlot5();
    }
}

void Widget::onComputerSlot5()
{
    if (stop)
        return;
    char comp;
    QString style;
    if (player == 'X'){
        comp = '0';
        style = StyleHelper::getZeroNormalStyle();
    }else {
        comp = 'X';
        style = StyleHelper::getCrossNormalStyle();
    }
    timer5 -> stop();
    soundEffectEnemy.play();
//    for (int row = 0; row < 3; row++)
//        for (int column = 0; column < 3; column++){
//            if (gameArea3[row][column] == '-'){
//                gameArea3[row][column] = comp;
//                changeButtonStyle(row, column, style);
//            }
//        }
    while(true){
        int row = rand() % 5;
        int column = rand() % 5;
        if (gameArea5[row][column] == '-'){
            gameArea5[row][column] = comp;
            changeButtonStyle5(row, column, style);
            ui -> msg_lbl -> setText("Твой ход!");
            //chekGameStop();
            playerLocked = false;
            checkFinal();
            endGame();

            break;
        }
    }
}

void Widget::on_pB_about_clicked()
{
    soundEffectBtns.play();
    if (ui -> tabWidget -> currentIndex() != 2){
        ui -> tabWidget -> setCurrentIndex(2);
        ui -> pB_about -> setText("Назад");
        ui -> pB_about -> setStyleSheet(StyleHelper::getStartButtonActiveStyle());
        ui -> pB_X -> setDisabled(true);
        ui -> pB_0 -> setDisabled(true);
        ui -> pB_3 -> setDisabled(true);
        ui -> pB_5 -> setDisabled(true);
        ui -> pB_play -> setDisabled(true);
    }else{
        ui -> tabWidget -> setCurrentIndex(0);
        ui -> pB_about -> setText("Об игре");
        ui -> pB_about -> setStyleSheet(StyleHelper::getStartButtonStyle());
        ui -> pB_X -> setDisabled(false);
        ui -> pB_0 -> setDisabled(false);
        ui -> pB_3 -> setDisabled(false);
        ui -> pB_5 -> setDisabled(false);
        ui -> pB_play -> setDisabled(false);
        changeButtonsStatus5(0);
    }
    ;
}
//=======================================================buttons of mode=====================================
void Widget::game_mod()
{
    soundEffectSet.play();
    QPushButton *button = (QPushButton *)sender();
    if(button -> text() == "3x3"){
        ui -> tabWidget -> setCurrentIndex(0);
        changeButtonsStatus5(0);
    }
    else if(button -> text() == "5x5"){
        ui -> tabWidget -> setCurrentIndex(1);
        changeButtonsStatus5(1);
    }
}

void Widget::changeButtonsStatus5(int n)
{
    if(n == 0){
        ui -> pB_3 -> setStyleSheet(StyleHelper::getLeftModeButtonActiveStyle());
        ui -> pB_5 -> setStyleSheet(StyleHelper::getRightModeButtonStyle());
    }else{
        ui -> pB_3 -> setStyleSheet(StyleHelper::getLeftModeButtonStyle());
        ui -> pB_5 -> setStyleSheet(StyleHelper::getRightModeButtonActiveStyle());
    }
}




void Widget::on_pB_set_clicked()
{
    soundEffectSet.play();
    //hide();
    windowSet = new toSet;
    windowSet->setModal(true);
    windowSet->show();
}


void Widget::on_pB_MUZ_clicked()
{
    if(!playMusic){
        playMusic = true;
        ui -> pB_MUZ -> setStyleSheet(StyleHelper::getStartButtonActiveStyle());
    }else{
        playMusic = false;
        ui -> pB_MUZ -> setStyleSheet(StyleHelper::getStartButtonStyle());
    }
    startMusic();
}

