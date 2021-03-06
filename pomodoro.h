#ifndef POMODORO_H
#define POMODORO_H

#include <QMainWindow>
#include <QLineEdit>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Pomodoro; }
QT_END_NAMESPACE

class Pomodoro : public QMainWindow
{
    Q_OBJECT

    struct TimeInfo
    {
        int minute;
        int second;
    };
    struct TimerStatus
    {
        bool isRunning;
        bool isPaused;
        bool isDone;
    };

public:
    Pomodoro(QWidget *parent = nullptr);
    ~Pomodoro();

private:
    Ui::Pomodoro *ui;
    QTimer* m_timeCounterTimer;
    QTimer* m_breakCounterTimer;
    const int m_maxMinute;
    const int m_maxSecond;
    const int m_millisecondInSecond;
    bool m_isTimeRunning;
    bool m_isBreakRunning;
    TimeInfo m_curMinSecTime;
    TimeInfo m_curMinSecBreak;
    TimerStatus m_timeStatus;
    TimerStatus m_breakStatus;

private slots:
    void on_setTimeLineEdit_editingFinished();
    void on_setBreakLineEdit_editingFinished();
    void setLineEdit(const QString &minuteStr, QLineEdit* lineEdit, QLabel* labelCounter);
    void validateMinute(const QString minuteStr, QLineEdit* lineEdit);

    QString formatMinSec(QLineEdit* lineEditMin);
    QString formatMinSec(int minute, int second);

    void on_startTimeBtn_clicked();
    void on_startBreakBtn_clicked();

    void toggleTimer(TimerStatus &timerStatus, TimeInfo &timeInfo, QLineEdit* lineEdit, QTimer*& timer, QPushButton* pushButton, QLabel* counterLabel);
    void updateClockTime();
    void updateClockBreak();
    void on_resetTimeBtn_clicked();
    void on_resetBreakBtn_clicked();
};
#endif // POMODORO_H
