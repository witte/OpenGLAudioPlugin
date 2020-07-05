JUCE test project to show problem with OpenGL component on Linux VST3.

## Building
```
git clone https://github.com/witte/OpenGLAudioPlugin.git --recurse-submodules
cd OpenGLAudioPlugin
cmake -S . -B build
cmake --build build
```

## Reproducing
```
- compile the plugin
- open a plugin host (Juce's AudioPluginHost, Bitwig, Reaper)
- load the plugin
- open the plugin's editor
- close the plugin's editor
- open the plugin's editor again (doesn't happen every time)
```

You'll get these two error messages before the host crashes:
```
ERROR: X returned BadWindow (invalid Window parameter) for operation X_UnmapWindow
ERROR: X returned BadWindow (invalid Window parameter) for operation X_DestroyWindow
```

The SIGSEGV happens at: `JUCE/modules/juce_gui_basics/native/x11/juce_linux_XWindowSystem.cpp` at line `3358`

You'll get the same two error messages (but no crash) when unloading the plugin if you've only opened the editor once.

