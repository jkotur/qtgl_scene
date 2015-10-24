#ifndef SCENE_WINDOW_H_ONQAQFYG
#define SCENE_WINDOW_H_ONQAQFYG

#include <QOpenGLWindow>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>

#include "data.h"

class SceneWindow : public QOpenGLWindow , protected QOpenGLFunctions {
public:
    SceneWindow( const Data& data );

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;

    const Data& data;

    QOpenGLShaderProgram* m_program;

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;
};


#endif /* end of include guard: SCENE_WINDOW_H_ONQAQFYG */

