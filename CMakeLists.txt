cmake_minimum_required(VERSION 3.15)

project(OpenGLTestPlugin VERSION 0.0.1)

add_subdirectory(JUCE)

juce_add_plugin(OpenGLTestPlugin
    COMPANY_NAME "OpenGLTest"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE Juce
    PLUGIN_CODE Dem0
    FORMATS AU VST3 Standalone
    PRODUCT_NAME "OpenGLTestPlugin")

target_sources(OpenGLTestPlugin PRIVATE
    OpenGLComponent.cpp
    PluginEditor.cpp
    PluginProcessor.cpp)

target_compile_definitions(OpenGLTestPlugin PUBLIC
    JUCE_ENABLE_GPL_MODE=1
    JUCE_DISPLAY_SPLASH_SCREEN=0
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(OpenGLTestPlugin PRIVATE juce::juce_opengl juce::juce_audio_utils)
