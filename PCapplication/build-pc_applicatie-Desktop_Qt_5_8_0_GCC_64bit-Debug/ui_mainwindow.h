/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *button_open_ClientDialog;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Tab_Autonomous_Control;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Stop_2;
    QPushButton *pushButton_Clean;
    QPushButton *pushButton_Dock;
    QPushButton *pushButton_Spot;
    QWidget *Tab_Manual_Control;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_1;
    QGridLayout *gridLayout;
    QPushButton *pushButton_Left;
    QPushButton *pushButton_Backward;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Forward;
    QPushButton *pushButton_Right;
    QPushButton *pushButton_Backward_Right;
    QPushButton *pushButton_Backward_Left;
    QPushButton *pushButton_Forward_Right;
    QPushButton *pushButton_Forward_Left;
    QLabel *Label_Roomba_Speed;
    QSlider *horizontalSlider_Wheel_Speed;
    QLabel *Label_Brush_Speed;
    QSlider *horizontalSlider_Brush_Speed;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Spot_Man;
    QPushButton *pushButton_Clean_Man;
    QPushButton *pushButton_Dock_Man;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(399, 519);
        MainWindow->setMinimumSize(QSize(399, 519));
        MainWindow->setMaximumSize(QSize(399, 519));
        button_open_ClientDialog = new QAction(MainWindow);
        button_open_ClientDialog->setObjectName(QStringLiteral("button_open_ClientDialog"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 381, 451));
        tabWidget->setMinimumSize(QSize(381, 451));
        tabWidget->setMaximumSize(QSize(381, 451));
        Tab_Autonomous_Control = new QWidget();
        Tab_Autonomous_Control->setObjectName(QStringLiteral("Tab_Autonomous_Control"));
        gridLayoutWidget = new QWidget(Tab_Autonomous_Control);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 20, 371, 171));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_Stop_2 = new QPushButton(gridLayoutWidget);
        pushButton_Stop_2->setObjectName(QStringLiteral("pushButton_Stop_2"));
        pushButton_Stop_2->setMinimumSize(QSize(80, 51));
        pushButton_Stop_2->setMaximumSize(QSize(80, 51));

        gridLayout_2->addWidget(pushButton_Stop_2, 0, 1, 1, 1);

        pushButton_Clean = new QPushButton(gridLayoutWidget);
        pushButton_Clean->setObjectName(QStringLiteral("pushButton_Clean"));
        pushButton_Clean->setMinimumSize(QSize(80, 51));
        pushButton_Clean->setMaximumSize(QSize(80, 51));

        gridLayout_2->addWidget(pushButton_Clean, 1, 1, 1, 1);

        pushButton_Dock = new QPushButton(gridLayoutWidget);
        pushButton_Dock->setObjectName(QStringLiteral("pushButton_Dock"));
        pushButton_Dock->setMinimumSize(QSize(80, 51));
        pushButton_Dock->setMaximumSize(QSize(80, 51));

        gridLayout_2->addWidget(pushButton_Dock, 1, 2, 1, 1);

        pushButton_Spot = new QPushButton(gridLayoutWidget);
        pushButton_Spot->setObjectName(QStringLiteral("pushButton_Spot"));
        pushButton_Spot->setMinimumSize(QSize(80, 51));
        pushButton_Spot->setMaximumSize(QSize(80, 51));

        gridLayout_2->addWidget(pushButton_Spot, 1, 0, 1, 1);

        tabWidget->addTab(Tab_Autonomous_Control, QString());
        Tab_Manual_Control = new QWidget();
        Tab_Manual_Control->setObjectName(QStringLiteral("Tab_Manual_Control"));
        verticalLayoutWidget = new QWidget(Tab_Manual_Control);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 363, 414));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_Left = new QPushButton(verticalLayoutWidget);
        pushButton_Left->setObjectName(QStringLiteral("pushButton_Left"));
        pushButton_Left->setMinimumSize(QSize(81, 81));
        pushButton_Left->setMaximumSize(QSize(81, 81));
        pushButton_Left->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_left.png);"));

        gridLayout->addWidget(pushButton_Left, 1, 0, 1, 1);

        pushButton_Backward = new QPushButton(verticalLayoutWidget);
        pushButton_Backward->setObjectName(QStringLiteral("pushButton_Backward"));
        pushButton_Backward->setMinimumSize(QSize(81, 81));
        pushButton_Backward->setMaximumSize(QSize(81, 81));
        pushButton_Backward->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_backward.png);"));

        gridLayout->addWidget(pushButton_Backward, 2, 1, 1, 1);

        pushButton_Stop = new QPushButton(verticalLayoutWidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setMinimumSize(QSize(81, 81));
        pushButton_Stop->setMaximumSize(QSize(81, 81));
        pushButton_Stop->setStyleSheet(QStringLiteral("background-color: rgb(78, 154, 6);"));

        gridLayout->addWidget(pushButton_Stop, 1, 1, 1, 1);

        pushButton_Forward = new QPushButton(verticalLayoutWidget);
        pushButton_Forward->setObjectName(QStringLiteral("pushButton_Forward"));
        pushButton_Forward->setMinimumSize(QSize(81, 81));
        pushButton_Forward->setMaximumSize(QSize(81, 81));
        pushButton_Forward->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_forward.png);"));

        gridLayout->addWidget(pushButton_Forward, 0, 1, 1, 1);

        pushButton_Right = new QPushButton(verticalLayoutWidget);
        pushButton_Right->setObjectName(QStringLiteral("pushButton_Right"));
        pushButton_Right->setMinimumSize(QSize(81, 81));
        pushButton_Right->setMaximumSize(QSize(81, 81));
        pushButton_Right->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_right.png);"));

        gridLayout->addWidget(pushButton_Right, 1, 2, 1, 1);

        pushButton_Backward_Right = new QPushButton(verticalLayoutWidget);
        pushButton_Backward_Right->setObjectName(QStringLiteral("pushButton_Backward_Right"));
        pushButton_Backward_Right->setMinimumSize(QSize(81, 81));
        pushButton_Backward_Right->setMaximumSize(QSize(81, 81));
        pushButton_Backward_Right->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_backward_right.png);"));

        gridLayout->addWidget(pushButton_Backward_Right, 2, 2, 1, 1);

        pushButton_Backward_Left = new QPushButton(verticalLayoutWidget);
        pushButton_Backward_Left->setObjectName(QStringLiteral("pushButton_Backward_Left"));
        pushButton_Backward_Left->setMinimumSize(QSize(81, 81));
        pushButton_Backward_Left->setMaximumSize(QSize(81, 81));
        pushButton_Backward_Left->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_backward_left.png);"));

        gridLayout->addWidget(pushButton_Backward_Left, 2, 0, 1, 1);

        pushButton_Forward_Right = new QPushButton(verticalLayoutWidget);
        pushButton_Forward_Right->setObjectName(QStringLiteral("pushButton_Forward_Right"));
        pushButton_Forward_Right->setMinimumSize(QSize(81, 81));
        pushButton_Forward_Right->setMaximumSize(QSize(81, 81));
        pushButton_Forward_Right->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_forward_right.png);"));

        gridLayout->addWidget(pushButton_Forward_Right, 0, 2, 1, 1);

        pushButton_Forward_Left = new QPushButton(verticalLayoutWidget);
        pushButton_Forward_Left->setObjectName(QStringLiteral("pushButton_Forward_Left"));
        pushButton_Forward_Left->setMinimumSize(QSize(81, 81));
        pushButton_Forward_Left->setMaximumSize(QSize(81, 81));
        pushButton_Forward_Left->setStyleSheet(QStringLiteral("border-image: url(:/Images/arrow_forward_left.png);"));

        gridLayout->addWidget(pushButton_Forward_Left, 0, 0, 1, 1);


        verticalLayout_1->addLayout(gridLayout);


        verticalLayout->addLayout(verticalLayout_1);

        Label_Roomba_Speed = new QLabel(verticalLayoutWidget);
        Label_Roomba_Speed->setObjectName(QStringLiteral("Label_Roomba_Speed"));
        Label_Roomba_Speed->setMinimumSize(QSize(131, 17));
        Label_Roomba_Speed->setMaximumSize(QSize(131, 17));

        verticalLayout->addWidget(Label_Roomba_Speed);

        horizontalSlider_Wheel_Speed = new QSlider(verticalLayoutWidget);
        horizontalSlider_Wheel_Speed->setObjectName(QStringLiteral("horizontalSlider_Wheel_Speed"));
        horizontalSlider_Wheel_Speed->setMaximum(100);
        horizontalSlider_Wheel_Speed->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_Wheel_Speed);

        Label_Brush_Speed = new QLabel(verticalLayoutWidget);
        Label_Brush_Speed->setObjectName(QStringLiteral("Label_Brush_Speed"));
        Label_Brush_Speed->setMinimumSize(QSize(121, 17));
        Label_Brush_Speed->setMaximumSize(QSize(121, 17));

        verticalLayout->addWidget(Label_Brush_Speed);

        horizontalSlider_Brush_Speed = new QSlider(verticalLayoutWidget);
        horizontalSlider_Brush_Speed->setObjectName(QStringLiteral("horizontalSlider_Brush_Speed"));
        horizontalSlider_Brush_Speed->setMaximum(128);
        horizontalSlider_Brush_Speed->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_Brush_Speed);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_Spot_Man = new QPushButton(verticalLayoutWidget);
        pushButton_Spot_Man->setObjectName(QStringLiteral("pushButton_Spot_Man"));
        pushButton_Spot_Man->setMinimumSize(QSize(80, 51));
        pushButton_Spot_Man->setMaximumSize(QSize(80, 51));

        horizontalLayout->addWidget(pushButton_Spot_Man);

        pushButton_Clean_Man = new QPushButton(verticalLayoutWidget);
        pushButton_Clean_Man->setObjectName(QStringLiteral("pushButton_Clean_Man"));
        pushButton_Clean_Man->setMinimumSize(QSize(80, 51));
        pushButton_Clean_Man->setMaximumSize(QSize(80, 51));

        horizontalLayout->addWidget(pushButton_Clean_Man);

        pushButton_Dock_Man = new QPushButton(verticalLayoutWidget);
        pushButton_Dock_Man->setObjectName(QStringLiteral("pushButton_Dock_Man"));
        pushButton_Dock_Man->setMinimumSize(QSize(80, 51));
        pushButton_Dock_Man->setMaximumSize(QSize(80, 51));

        horizontalLayout->addWidget(pushButton_Dock_Man);


        verticalLayout->addLayout(horizontalLayout);

        tabWidget->addTab(Tab_Manual_Control, QString());
        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 399, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        toolBar->addAction(button_open_ClientDialog);
        menuBar->addAction(menuMenu->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        button_open_ClientDialog->setText(QApplication::translate("MainWindow", "Server Connection", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        button_open_ClientDialog->setToolTip(QApplication::translate("MainWindow", "ServerConnection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton_Stop_2->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        pushButton_Clean->setText(QApplication::translate("MainWindow", "Clean", Q_NULLPTR));
        pushButton_Dock->setText(QApplication::translate("MainWindow", "Dock", Q_NULLPTR));
        pushButton_Spot->setText(QApplication::translate("MainWindow", "Spot", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Tab_Autonomous_Control), QApplication::translate("MainWindow", "Autonomous Control", Q_NULLPTR));
        pushButton_Left->setText(QString());
        pushButton_Backward->setText(QString());
        pushButton_Stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        pushButton_Forward->setText(QString());
        pushButton_Right->setText(QString());
        pushButton_Backward_Right->setText(QString());
        pushButton_Backward_Left->setText(QString());
        pushButton_Forward_Right->setText(QString());
        pushButton_Forward_Left->setText(QString());
        Label_Roomba_Speed->setText(QApplication::translate("MainWindow", "Roomba Speed", Q_NULLPTR));
        Label_Brush_Speed->setText(QApplication::translate("MainWindow", "Brush Speed", Q_NULLPTR));
        pushButton_Spot_Man->setText(QApplication::translate("MainWindow", "Spot", Q_NULLPTR));
        pushButton_Clean_Man->setText(QApplication::translate("MainWindow", "Clean", Q_NULLPTR));
        pushButton_Dock_Man->setText(QApplication::translate("MainWindow", "Dock", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Tab_Manual_Control), QApplication::translate("MainWindow", "Manual Control", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
