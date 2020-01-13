import numpy
import matplotlib.pyplot as plot

from scipy.io import wavfile

from RawDataset.python.utilities import normalise_to_range_of_one, get_first_sound_channel, make_plot

MICROSECONDS_IN_MILLISECONDS: int = 1000


def plote_the_tone(sound_channel: numpy.ndarray, sound_length: int, sampling_freq: int):
    step_array: numpy.ndarray = numpy.arange(sound_length)
    microseconds_step_array: numpy.ndarray = step_array / sampling_freq
    milliseconds_step_array = microseconds_step_array * MICROSECONDS_IN_MILLISECONDS

    make_plot('Time (ms)', milliseconds_step_array, 'Amplitude', sound_channel)
    plot.savefig('foo.png', bbox_inches='tight')

wavAudioFilePath: str = "../resourses/track_sample.wav"

# Sampling frequency must be 44100 Hz.
samplingFreq: int
soundArray: numpy.ndarray
samplingFreq, soundArray = wavfile.read(wavAudioFilePath)

normalisedSoundArray: numpy.ndarray = normalise_to_range_of_one(soundArray)
soundLength: int = len(normalisedSoundArray)

soundChannel: numpy.ndarray = get_first_sound_channel(normalisedSoundArray)

plote_the_tone(soundChannel, soundLength, samplingFreq)
