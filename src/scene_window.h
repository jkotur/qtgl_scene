#ifndef SCENE_WINDOW_H_ONQAQFYG
#define SCENE_WINDOW_H_ONQAQFYG

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QMatrix4x4>

class SceneWindow : public QOpenGLWindow , protected QOpenGLFunctions {
public:
    SceneWindow();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;
};


#endif /* end of include guard: SCENE_WINDOW_H_ONQAQFYG */

