#include "mainwindow.h"
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <qDebug>
#include <QBitArray>
#include <QPushButton>
#include <QBoxLayout>
#include <QWidget>
#include <QtWidgets>
#include <QLCDNumber>
#include <QCheckBox>
#include <QDebug>
#include <QApplication>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QDebug>


class A : public  QWidget
{
QLCDNumber *  m_plcd;

QGridLayout* pgrdLayout;
public :
A() : QWidget()
{

pgrdLayout = new QGridLayout;
m_plcd = new QLCDNumber(12);
m_plcd->setSegmentStyle(QLCDNumber::Flat);
m_plcd->setMinimumSize(150, 50);
pgrdLayout->addWidget(m_plcd, 0, 0, 1, 4);
pgrdLayout->addWidget(creatbtn ("6"), 1, 0, 1, 4);
m_plcd->display("0");
setLayout(pgrdLayout);

}

QPushButton* creatbtn (const QString& str)
{
    QPushButton* pcmdA;
    pcmdA = new QPushButton (str);
   // QObject::connect(pcmdA, SIGNAL(clicked()),  this,  SLOT(pressed()));
    connect(pcmdA, SIGNAL(clicked()), SLOT(pressed()));
    return pcmdA;
}

public slots:
void pressed ();
};

void A :: pressed ()
{
   // QString str = ((QPushButton*)sender())->text();
    QPushButton *s = (QPushButton*)sender();
    QString str = s->text();
    m_plcd->display(str);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  A aob;
  aob.show();
  return app.exec();
}

/*
void messageToFile(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
QFile file("protocol.log");
if(!file.open(QIODevice :: WriteOnly | QIODevice :: Text | QIODevice::Append))
{
qDebug()<<"file not found\n";
return;
}
QString strDateTime = QDateTime :: currentDateTime().toString ( "dd.ММ. yy-hh:mm");
qDebug()<<"strDateTime\n";
QTextStream out(&file);
switch (type) {
case QtDebugMsg:
out << strDateTime << "Debug: " << msg<< ", " << context.file << endl;
break;
case QtWarningMsg:
out << strDateTime << "Warning: " << msg<< ", " << context.file << endl;
break;
case QtCriticalMsg:
out << strDateTime << "Critical: " << msg<< ", " << context.file << endl;
break;
case QtFatalMsg:
out << strDateTime << "Fatal: " << msg<< ", " << context. file << endl;
abort ();
}
}

int main(int argc, char** argv)
{
QApplication app(argc, argv);
//qInstallMessageHandler(messageToFile);
qInstallMessageHandler(0);
qDebug()<<"hello world\n";
qDebug()<<qBound(2, 12, 7);
return app.exec();
}
*/


/*
class Window: public QWidget
{
public:
  Window() : QWidget()
  {
    QVBoxLayout* layout = new QVBoxLayout();
    for (int i=0; i < 10; ++i)
    {
      QCheckBox* checkBox = new QCheckBox(this);
      checkBox->setObjectName("check" + QString::number(i));
      layout->addWidget(checkBox);
      connect(checkBox, &QCheckBox::toggled, this, &Window::toggled);
    }
    setLayout(layout);
  }
  void toggled(bool)
  {
    qDebug() << QObject::sender()->objectName();
  }
};

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Window window;
  window.show();
  return app.exec();
}
*/
/*
class QLCDNumber;

class QPushButton;

int main(int argc, char** argv )
{
QApplication app(argc, argv);

QWidget wgt;

QPushButton* pcmdA = new QPushButton ("А");
QGridLayout* pgrdLayout = new QGridLayout;
//pgrdLayout->setContentsMargins(5, 5, 5, 5);
//pgrdLayout->setSpacing(15);
pgrdLayout->addWidget(pcmdA, 0, 0);
wgt.setLayout(pgrdLayout);
//QString str = ((QPushButton*)sender())->text();

QLCDNumber*     m_plcd;
m_plcd = new QLCDNumber(12);
m_plcd->setSegmentStyle(QLCDNumber::Flat);
m_plcd->setMinimumSize(150, 50);
pgrdLayout->addWidget(m_plcd, 0, 0, 1, 4);
QString str = ((QPushButton*)sender())->text();
m_plcd->display("123");

wgt.show();
return app.exec();
}
*/


/*
int main(int argc, char** argv )
{
QApplication app(argc, argv);
QWidget wgt;
QPushButton* pcmdA = new QPushButton ("А");
QPushButton* pcmdB = new QPushButton("B");
QPushButton* pcmdC = new QPushButton ( "С") ;
QPushButton* pcmdD = new QPushButton ( "D") ;
QGridLayout* pgrdLayout = new QGridLayout;
pgrdLayout->setContentsMargins(5, 5, 5, 5);
pgrdLayout->setSpacing(15);
pgrdLayout->addWidget(pcmdA, 0, 0);
pgrdLayout->addWidget(pcmdB, 0, 1);
pgrdLayout->addWidget(pcmdC, 1, 0);
pgrdLayout->addWidget(pcmdD, 1, 1) ;
wgt.setLayout(pgrdLayout);
wgt.show();
return app.exec();
}
*/
/*
int main(int argc, char** argv)
{
QApplication app(argc, argv);
QWidget wgt;
QPushButton * pcmdA = new QPushButton("A");
QPushButton* pcmdB = new QPushButton("B");
QPushButton* pcmdC = new QPushButton("C");
QPushButton* pcmdD = new QPushButton ( "D") ;
//Layout setup
QVBoxLayout* pvbxLayout = new QVBoxLayout;
QHBoxLayout* phbxLayout = new QHBoxLayout;
phbxLayout->setContentsMargins(5, 5, 5, 5);
phbxLayout->setSpacing(15);
phbxLayout->addWidget(pcmdC);
phbxLayout->addWidget(pcmdD);
pvbxLayout->setContentsMargins(5, 5, 5, 5);
pvbxLayout->setSpacing(15);
pvbxLayout->addWidget(pcmdA);
pvbxLayout->addWidget(pcmdB);
phbxLayout->addLayout(pvbxLayout);  //pvbxLayout->addLayout(phbxLayout);
wgt.setLayout(phbxLayout);          //wgt.setLayout(pvbxLayout);
wgt.show () ;
return app.exec();
}
*/

/*
int main(int argc, char** argv)
{
QApplication app(argc, argv);
QWidget wgt;
QPushButton * pcmdA = new QPushButton("A");
QPushButton* pcmdB = new QPushButton("B");
QPushButton* pcmdC = new QPushButton("C");
//Layout setup
QHBoxLayout * phbxLayout = new QHBoxLayout;
phbxLayout->setContentsMargins(10, 10, 10, 10);
phbxLayout->setSpacing(20);
phbxLayout->addWidget(pcmdA);
phbxLayout->addWidget(pcmdB);
phbxLayout->addWidget(pcmdC);
wgt.setLayout(phbxLayout);
wgt.show () ;
return app.exec();
}
*/
/*
int main(int argc, char** argv)
{
QApplication app(argc, argv);
QWidget wgt;
QPushButton * pcmdA = new QPushButton("A");
QPushButton* pcmdB = new QPushButton("B");
//QPushButton* pcmdC = new QPushButton("C");
//Layout setup
QBoxLayout * pbxLayout = new QBoxLayout(QBoxLayout :: LeftToRight);
pbxLayout->addWidget(pcmdA, 1);
pbxLayout->addStretch(1);
pbxLayout->addWidget(pcmdB, 2);
//pbxLayout->addWidget(pcmdC, 3);
wgt.setLayout(pbxLayout);
wgt.resize(450, 40);
wgt.show () ;
return app.exec();
}
*/
/*
int main(int argc, char** argv)
{
QApplication app(argc, argv);
QWidget wgt;
QPixmap pix (": /clock .png") ;
QCursor cur (pix);
wgt.setCursor(cur);
wgt.resize(180, 100);
wgt.show();
return app.exec();
}
*/
/*
#include <QtWidgets>
int main(int argc, char ** argv)
{
QApplication app (argc , argv) ;
QWidget wgt;
QWidget* pwgtl = new QWidget ( &wgt);
QPalette pall;
pall.setColor(pwgtl->backgroundRole( ) , Qt :: blue);
pwgtl->setPalette (pall);
pwgtl->resize(100, 100);
pwgtl->move (25, 25);
pwgtl->setAutoFillBackground (true) ;
//QWidget* pwgt2 = new QWidget(&wgt ) ;
//QPalette pal2 ;
//pal2. setBrush (pwgt2->backgroundRole () , QBrush (QPixmap (": / stone.jpg"))) ;
//pwgt2->setPalette(pal2);
//pwgt2->resize(100, 100);
//pwgt2->move(75, 75);
//pwgt2->setAutoFillBackground(true);
//wgt.resize(200, 200);
wgt.show ( ) ;
return app.exec();
}
*/
/*
int main(int argc, char** argv)
{
QByteArray a = "Test Data";
QByteArray aCompressed = qCompress(a);
qDebug() << qUncompress(aCompressed)<<endl;

QByteArray a2 = "Test Data";
QByteArray aBase64 = a2.toBase64();
qDebug() << aBase64<<endl;
qDebug() << QByteArray::fromBase64(aBase64)<<endl;

QBitArray bits(3);
bits[0] = bits[1] = true;
bits[2] = false;
qDebug()<<bits<<endl;
}
*/

/*
int main(int argc, char** argv)
{
qDebug()<<qBound(9, 12, 7);
}
*/
