#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_opengl/juce_opengl.h>

using namespace juce;

class OpenGLComponent : public Component, public OpenGLRenderer
{
    public:
        OpenGLComponent();
        ~OpenGLComponent() override;

        void paint (Graphics&) override {}
        void resized() override {}

        void newOpenGLContextCreated() override;
        void renderOpenGL() override;
        void openGLContextClosing() override;


    private:
        OpenGLContext openGLContext;


        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OpenGLComponent)
};
