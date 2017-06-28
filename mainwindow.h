#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QString>
#include <QClipboard>
#include <description.h>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGridLayout *layout;
    QGridLayout *layout_noEdit;
    QGridLayout *layout2;
    QGridLayout *descriptionLayout;
    QGridLayout *layout_svhrrolavg;
    QGridLayout *layout_svhrrolavg_noEdit;


    QLabel *descriptionLabel;
    QLabel *siteLabel;
    QLabel *paramLabel;
    QLabel *startDateLabel;
    QLabel *endDateLabel;
    QLabel *startHourLabel;
    QLabel *endHourLabel;
    QLabel *timeIntervalLabel;
    QLabel *debugLabel;
    QLabel *tSwitchLabel;
    QLabel *TSwitchLabel;
    QLabel *fSwitchLabel;
    QLabel *aSwitchLabel;

    QCheckBox *siteCheckBox;
    QCheckBox *paramCheckBox;
    QCheckBox *startDateCheckBox;
    QCheckBox *endDateCheckBox;
    QCheckBox *startHourCheckBox;
    QCheckBox *endHourCheckBox;
    QCheckBox *timeIntervalCheckBox;
    QCheckBox *debugCheckBox;
    QCheckBox *tSwitchCheckBox;
    QCheckBox *TSwitchCheckBox;
    QCheckBox *fSwitchCheckBox;
    QCheckBox *aSwitchCheckBox;

    QCheckBox *cascadeCheckBox;
    QCheckBox *MSwitchCheckBox;
    QCheckBox *LSwitchCheckBox;
    QCheckBox *ISwitchCheckBox;
    QCheckBox *OSwitchCheckBox;
    QCheckBox *mSwitchCheckBox;

    QLineEdit *siteLineEdit;
    QLineEdit *paramLineEdit;
    QLineEdit *startDateLineEdit;
    QLineEdit *endDateLineEdit;
    QLineEdit *startHourLineEdit;
    QLineEdit *endHourLineEdit;
    QLineEdit *timeIntervalLineEdit;
    QLineEdit *debugLineEdit;
    QLineEdit *tSwitchLineEdit;
    QLineEdit *TSwitchLineEdit;
    QLineEdit *fSwitchLineEdit;
    QLineEdit *aSwitchLineEdit;

    QString *siteText;
    QString *paramText;
    QString *startDateText;
    QString *endDateText;
    QString *startHourText;
    QString *endHourText;
    QString *timeIntervalText;
    QString *debugText;

    QString *tSwitchText;
    QString *TSwitchText;
    QString *fSwitchText;

    QString *cascadeCommand;
    QString *LSwitchCommand;
    QString *MSwitchCommand;
    QString *ISwitchCommand;
    QString *OSwitchCommand;
    QString *mSwitchCommand;

    QString *svcommand;
    QString *descriptionText;

    QString *svmpcalcparmHelpText;
    QString *ProcessNowHelpText;

    QClipboard *cp;

private slots:

    void deleteLayout();
    void deleteLayout2();
    void deleteLayout_svhrrolavg();

    void newDescriptionLayout();

    void newLayout();
    void newLayout2();
    void newLayout_svhrrolavg();

    void svmpcalcparmHelp();
    void ProcessNowHelp();

    void siteTextReplace();
    void paramTextReplace();
    void startDateTextReplace();
    void endDateTextReplace();
    void startHourTextReplace();
    void endHourTextReplace();
    void timeIntervalTextReplace();
    void debugTextReplace();

    void tSwitchTextReplace();
    void TSwitchTextReplace();
    void fSwitchTextReplace();



    void executeCommand();


    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();

    void on_pushButton_Description_clicked();

    void on_pushButton_Run_clicked();

private:
    Ui::MainWindow *ui;
    Description *description;
};

#endif // MAINWINDOW_H
