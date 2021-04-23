#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include <mutex>
#include "IDrawable.h"

using namespace std;

class Window {
    public:
        Window();
        ~Window();

        void addElement(IDrawable * element, unsigned int yPosition, unsigned int xPosition);
        void run();

    private:
        void graphicsLoop();
        void updateLoop();
        void notifyLoop();
        
        bool exit();
        void shutDown();

    private:
        vector<IDrawable*> m_elements;
        int m_numOfRows;
        int m_numOfColumns;
        mutex m_mutex_exit;
        bool m_exit;
};

#endif