#include "gui.h"

Gui::Gui(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_leds = new Gpio(this);
    m_status = 0;
    m_timer = new QTimer();
    connect(m_timer, &QTimer::timeout, this, &Gui::toggle);
    m_timer->start(TIMEOUT);
}
void Gui::on_speedSlider_valueChanged(int value)
{
    m_timer->start(1000/value);
}
void Gui::on_blinkButton_clicked()
{
    m_blink = 1;
}
void Gui::on_lauflichtButton_clicked()
{
    m_blink = 0;
    counter = 1;
}
void Gui::toggle()
{
    m_status = !m_status;
    if(m_blink == 1)
    {
         if(m_status == 1)
         {
            counter = 15;
         }
         else
         {
           counter = 0;
         }
         m_leds->set(counter);
    }
    if(m_blink == 0)
    {
         m_leds->set(counter);
         if(counter < 8)
         {
           counter = counter * 2;
         }
         else
         {
           counter = 1;
         }
    }
}
