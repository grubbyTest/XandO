#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include <QString>

class StyleHelper
{
public:
    static QString getStartButtonStyle();
    static QString getStartButtonActiveStyle();
    static QString setMainWidgetStyle();
    static QString getLeftButtonStyle();
    static QString getRightButtonStyle();
    static QString getLeftButtonActiveStyle();
    static QString getRightButtonActiveStyle();
    static QString getTabWidgetStyle();
    static QString getTabStyle();

    static QString getLeftModeButtonStyle();
    static QString getRightModeButtonStyle();
    static QString getLeftModeButtonActiveStyle();
    static QString getRightModeButtonActiveStyle();

    static QString getBlankButtonStyle();
    static QString getCrossNormalStyle();
    static QString getCrossVinStyle();
    static QString getCrossLoseStyle();

    static QString getZeroNormalStyle();
    static QString getZeroVinStyle();
    static QString getZeroLoseStyle();

    static QString getEmptyMsgStyle();
    static QString getNormalMsgStyle();
    static QString getVinMsgStyle();
    static QString getLoseMsgStyle();
};

#endif // STYLEHELPER_H
