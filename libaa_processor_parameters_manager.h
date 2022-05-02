//
// Created by user on 3/25/22.
//

#ifndef AUDIOEFFECT_PLUGINS_AUDIO_EFFECT_PROCESSOR_PARAMETERS_MANAGER_H
#define AUDIOEFFECT_PLUGINS_AUDIO_EFFECT_PROCESSOR_PARAMETERS_MANAGER_H

class AudioEffectProcessorParametersManager {
public:
  AudioEffectProcessorParametersManager(libaa::IAudioProcessor &p)
      : proc(p) {
    auto *audio_effect_params = proc.getParameters();
    size_t num_params =
        (audio_effect_params == nullptr) ? (0) : (audio_effect_params->size());

    params.resize(num_params, nullptr);
    for (int i = 0; i < num_params; ++i) {
      auto& p = audio_effect_params->get(i);
      auto param_type = p.getParameterType();
      auto param_name = p.getParameterName();
      if(param_type == libaa::ParameterType::kFloat){
        auto v = p.getPlainValue();
        auto min_v = p.getMinPlainValue();
        auto max_v = p.getMaxPlainValue();

        params[i] = new juce::AudioParameterFloat(param_name, param_name, min_v,
                                                  max_v, v);

      }else if(param_type == libaa::ParameterType::kChoice){
        int default_index = p.getInt();
        juce::StringArray choices;
        for(const auto& c : p.getChoiceStrings()){
          choices.add(c);
        }
        params[i] = new juce::AudioParameterChoice(param_name, param_name, choices,default_index);
      }
    }
  }

  libaa::IAudioProcessor &proc;
  std::vector<juce::RangedAudioParameter *> params;
};


#endif // AUDIOEFFECT_PLUGINS_AUDIO_EFFECT_PROCESSOR_PARAMETERS_MANAGER_H
