"""
    Fast Fourier Transform gives us frequency, amplitude and time.
"""
import numpy
from scipy.fftpack import fft
from scipy.io import wavfile

from RawDataset.python.utilities import normalise_to_range_of_one, get_first_sound_channel, make_plot

KHZ_IN_HZ: int = 1000


def make_fft_array_of_length(sound_channel: numpy.ndarray):
    fft_array: numpy.ndarray = fft(sound_channel)
    # All array is to large to handle, so we need to take only half of it
    half_length: int = int(soundLength / 2)

    return fft_array[0:half_length]


# FFT contains both magnitude and phase. It is given in complex numbers (a + ib) format.
def get_real_from_complex(half_of_fft_array: numpy.ndarray): return abs(half_of_fft_array)


# To make magnitude independent of signal length or its sampling frequency
def scale_by(real_part_fft_array: numpy.ndarray, sound_length: int): return real_part_fft_array / sound_length


def calculate_step_frequency(sampling_freq: int, sound_length: int):
    half_sound_length: int = int(sound_length / 2)
    fft_step_array: numpy.ndarray = numpy.arange(half_sound_length)
    step_delta: float = sampling_freq / sound_length

    return fft_step_array * step_delta


def plot_fft(step_freq_array_hz: numpy.ndarray, fft_array: numpy.ndarray):
    step_freq_array_khz: numpy.ndarray = step_freq_array_hz / KHZ_IN_HZ
    power_db: numpy.ndarray = 10 * numpy.log10(fft_array)
    make_plot('Frequency (Khz)', step_freq_array_khz, 'Power (dB)', power_db, color='B')


wavAudioFilePath: str = "../resourses/track_sample.wav"

# Sampling frequency must be 44100 Hz.
samplingFreq: int
soundArray: numpy.ndarray
samplingFreq, soundArray = wavfile.read(wavAudioFilePath)

normalisedSoundArray: numpy.ndarray = normalise_to_range_of_one(soundArray)

soundLength: int = len(normalisedSoundArray)

soundChannel: numpy.ndarray = get_first_sound_channel(normalisedSoundArray)

fftArray: numpy.ndarray = make_fft_array_of_length(soundChannel)
realPartFftArray: numpy.ndarray = get_real_from_complex(fftArray)
scaledRealPartFftArray: numpy.ndarray = scale_by(realPartFftArray, soundLength)
stepFreqArrayHz: numpy.ndarray = calculate_step_frequency(samplingFreq, soundLength)
# TODO research why multiply by two?
plot_fft(stepFreqArrayHz, scaledRealPartFftArray * 2)
