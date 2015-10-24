#include "scene_window.h"

SceneWindow::SceneWindow()
{
}

void SceneWindow::initializeGL()
{
    initializeOpenGLFunctions();

    m_camera.setToIdentity();
    m_camera.translate(0, 0, -1);

    m_world.setToIdentity();

    glClearColor(0.2, 0.2, 0.2, 1);
}

void SceneWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void SceneWindow::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );

    m_proj.setToIdentity();
    m_proj.ortho( 0, 0, w, h, -10, 10);
}

