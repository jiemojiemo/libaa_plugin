project(LibAAGain_PLUGIN VERSION 0.0.1)

juce_add_plugin(
        LibAAGain
        PLUGIN_MANUFACTURER_CODE LIBA
        PLUGIN_CODE LibAAGain
        FORMATS VST3
        PRODUCT_NAME "LibAAGain"
)

target_sources(LibAAGain
        PRIVATE
        PluginProcessor.cpp)

target_compile_definitions(LibAAGain
        PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(LibAAGain
        PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
        libaa
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)