#ifndef GUI_H
#define GUI_H

#include "ui_gui.h"

class Gui : public QWidget, private Ui::Gui
{
    Q_OBJECT

public:
    explicit Gui(QWidget *parent = nullptr);
private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_blinkButton_clicked(bool checked);
    void on_lauflichtButton_clicked(bool checked);
};

#endif // GUI_H
