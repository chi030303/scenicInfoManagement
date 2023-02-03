#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void on_recommendpath_clicked();

    void on_recommend_clicked();

    void on_spotguide_clicked();

    void on_info_clicked();

    void drawline(int x1,int y1,int x2,int y2, QColor const c);

    void on_display_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap pix;
};
#endif // MAINWINDOW_H
