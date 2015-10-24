#include "scene_window.h"

static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colAttr;\n"
    "varying lowp vec4 col;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   col = colAttr;\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 col;\n"
    "void main() {\n"
    "   gl_FragColor = col;\n"
    "}\n";

SceneWindow::SceneWindow( const Data& data )
    : data(data)
{
    auto f = format();
    f.setSwapInterval(1);
    setFormat( f );
}

void SceneWindow::initializeGL()
{
    initializeOpenGLFunctions();

    m_camera.setToIdentity();
    m_camera.translate(0, 0, -1);

    m_world.setToIdentity();

    glClearColor(0.2, 0.2, 0.2, 1);

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");
}

void SceneWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_program->bind();

    // TODO: multiply by world matrix
    m_program->setUniformValue(m_matrixUniform, m_proj);

    std::vector<GLfloat> vertices;
    std::vector<GLfloat> colors;

    vertices.reserve( 2 * data.lines.size() );
    colors  .reserve( 3 * data.lines.size() );

    data.mutex.lock();
    for( auto& p : data.lines )
    {
        vertices.push_back( p.x );
        vertices.push_back( p.y );

        colors.push_back( p.c.r );
        colors.push_back( p.c.g );
        colors.push_back( p.c.b );
    }
    data.mutex.unlock();

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.data());
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors  .data());

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_LINE_STRIP, 0, data.lines.size());

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);

    m_program->release();

    update();
}

void SceneWindow::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );

    m_proj.setToIdentity();
    m_proj.ortho( 0, 10, -2, 2, -10, 10);
}

