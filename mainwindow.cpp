#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QString>
#include <QClipboard>
#include <iostream>
#include <QMessageBox>
#include <QSpacerItem>
#include <description.h>
#include <QProcess>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItem("svmpcalcparm");
    ui->comboBox->addItem("ProcessNow");
    ui->comboBox->addItem("svhrrolavg");

    newLayout();

    svcommand = new QString();
    *svcommand = "";

    siteText = new QString();
    *siteText = siteLineEdit->text();

    paramText = new QString();
    *paramText = paramLineEdit->text();

    startDateText = new QString();
    *startDateText = startDateLineEdit->text();

    endDateText = new QString();
    *endDateText = endDateLineEdit->text();

    startHourText = new QString();
    *startHourText = startHourLineEdit->text();

    endHourText = new QString();
    *endHourText = endHourLineEdit->text();

    timeIntervalText = new QString();
    *timeIntervalText = timeIntervalLineEdit->text();

    tSwitchText = new QString("");
    TSwitchText = new QString("");
    fSwitchText = new QString("");

    svmpcalcparmHelp();
    ProcessNowHelp();

    description = new Description();
    newDescriptionLayout();

    cascadeCommand = new QString("");
    LSwitchCommand = new QString("");
    MSwitchCommand = new QString("");
    ISwitchCommand = new QString("");
    OSwitchCommand = new QString("");
    mSwitchCommand = new QString("");
    debugText = new QString("");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{


    if(arg1 == "ProcessNow" && ui->groupBox->layout() == layout) {
        deleteLayout();
        newLayout2();

        descriptionText = ProcessNowHelpText;
        descriptionLabel->setText(*ProcessNowHelpText);

    }
    else if(arg1 == "ProcessNow" && ui->groupBox->layout() == layout_svhrrolavg) {
        deleteLayout_svhrrolavg();
        newLayout2();

        descriptionText = ProcessNowHelpText;
        descriptionLabel->setText(*ProcessNowHelpText);
    }

    if(arg1 == "svmpcalcparm" && ui->groupBox->layout() == layout2) {
        deleteLayout2();
        newLayout();

        descriptionText = svmpcalcparmHelpText;
        descriptionLabel->setText(*descriptionText);
    }
    else if(arg1 == "svmpcalcparm" && ui->groupBox->layout() == layout_svhrrolavg) {
        deleteLayout_svhrrolavg();
        newLayout();

        descriptionText = svmpcalcparmHelpText;
        descriptionLabel->setText(*descriptionText);
    }

    if(arg1 == "svhrrolavg" && ui->groupBox->layout() == layout) {
        deleteLayout();
        newLayout_svhrrolavg();
    }
    else if(arg1 =="svhrrolavg" && ui->groupBox->layout() == layout2) {
        deleteLayout2();
        newLayout_svhrrolavg();
    }



}



// ------- START WIDGET ACTION FUNCTIONALITY FUNCTIONS -------

void MainWindow::on_pushButton_clicked()
{

    if(ui->comboBox->currentText() == "svmpcalcparm"){

        siteTextReplace();
        paramTextReplace();
        startDateTextReplace();
        endDateTextReplace();
        startHourTextReplace();
        endHourTextReplace();
        timeIntervalTextReplace();

        if(debugCheckBox->isChecked() == true)
            *debugText = "-@ " + debugLineEdit->text();
        else
            *debugText = "";

        if(cascadeCheckBox->isChecked() == true)
            *cascadeCommand = "-c ";
        else
            *cascadeCommand = "";

        if(MSwitchCheckBox->isChecked() == true)
            *MSwitchCommand = "-M ";
        else
            *MSwitchCommand = "";

        if(LSwitchCheckBox->isChecked() == true)
            *LSwitchCommand = "-L ";
        else
            *LSwitchCommand = "";

        if(ISwitchCheckBox->isChecked() == true)
            *ISwitchCommand = "-I ";
        else
            *ISwitchCommand = "";

        if(OSwitchCheckBox->isChecked() == true)
            *OSwitchCommand = "-O ";
        else
            *OSwitchCommand = "";

        if(mSwitchCheckBox->isChecked() == true)
            *mSwitchCommand = "-m ";
        else
            *mSwitchCommand = "";

            *svcommand = ui->comboBox->currentText() + " -s " + *siteText + " -p " + *paramText + " -d " + *startDateText + " -D " + *endDateText + " -h " + *startHourText + " -H " + *endHourText + " -t " + *timeIntervalText + " " + *cascadeCommand + *LSwitchCommand + *MSwitchCommand + *ISwitchCommand + *OSwitchCommand + *mSwitchCommand + *debugText;
        }
        else if(ui->comboBox->currentText() == "ProcessNow") {

        startDateTextReplace();
        endDateTextReplace();
        tSwitchTextReplace();
        TSwitchTextReplace();
        fSwitchTextReplace();

        *svcommand = ui->comboBox->currentText() + " -d " + *startDateText + " -D " + *endDateText + " -t " + *tSwitchText + " -T " + *TSwitchText + " -f " + *fSwitchText;
        }

    cp->clear();
    cp->setText(*svcommand);
}

// ------- END WIDGET ACTION FUNCTIONALITY FUNCTIONS -------



// -------START CUSTOM FUNCTIONS SECTION -------

void MainWindow::siteTextReplace() {
    *siteText = siteLineEdit->text();
}

void MainWindow::paramTextReplace() {
    *paramText = paramLineEdit->text();
}

void MainWindow::startDateTextReplace() {
    *startDateText = startDateLineEdit->text();
}

void MainWindow::endDateTextReplace() {
    *endDateText = endDateLineEdit->text();
}

void MainWindow::startHourTextReplace() {
    *startHourText = startHourLineEdit->text();
}

void MainWindow::endHourTextReplace() {
    *endHourText = endHourLineEdit->text();
}

void MainWindow::timeIntervalTextReplace() {
    *timeIntervalText = timeIntervalLineEdit->text();
}

void MainWindow::debugTextReplace() {
    *debugText = debugLineEdit->text();
}

void MainWindow::tSwitchTextReplace() {
    *tSwitchText = tSwitchLineEdit->text();
}

void MainWindow::TSwitchTextReplace() {
    *TSwitchText = TSwitchLineEdit->text();
}

void MainWindow::fSwitchTextReplace() {
    *fSwitchText = fSwitchLineEdit->text();
}


void MainWindow::newLayout() {

    layout = new QGridLayout;
    layout_noEdit = new QGridLayout;

    siteLabel = new QLabel("<site>");
    paramLabel = new QLabel("<parameter>");
    startDateLabel = new QLabel("<start date>");
    endDateLabel = new QLabel("<end date>");
    startHourLabel = new QLabel("<start hour>");
    endHourLabel = new QLabel("<end hour>");
    timeIntervalLabel = new QLabel("<time interval>");
    debugLabel = new QLabel("<debug>");

    siteCheckBox = new QCheckBox("-s");
    siteCheckBox->setChecked(true);
    siteCheckBox->setEnabled(false);
    paramCheckBox = new QCheckBox("-p");
    paramCheckBox->setChecked(true);
    paramCheckBox->setEnabled(false);
    startDateCheckBox = new QCheckBox("-d");
    startDateCheckBox->setChecked(true);
    startDateCheckBox->setEnabled(false);
    endDateCheckBox = new QCheckBox("-D");
    endDateCheckBox->setChecked(true);
    endDateCheckBox->setEnabled(false);
    startHourCheckBox = new QCheckBox("-h");
    startHourCheckBox->setChecked(true);
    startHourCheckBox->setEnabled(false);
    endHourCheckBox = new QCheckBox("-H");
    endHourCheckBox->setChecked(true);
    endHourCheckBox->setEnabled(false);
    timeIntervalCheckBox = new QCheckBox("-t");
    timeIntervalCheckBox->setChecked(true);
    timeIntervalCheckBox->setEnabled(false);
    cascadeCheckBox = new QCheckBox("-c");
    cascadeCheckBox->setChecked(false);
    MSwitchCheckBox = new QCheckBox("-M");
    MSwitchCheckBox->setChecked(false);
    LSwitchCheckBox = new QCheckBox("-L");
    LSwitchCheckBox->setChecked(true);
    ISwitchCheckBox = new QCheckBox("-I");
    ISwitchCheckBox->setChecked(false);
    debugCheckBox = new QCheckBox("-@");
    debugCheckBox->setChecked(false);
    OSwitchCheckBox = new QCheckBox("-O");
    OSwitchCheckBox->setChecked(false);
    mSwitchCheckBox = new QCheckBox("-m");
    mSwitchCheckBox->setChecked(false);

    siteLineEdit = new QLineEdit();
    siteLineEdit->setPlaceholderText("<ALL>");
    paramLineEdit = new QLineEdit();
    paramLineEdit->setPlaceholderText("<ALL>");
    startDateLineEdit = new QLineEdit();
    startDateLineEdit->setPlaceholderText("<mmddyy>");
    endDateLineEdit = new QLineEdit();
    endDateLineEdit->setPlaceholderText("<mmddyy>");
    startHourLineEdit = new QLineEdit();
    startHourLineEdit->setPlaceholderText("<hhmm>");
    endHourLineEdit = new QLineEdit();
    endHourLineEdit->setPlaceholderText("<hhmm>");
    timeIntervalLineEdit = new QLineEdit();
    timeIntervalLineEdit->setPlaceholderText("<001H>");
    debugLineEdit = new QLineEdit();
    debugLineEdit->setPlaceholderText("2>C:\\Users\\Escsupport\\Desktop\\Debug.txt");

    layout->addWidget(siteCheckBox,0,0);
    layout->addWidget(siteLabel,0,1);
    layout->addWidget(siteLineEdit,0,2);
    layout->addWidget(paramCheckBox,1,0);
    layout->addWidget(paramLabel,1,1);
    layout->addWidget(paramLineEdit,1,2);
    layout->addWidget(startDateCheckBox,2,0);
    layout->addWidget(startDateLabel,2,1);
    layout->addWidget(startDateLineEdit,2,2);
    layout->addWidget(endDateCheckBox,3,0);
    layout->addWidget(endDateLabel,3,1);
    layout->addWidget(endDateLineEdit,3,2);
    layout->addWidget(startHourCheckBox,4,0);
    layout->addWidget(startHourLabel,4,1);
    layout->addWidget(startHourLineEdit,4,2);
    layout->addWidget(endHourCheckBox,5,0);
    layout->addWidget(endHourLabel,5,1);
    layout->addWidget(endHourLineEdit,5,2);
    layout->addWidget(timeIntervalCheckBox,6,0);
    layout->addWidget(timeIntervalLabel,6,1);
    layout->addWidget(timeIntervalLineEdit,6,2);
    layout->addWidget(debugCheckBox,7,0);
    layout->addWidget(debugLabel,7,1);
    layout->addWidget(debugLineEdit,7,2);


    layout_noEdit->addWidget(cascadeCheckBox,0,0);
    layout_noEdit->addWidget(MSwitchCheckBox,0,1);
    layout_noEdit->addWidget(LSwitchCheckBox,0,2);
    layout_noEdit->addWidget(ISwitchCheckBox,0,3);
    layout_noEdit->addWidget(OSwitchCheckBox,0,4);
    layout_noEdit->addWidget(mSwitchCheckBox,0,5);

    ui->groupBox->setLayout(layout);
    ui->groupBox_noEdit->setLayout(layout_noEdit);

    ui->groupBox_noEdit->setMaximumHeight(35);
    ui->groupBox_noEdit->setMaximumWidth(250);

    ui->groupBox_noEdit->setVisible(true);


}

void MainWindow::newLayout2() {

    layout2 = new QGridLayout;

    startDateLabel = new QLabel("<start date>");
    endDateLabel = new QLabel("<end date>");
    tSwitchLabel = new QLabel("<start hour");
    TSwitchLabel = new QLabel("<end hour>");
    fSwitchLabel = new QLabel("<file name>");


    startDateCheckBox = new QCheckBox("-d");
    startDateCheckBox->setChecked(true);
    startDateCheckBox->setEnabled(false);
    endDateCheckBox = new QCheckBox("-D");
    endDateCheckBox->setChecked(true);
    endDateCheckBox->setEnabled(false);
    tSwitchCheckBox = new QCheckBox("-t");
    tSwitchCheckBox->setChecked(true);
    tSwitchCheckBox->setEnabled(false);
    TSwitchCheckBox = new QCheckBox("-T");
    TSwitchCheckBox->setChecked(true);
    TSwitchCheckBox->setEnabled(false);
    fSwitchCheckBox = new QCheckBox("-f");
    fSwitchCheckBox->setChecked(true);
    fSwitchCheckBox->setEnabled(false);

    startDateLineEdit = new QLineEdit();
    startDateLineEdit->setPlaceholderText("<mmddyy>");
    endDateLineEdit = new QLineEdit();
    endDateLineEdit->setPlaceholderText("<mmddyy>");
    tSwitchLineEdit = new QLineEdit();
    tSwitchLineEdit->setPlaceholderText("<hhmm>");
    TSwitchLineEdit = new QLineEdit();
    TSwitchLineEdit->setPlaceholderText("<hhmm>");
    fSwitchLineEdit = new QLineEdit();
    fSwitchLineEdit->setPlaceholderText("<UNIT01_DAILY>");

    layout2->addWidget(startDateCheckBox,0,0);
    layout2->addWidget(startDateLabel,0,1);
    layout2->addWidget(startDateLineEdit,0,2);
    layout2->addWidget(endDateCheckBox,1,0);
    layout2->addWidget(endDateLabel,1,1);
    layout2->addWidget(endDateLineEdit,1,2);
    layout2->addWidget(tSwitchCheckBox,2,0);
    layout2->addWidget(tSwitchLabel,2,1);
    layout2->addWidget(tSwitchLineEdit,2,2);
    layout2->addWidget(TSwitchCheckBox,3,0);
    layout2->addWidget(TSwitchLabel,3,1);
    layout2->addWidget(TSwitchLineEdit,3,2);
    layout2->addWidget(fSwitchCheckBox,4,0);
    layout2->addWidget(fSwitchLabel,4,1);
    layout2->addWidget(fSwitchLineEdit,4,2);

    ui->groupBox->setLayout(layout2);
    ui->groupBox_noEdit->setVisible(false);
}

void MainWindow::newLayout_svhrrolavg() {

    layout_svhrrolavg = new QGridLayout;

    siteLabel = new QLabel("<site>");
    paramLabel = new QLabel("<parameter>");
    startDateLabel = new QLabel("<start date>");
    endDateLabel = new QLabel("<end date>");
    startHourLabel = new QLabel("<start hour>");
    endHourLabel = new QLabel("<end hour>");
    aSwitchLabel = new QLabel("<time interval");

    siteCheckBox = new QCheckBox("-s");
    siteCheckBox->setChecked(true);
    siteCheckBox->setEnabled(false);
    paramCheckBox = new QCheckBox("-p");
    paramCheckBox->setChecked(true);
    paramCheckBox->setEnabled(false);
    startDateCheckBox = new QCheckBox("-d");
    startDateCheckBox->setChecked(true);
    startDateCheckBox->setEnabled(false);
    endDateCheckBox = new QCheckBox("-D");
    endDateCheckBox->setChecked(true);
    endDateCheckBox->setEnabled(false);
    startHourCheckBox = new QCheckBox("-h");
    startHourCheckBox->setChecked(true);
    startHourCheckBox->setEnabled(false);
    endHourCheckBox = new QCheckBox("-H");
    endHourCheckBox->setChecked(true);
    endHourCheckBox->setEnabled(false);
    aSwitchCheckBox = new QCheckBox("-a");
    aSwitchCheckBox->setChecked(true);
    aSwitchCheckBox->setEnabled(false);

    siteLineEdit = new QLineEdit();
    siteLineEdit->setPlaceholderText("<ALL>");
    paramLineEdit = new QLineEdit();
    paramLineEdit->setPlaceholderText("<ALL>");
    startDateLineEdit = new QLineEdit();
    startDateLineEdit->setPlaceholderText("<mmddyy>");
    endDateLineEdit = new QLineEdit();
    endDateLineEdit->setPlaceholderText("<mmddyy>");
    startHourLineEdit = new QLineEdit();
    startHourLineEdit->setPlaceholderText("<hhmm>");
    endHourLineEdit = new QLineEdit();
    endHourLineEdit->setPlaceholderText("<hhmm>");
    aSwitchLineEdit = new QLineEdit();
    aSwitchLineEdit->setPlaceholderText("<001H>");

    layout_svhrrolavg->addWidget(siteCheckBox,0,0);
    layout_svhrrolavg->addWidget(siteLabel,0,1);
    layout_svhrrolavg->addWidget(siteLineEdit,0,2);
    layout_svhrrolavg->addWidget(paramCheckBox,1,0);
    layout_svhrrolavg->addWidget(paramLabel,1,1);
    layout_svhrrolavg->addWidget(paramLineEdit,1,2);
    layout_svhrrolavg->addWidget(startDateCheckBox,2,0);
    layout_svhrrolavg->addWidget(startDateLabel,2,1);
    layout_svhrrolavg->addWidget(startDateLineEdit,2,2);
    layout_svhrrolavg->addWidget(endDateCheckBox,3,0);
    layout_svhrrolavg->addWidget(endDateLabel,3,1);
    layout_svhrrolavg->addWidget(endDateLineEdit,3,2);
    layout_svhrrolavg->addWidget(startHourCheckBox,4,0);
    layout_svhrrolavg->addWidget(startHourLabel,4,1);
    layout_svhrrolavg->addWidget(startHourLineEdit,4,2);
    layout_svhrrolavg->addWidget(endHourCheckBox,5,0);
    layout_svhrrolavg->addWidget(endHourLabel,5,1);
    layout_svhrrolavg->addWidget(endHourLineEdit,5,2);
    layout_svhrrolavg->addWidget(aSwitchCheckBox,6,0);
    layout_svhrrolavg->addWidget(aSwitchLabel,6,1);
    layout_svhrrolavg->addWidget(aSwitchLineEdit,6,2);

    ui->groupBox->setLayout(layout_svhrrolavg);
}

void MainWindow::deleteLayout() {

    delete layout;
    delete siteCheckBox;
    delete siteLabel;
    delete siteLineEdit;

    delete paramCheckBox;
    delete paramLabel;
    delete paramLineEdit;

    delete startDateCheckBox;
    delete startDateLabel;
    delete startDateLineEdit;

    delete endDateCheckBox;
    delete endDateLabel;
    delete endDateLineEdit;

    delete startHourCheckBox;
    delete startHourLabel;
    delete startHourLineEdit;

    delete endHourCheckBox;
    delete endHourLabel;
    delete endHourLineEdit;

    delete timeIntervalCheckBox;
    delete timeIntervalLabel;
    delete timeIntervalLineEdit;

    delete debugCheckBox;
    delete debugLabel;
    delete debugLineEdit;

    delete layout_noEdit;
    delete cascadeCheckBox;
    delete MSwitchCheckBox;
    delete LSwitchCheckBox;
    delete ISwitchCheckBox;
    delete OSwitchCheckBox;
    delete mSwitchCheckBox;

}

void MainWindow::deleteLayout2() {

    delete layout2;

    delete startDateCheckBox;
    delete startDateLabel;
    delete startDateLineEdit;

    delete endDateCheckBox;
    delete endDateLabel;
    delete endDateLineEdit;

    delete TSwitchCheckBox;
    delete TSwitchLabel;
    delete TSwitchLineEdit;

    delete tSwitchCheckBox;
    delete tSwitchLabel;
    delete tSwitchLineEdit;

    delete fSwitchCheckBox;
    delete fSwitchLabel;
    delete fSwitchLineEdit;

}

void MainWindow::deleteLayout_svhrrolavg() {

    delete layout_svhrrolavg;
    delete siteCheckBox;
    delete siteLabel;
    delete siteLineEdit;

    delete paramCheckBox;
    delete paramLabel;
    delete paramLineEdit;

    delete startDateCheckBox;
    delete startDateLabel;
    delete startDateLineEdit;

    delete endDateCheckBox;
    delete endDateLabel;
    delete endDateLineEdit;

    delete startHourCheckBox;
    delete startHourLabel;
    delete startHourLineEdit;

    delete endHourCheckBox;
    delete endHourLabel;
    delete endHourLineEdit;

    delete aSwitchCheckBox;
    delete aSwitchLabel;
    delete aSwitchLineEdit;

}

// ------- END CUSTOM FUNCTIONS SECTION -------


// ------- START HELP FUNCTIONS SECTION -------

void MainWindow::svmpcalcparmHelp() {
    svmpcalcparmHelpText = new QString("\
mpcalcparm - Calculate parameter values based on user defined equations. \n\
Usage: mpcalcparm [-s <site[,site,...]>] [-p <parameter[,parameter,...]>]\n\
                  [-d <start date>] [-h <start time>]\n\
                  [-D <end date>] [-H <end time>]\n\
                  [-t <average type>] [-c] [-M] [-L] [-I] [-O] [-m] [-@]\n\
                                            \n\
                      -s and -p support 'ALL'\n\
                      -d, -D dates are in the format mmddyy\n\
                      -h, -H times are in the format hhmm\n\
                       -t     averaging interval and data type, supported data types are\n\
                              m for minutes, h for hour, d for day, n for month, default is 1h.\n\
                       -c     compute parameters calculated from specified parameter\n\
                       -M     propagate INV, MISS, OOC, SUSP, STATE_INV, OUR, CAP data flags only,\n\
                                                      and redetermine EXC (no data value modification)\n\
                       -L     calculate logger and central math parameters\n\
                       -I     do not overwrite System, Component, Formula ID's or MC\n\
                       -O     do not cascade results\n\
                       -m     has no effect (retained to be backward compatible for scheduled task)\n\
                       -@     enable error reporting.\n\
                                            \n\
Diluent capping controlled by resources MP_CAPPED_DILUENT, MP_CAP_ALWAYS,\n\
MP_CAP_ZERO_ONLY, MP_CAP_VALUE, and MP_CAP_ROUND_FIRST.\n\
                                            \n\
           Ex: mpcalcparm -s ALL -p ALL -t 1h -d 030193 -h 1200 -D 030293 -H 0800\n\
               calculates all hourly central math parameters from March 1 at noon to\n\
               March 2 at 8am \n\
           or\n\
               mpcalcparm -s UNIT#1 -p SO2 -I -L -t 1h\n\
               calculates UNIT#1:SO2 for the most recent hour without overwriting ID's\n\
           or\n\
               mpcalcparm -L\n\
               will calculate all hourly central and logger math parameters for the\n\
               most recent hour.\n\
           mpcalcparm (returning Code 120)");


}

void MainWindow::ProcessNowHelp() {

        ProcessNowHelpText = new QString("\
Usage:\n\
Note that the start and end time is “t” and “T”, not “h” and “H”:\n\
\n\
• “-d MMDDYY” start date where “MMDDYY” is a fixed date\n\
• “-D MMDDYY” end date where “MMDDYY” is a fixed date\n\
• “-t HHMM” start time where “HHMM” is a fixed time\n\
• “-T HHMM” end time where “HHMM” is a fixed time\n\
• “-f filename” where filename is the name of the .AUTO file (without the extension)\n\
\n\
Default time range is beginning of current quarter to NOW-1 hour.\n\
\n\
\n\
The “-d” option also allows the following in place of the MMDDYY:\n\
\n\
• “TODAY-n” where “n” is the number of days before today\n\
• “NOW-nd” where “n” is the number of days before now\n\
• “NOW-nH” where “n” is the number of hours before now (minutes are set to 00)");
}


void MainWindow::on_pushButton_Description_clicked()
{
        description->show();
}

void MainWindow::newDescriptionLayout() {
    descriptionLayout = new QGridLayout();
    descriptionText = new QString(*svmpcalcparmHelpText);
    descriptionLabel = new QLabel(*descriptionText);
    descriptionLabel->setAlignment(Qt::AlignTop);

    descriptionLayout->addWidget(descriptionLabel);

    description->setLayout(descriptionLayout);
}

void MainWindow::executeCommand() {

    if(ui->comboBox->currentText() == "ProcessNow") {
    QProcess *command = new QProcess();
    *svcommand = "%cem_data_root%..\\Server\\" + *svcommand;
    command->start("C:\\Windows\\System32\\cmd.exe", QStringList() << "/C" << *svcommand);
}

    else {
    QProcess *command = new QProcess();
    command->start("C:\\Windows\\System32\\cmd.exe", QStringList() << "/C" << *svcommand);
    }
}

void MainWindow::on_pushButton_Run_clicked()
{
    if(ui->comboBox->currentText() == "svmpcalcparm"){

    siteTextReplace();
    paramTextReplace();
    startDateTextReplace();
    endDateTextReplace();
    startHourTextReplace();
    endHourTextReplace();
    timeIntervalTextReplace();
    debugTextReplace();

        if(debugCheckBox->isChecked() == true)
            *debugText = "-@ " + *debugText;
        else
            *debugText = "";

        if(cascadeCheckBox->isChecked() == true)
            *cascadeCommand = "-c ";
        else
            *cascadeCommand = "";

        if(MSwitchCheckBox->isChecked() == true)
            *MSwitchCommand = "-M ";
        else
            *MSwitchCommand = "";

        if(LSwitchCheckBox->isChecked() == true)
            *LSwitchCommand = "-L ";
        else
            *LSwitchCommand = "";

        if(ISwitchCheckBox->isChecked() == true)
            *ISwitchCommand = "-I ";
        else
            *ISwitchCommand = "";

        if(OSwitchCheckBox->isChecked() == true)
            *OSwitchCommand = "-O ";
        else
            *OSwitchCommand = "";

        if(mSwitchCheckBox->isChecked() == true)
            *mSwitchCommand = "-m ";
        else
            *mSwitchCommand = "";

            *svcommand = ui->comboBox->currentText() + " -s " + *siteText + " -p " + *paramText + " -d " + *startDateText + " -D " + *endDateText + " -h " + *startHourText + " -H " + *endHourText + " -t " + *timeIntervalText + " " + *cascadeCommand + *LSwitchCommand + *MSwitchCommand + *ISwitchCommand + *OSwitchCommand + *mSwitchCommand + *debugText;

        }
    else if(ui->comboBox->currentText() == "ProcessNow") {

    startDateTextReplace();
    endDateTextReplace();
    tSwitchTextReplace();
    TSwitchTextReplace();
    fSwitchTextReplace();

    *svcommand = ui->comboBox->currentText() + " -d " + *startDateText + " -D " + *endDateText + " -t " + *tSwitchText + " -T " + *TSwitchText + " -f " + *fSwitchText;
}

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Run the following command?",*svcommand,QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    executeCommand();

}
