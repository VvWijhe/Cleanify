/********************************************************************************
** Form generated from reading UI file 'roombasim.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMBASIM_H
#define UI_ROOMBASIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoombaSim
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *view;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *speedLabel;
    QSlider *speedSlider;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *RoombaSim)
    {
        if (RoombaSim->objectName().isEmpty())
            RoombaSim->setObjectName(QStringLiteral("RoombaSim"));
        RoombaSim->setEnabled(true);
        RoombaSim->resize(958, 486);
        RoombaSim->setMaximumSize(QSize(958, 486));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        RoombaSim->setFont(font);
        centralwidget = new QWidget(RoombaSim);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        view = new QGraphicsView(centralwidget);
        view->setObjectName(QStringLiteral("view"));

        horizontalLayout->addWidget(view);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(20, 0, 20, 0);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setMinimumSize(QSize(180, 31));

        verticalLayout->addWidget(startButton);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(180, 31));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(7);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        speedLabel = new QLabel(centralwidget);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(speedLabel);

        speedSlider = new QSlider(centralwidget);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setMaximumSize(QSize(100, 16777215));
        speedSlider->setMinimum(30);
        speedSlider->setMaximum(900);
        speedSlider->setSingleStep(90);
        speedSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(speedSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        RoombaSim->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(RoombaSim);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RoombaSim->setStatusBar(statusbar);
        menubar = new QMenuBar(RoombaSim);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 958, 24));
        RoombaSim->setMenuBar(menubar);

        retranslateUi(RoombaSim);

        QMetaObject::connectSlotsByName(RoombaSim);
    } // setupUi

    void retranslateUi(QMainWindow *RoombaSim)
    {
        RoombaSim->setWindowTitle(QApplication::translate("RoombaSim", "MainWindow", 0));
        startButton->setText(QApplication::translate("RoombaSim", "Start", 0));
        pushButton->setText(QApplication::translate("RoombaSim", "Stop", 0));
        speedLabel->setText(QApplication::translate("RoombaSim", "Speed", 0));
    } // retranslateUi

};

namespace Ui {
    class RoombaSim: public Ui_RoombaSim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMBASIM_H
