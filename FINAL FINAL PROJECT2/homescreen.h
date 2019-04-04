#ifndef HOMESCREEN_H
#define HOMESCREEN_H


#include <QWidget>

/**
 * @class MainScreen
 * @brief The MainScreen class reprsents the initial screen that is shown when the program starts.
 *
 * This screen houses the gameplay instructions and a play button which will actually launch
 * an instance of the GameView class.
 */

class HomeScreen: public QWidget{
    Q_OBJECT
public:
    HomeScreen(QWidget * parent=0);
public slots:
    /**
     * @brief initializes and displays an instance of the GameView class
     */
    void play();
};

#endif // HOMESCREEN_H
