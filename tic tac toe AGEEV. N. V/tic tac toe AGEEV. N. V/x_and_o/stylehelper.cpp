#include "stylehelper.h"


QString StyleHelper::getStartButtonStyle()
{
    return "QPushButton{"
           "   color: #fff;"
           "    background: none;"
           "    border: 2px solid #3a3a3a;"
           "    border-radius: 15px;"
           //"    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(148, 72, 156, 255), stop:1 rgba(249, 156, 255, 255));"
           "    background-color: rgba(138, 138, 138, 100);"
           "    font-family: 'Roboto Medium';"
           "    font-size: 16px;"
           "    }"
           "QPushButton::hover{"
           //"    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(249, 156, 255, 255));"
           "    background-color: rgba(48, 48, 48, 100);"
           "    }"
           "QPushButton::pressed{"
           //"    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(148, 72, 156, 255), stop:1 rgba(249, 156, 255, 255));"
           "    background-color: rgba(138, 138, 138, 100);"
           "    }";
}

QString StyleHelper::getStartButtonActiveStyle()
{
    return "QPushButton{"
           "   color: #fff;"
           "    background: none;"
           "    border: 3px solid #7e0000;"
           "    border-radius: 15px;"
           //"    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(148, 72, 156, 255), stop:1 rgba(249, 156, 255, 255));"
           "    background-color: rgba(43, 14, 0, 100);"
           "    font-family: 'Roboto Medium';"
           "    font-size: 16px;"
           "    }"
           "QPushButton::hover{"
           //"    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(249, 156, 255, 255));"
           "    background-color: rgba(48, 48, 48, 100);"
           "    }"
           "QPushButton::pressed{"
           //"    background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(148, 72, 156, 255), stop:1 rgba(249, 156, 255, 255));"
           "    background-color: rgba(138, 138, 138, 100);"
           "    }";
}

QString StyleHelper::setMainWidgetStyle()
{
    return "QWidget{"
           //"    background-image: url(:/resources/images/bg.png);"
           "    background-image: url(:/resources/images/bcg.jpg);"
           "    }";
}

QString StyleHelper::getLeftButtonStyle()
{
    return "QPushButton{"
           //"    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0 rgba(47, 47, 47, 255), stop:1 rgba(255, 255, 255, 255));"
           "    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0.314607 rgba(58, 58, 58, 255), stop:1 rgba(108, 108, 108, 255));"
           "    background-image: url(:/resources/images/cross_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-top-left-radius: 5px;"
           "    border-bottom-left-radius: 5px;"
           "    }";
}

QString StyleHelper::getRightButtonStyle()
{
    return "QPushButton{"
           //"    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0 rgba(47, 47, 47, 255), stop:1 rgba(255, 255, 255, 255));"
           "    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0.314607 rgba(58, 58, 58, 255), stop:1 rgba(108, 108, 108, 255));"
           "    background-image: url(:/resources/images/zero_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-left: none;"
           "    border-top-right-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "    }";
}

QString StyleHelper::getLeftButtonActiveStyle()
{
    return "QPushButton{"
           "    background-color: #2d313b;"
           "    background-image: url(:/resources/images/cross_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-top-left-radius: 5px;"
           "    border-bottom-left-radius: 5px;"
           "    }";
}

QString StyleHelper::getRightButtonActiveStyle()
{
    return "QPushButton{"
           "    background-color: #2d313b;"
           "    background-image: url(:/resources/images/zero_small.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    border: 1px solid #333;"
           "    border-left: none;"
           "    border-top-right-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "    }";
}

QString StyleHelper::getTabWidgetStyle()
{
    return "QTabWidget{"
            "   border: none;"
            "   }"
            "QTabWidget::pane{"
            "   border: 1px solid #333;"
            "   border-radius: 3px;"
            "   }";
}

QString StyleHelper::getTabStyle()
{
    return "QWidget#game_3{"
           "   background: rgba(29, 15, 0, 180);"
           "   }"
           "QWidget#game_5{"
           "   background: rgba(29, 15, 0, 180);"
           "   }"
           "QWidget#about{"
           "   background: rgba(29, 15, 0, 180);"
           "    }";
}


QString StyleHelper::getLeftModeButtonStyle()
{
    return "QPushButton{"
           //"    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0 rgba(47, 47, 47, 255), stop:1 rgba(255, 255, 255, 255));"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0.314607 rgba(58, 58, 58, 255), stop:1 rgba(108, 108, 108, 255));"
           "    border: 1px solid #333;"
           "    border-top-left-radius: 5px;"
           "    border-bottom-left-radius: 5px;"
           "    color: white;"
           "    font-family: 'Roboto Medium';"
           "    }";
}

QString StyleHelper::getRightModeButtonStyle()
{
    return "QPushButton{"
           //"    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0 rgba(47, 47, 47, 255), stop:1 rgba(255, 255, 255, 255));"
           "    background: none;"
           "    background-color: qlineargradient(spread:pad, x1:0.573, y1:1, x2:0.556, y2:0, stop:0.314607 rgba(58, 58, 58, 255), stop:1 rgba(108, 108, 108, 255));"
           "    border: 1px solid #333;"
           "    border-top-right-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "    color: white;"
           "    font-family: 'Roboto Medium';"
           "    }";
}

QString StyleHelper::getLeftModeButtonActiveStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: #2d313b;"
           "    border: 1px solid #333;"
           "    border-top-left-radius: 5px;"
           "    border-bottom-left-radius: 5px;"
           "    color: grey;"
           "    font-family: 'Roboto Medium';"
           "    font-style: italic;"
           "    }";
}

QString StyleHelper::getRightModeButtonActiveStyle()
{
    return "QPushButton{"
           "    background: none;"
           "    background-color: #2d313b;"
           "    border: 1px solid #333;"
           "    border-top-right-radius: 5px;"
           "    border-bottom-right-radius: 5px;"
           "    color: grey;"
           "    font-family: 'Roboto Medium';"
           "    font-style: italic;"
           "    }";
}

QString StyleHelper::getBlankButtonStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background: none;"
           "    background-color: rgba(255, 255, 255, 85);"
           "    }"
           "QPushButton::hover{"
           "    background: rgba(255, 255, 255, 100);"
           "    }";
}

QString StyleHelper::getCrossNormalStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background: rgba(255, 255, 255, 85) url(:/resources/images/cross_large.png) no-repeat center center;"
           "    }";
//           "QPushButton::hover{"
//           "    background-color: white;"
//           "    }";
}

QString StyleHelper::getCrossVinStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background-color: green;"
           "    background-image: url(:/resources/images/cross_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    }"
           "QPushButton::hover{"
           //"    background-color: yellow;"
           "    }";
}

QString StyleHelper::getCrossLoseStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background-color: red;"
           "    background-image: url(:/resources/images/cross_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "    }"
           "QPushButton::hover{"
           //"    background-color: purple;"
           "    }";
}

QString StyleHelper::getZeroNormalStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background: rgba(255, 255, 255, 85) url(:/resources/images/zero_large.png) no-repeat center center;"
           "    }";
//           "QPushButton::hover{"
//           "    background-color: white;"
//           "}    ";
}

QString StyleHelper::getZeroVinStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background-color: green;"
           "    background-image: url(:/resources/images/zero_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}    "
           "QPushButton::hover{"
           //"    background-color: yellow;"
           "}    ";
}

QString StyleHelper::getZeroLoseStyle()
{
    return "QPushButton{"
           "    border: none;"
           "    background-color: red;"
           "    background-image: url(:/resources/images/zero_large.png);"
           "    background-repeat: no-repeat;"
           "    background-position: center center;"
           "}    "
           "QPushButton::hover{"
           //"    background-color: purple;"
            "}    ";
}

QString StyleHelper::getEmptyMsgStyle()
{
    return "QLabel{"
           "    background: none;"
           "    border-bottom: 2px solid #2a2a2a;"
           "    border-radius: 9px;"
           "    color: #ffffff;"
           "}   ";
}

QString StyleHelper::getNormalMsgStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto Medium';"
           "    font-size: 15px;"
           "    background: none;"
           "    border-bottom: 1px solid yellow;"
           "    border-radius: 9px;"
           "    background-color: qlineargradient(spread:pad, x1:0.556, y1:1, x2:0.59, y2:0, stop:0 rgba(255, 154, 102, 255), stop:0.168539 rgba(255, 102, 102, 0), stop:0.98 rgba(0, 0, 0, 0));"
           "    color: #ffffff;"
           "}   ";
}

QString StyleHelper::getVinMsgStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto Medium';"
           "    font-size: 15px;"
           "    background: none;"
           "    border-bottom: 2px solid #055902;"
           //"    border-bottom: 1px solid #1C7C32;"
           "    background-color: qlineargradient(spread:pad, x1:0.556, y1:1, x2:0.59, y2:0, stop:0 rgba(28, 124, 50, 255), stop:0.376404 rgba(255, 102, 102, 0), stop:0.98 rgba(0, 0, 0, 0));"
           "    border-radius: 9px;"
           "    color: #ffffff;"
           "}   ";
}

QString StyleHelper::getLoseMsgStyle()
{
    return "QLabel{"
           "    font-family: 'Roboto Medium';"
           "    font-size: 15px;"
           "    background: none;"
           "    border-bottom: 2px solid red;"
           "    background-color: qlineargradient(spread:pad, x1:0.556, y1:1, x2:0.59, y2:0, stop:0 rgba(170, 46, 48, 255), stop:0.269663 rgba(255, 102, 102, 0), stop:0.98 rgba(0, 0, 0, 0));"
           "    border-radius: 9px;"
           "    color: #ffffff;"
           "}   ";
}
