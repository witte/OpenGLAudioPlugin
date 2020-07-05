#include "OpenGLComponent.h"

OpenGLComponent::OpenGLComponent()
{
    openGLContext.setRenderer (this);
    openGLContext.attachTo (*this);
}

OpenGLComponent::~OpenGLComponent()
{
    openGLContext.detach();
}

void OpenGLComponent::newOpenGLContextCreated() {}

void OpenGLComponent::renderOpenGL() {}

void OpenGLComponent::openGLContextClosing() {}
