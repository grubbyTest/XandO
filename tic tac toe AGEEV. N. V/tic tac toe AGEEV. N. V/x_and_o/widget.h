#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <Qt>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "toset.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void game_mod();

    void on_pB_X_clicked();

    void on_pB_0_clicked();

    void on_pB_play_clicked();

    void onGameAreaButtonClicked();

    void onGameAreaButtonClicked5();

    void onComputerSlot();

    void onComputerSlot5();

    void on_pB_about_clicked();

    void on_pB_set_clicked();

    void on_pB_MUZ_clicked();

private:
    Ui::Widget *ui;
    void setInterfaceStyle();
    void changeButtonsStatus(int n);
    void changeButtonsStatus5(int n);

    void configTabWidget();
    void addFonts();
    void changeButtonStyle(int row, int column, QString style);
    void setGameAreaBtnStyle();
    void configGameAreaButtons();

    void changeButtonStyle5(int row, int column, QString style);
    void setGameAreaBtnStyle5();
    void configGameAreaButtons5();
    void setSoundEffect();
    void startMusic();

    void start();
    void lockPlayer();
    void computerInGame();
    void computerInGame5();
    void chekGameStop();
    void checkFinal();
    void endGame();
    QString finalEffectButton();

    char gameArea3[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    char gameArea5[5][5] = {
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-'}
    };
    char player = 'X';               //X or 0
    int progress = 0;
    int wins = 0;
    int defs = 0;
    bool gameStart = false;
    bool playerLocked = true;
    bool playMusic = true;
    QTimer *timer;
    QTimer *timer5;
    QTimer *timerForStartMusic;
    bool stop;
    char winner;
    QSoundEffect effect;
    QSoundEffect soundEffectEnemy;
    QSoundEffect soundEffectSet;
    QSoundEffect soundEffectBtns;
    QSoundEffect soundEffectBtnsToLost;
    QSoundEffect soundWin;
    QSoundEffect soundLost;
    QMediaPlayer *fonMusic;
    QAudioOutput *audioOutput;

    toSet *windowSet;
};
#endif // WIDGET_H
