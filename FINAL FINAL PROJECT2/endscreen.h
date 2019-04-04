#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QWidget>

class EndScreen: public QWidget{
    Q_OBJECT
public:
    EndScreen(QWidget * parent=0);
public slots:
    /**
     * @brief initializes and displays an instance of the GameView class
     */
    void end();
};

#endif // ENDSCREEN_H
