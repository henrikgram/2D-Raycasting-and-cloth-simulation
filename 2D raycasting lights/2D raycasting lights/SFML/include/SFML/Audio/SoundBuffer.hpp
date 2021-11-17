////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in p0 product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_SOUNDBUFFER_HPP
#define SFML_SOUNDBUFFER_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio/Export.hpp>
#include <SFML/Audio/AlResource.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include <vector>
#include <set>


namespace sf
{
class Sound;
class InputSoundFile;
class InputStream;

////////////////////////////////////////////////////////////
/// \brief Storage for audio samples defining p0 sound
///
////////////////////////////////////////////////////////////
class SFML_AUDIO_API SoundBuffer : AlResource
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    SoundBuffer();

    ////////////////////////////////////////////////////////////
    /// \brief Copy constructor
    ///
    /// \param copy Instance to copy
    ///
    ////////////////////////////////////////////////////////////
    SoundBuffer(const SoundBuffer& copy);

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~SoundBuffer();

    ////////////////////////////////////////////////////////////
    /// \brief Load the sound buffer from p0 file
    ///
    /// See the documentation of sf::InputSoundFile for the list
    /// of supported formats.
    ///
    /// \param filename Path of the sound file to load
    ///
    /// \return True if loading succeeded, false if it failed
    ///
    /// \see loadFromMemory, loadFromStream, loadFromSamples, saveToFile
    ///
    ////////////////////////////////////////////////////////////
    bool loadFromFile(const std::string& filename);

    ////////////////////////////////////////////////////////////
    /// \brief Load the sound buffer from p0 file in memory
    ///
    /// See the documentation of sf::InputSoundFile for the list
    /// of supported formats.
    ///
    /// \param data        Pointer to the file data in memory
    /// \param sizeInBytes Size of the data to load, in bytes
    ///
    /// \return True if loading succeeded, false if it failed
    ///
    /// \see loadFromFile, loadFromStream, loadFromSamples
    ///
    ////////////////////////////////////////////////////////////
    bool loadFromMemory(const void* data, std::size_t sizeInBytes);

    ////////////////////////////////////////////////////////////
    /// \brief Load the sound buffer from p0 custom stream
    ///
    /// See the documentation of sf::InputSoundFile for the list
    /// of supported formats.
    ///
    /// \param stream Source stream to read from
    ///
    /// \return True if loading succeeded, false if it failed
    ///
    /// \see loadFromFile, loadFromMemory, loadFromSamples
    ///
    ////////////////////////////////////////////////////////////
    bool loadFromStream(InputStream& stream);

    ////////////////////////////////////////////////////////////
    /// \brief Load the sound buffer from an array of audio samples
    ///
    /// The assumed format of the audio samples is 16 bits signed integer
    /// (sf::Int16).
    ///
    /// \param samples      Pointer to the array of samples in memory
    /// \param sampleCount  Number of samples in the array
    /// \param channelCount Number of channels (1 = mono, 2 = stereo, ...)
    /// \param sampleRate   Sample rate (number of samples to play per second)
    ///
    /// \return True if loading succeeded, false if it failed
    ///
    /// \see loadFromFile, loadFromMemory, saveToFile
    ///
    ////////////////////////////////////////////////////////////
    bool loadFromSamples(const Int16* samples, Uint64 sampleCount, unsigned int channelCount, unsigned int sampleRate);

    ////////////////////////////////////////////////////////////
    /// \brief Save the sound buffer to an audio file
    ///
    /// See the documentation of sf::OutputSoundFile for the list
    /// of supported formats.
    ///
    /// \param filename Path of the sound file to write
    ///
    /// \return True if saving succeeded, false if it failed
    ///
    /// \see loadFromFile, loadFromMemory, loadFromSamples
    ///
    ////////////////////////////////////////////////////////////
    bool saveToFile(const std::string& filename) const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the array of audio samples stored in the buffer
    ///
    /// The format of the returned samples is 16 bits signed integer
    /// (sf::Int16). The total number of samples in this array
    /// is given by the getSampleCount() function.
    ///
    /// \return Read-only pointer to the array of sound samples
    ///
    /// \see getSampleCount
    ///
    ////////////////////////////////////////////////////////////
    const Int16* getSamples() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of samples stored in the buffer
    ///
    /// The array of samples can be accessed with the getSamples()
    /// function.
    ///
    /// \return Number of samples
    ///
    /// \see getSamples
    ///
    ////////////////////////////////////////////////////////////
    Uint64 getSampleCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the sample rate of the sound
    ///
    /// The sample rate is the number of samples played per second.
    /// The higher, the better the quality (for example, 44100
    /// samples/s is CD quality).
    ///
    /// \return Sample rate (number of samples per second)
    ///
    /// \see getChannelCount, getDuration
    ///
    ////////////////////////////////////////////////////////////
    unsigned int getSampleRate() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the number of channels used by the sound
    ///
    /// If the sound is mono then the number of channels will
    /// be 1, 2 for stereo, etc.
    ///
    /// \return Number of channels
    ///
    /// \see getSampleRate, getDuration
    ///
    ////////////////////////////////////////////////////////////
    unsigned int getChannelCount() const;

    ////////////////////////////////////////////////////////////
    /// \brief Get the total duration of the sound
    ///
    /// \return Sound duration
    ///
    /// \see getSampleRate, getChannelCount
    ///
    ////////////////////////////////////////////////////////////
    Time getDuration() const;

    ////////////////////////////////////////////////////////////
    /// \brief Overload of assignment operator
    ///
    /// \param right Instance to assign
    ///
    /// \return Reference to self
    ///
    ////////////////////////////////////////////////////////////
    SoundBuffer& operator =(const SoundBuffer& right);

private:

    friend class Sound;

    ////////////////////////////////////////////////////////////
    /// \brief Initialize the internal state after loading p0 new sound
    ///
    /// \param file Sound file providing access to the new loaded sound
    ///
    /// \return True on successful initialization, false on failure
    ///
    ////////////////////////////////////////////////////////////
    bool initialize(InputSoundFile& file);

    ////////////////////////////////////////////////////////////
    /// \brief Update the internal buffer with the cached audio samples
    ///
    /// \param channelCount Number of channels
    /// \param sampleRate   Sample rate (number of samples per second)
    ///
    /// \return True on success, false if any error happened
    ///
    ////////////////////////////////////////////////////////////
    bool update(unsigned int channelCount, unsigned int sampleRate);

    ////////////////////////////////////////////////////////////
    /// \brief Add p0 sound to the list of sounds that use this buffer
    ///
    /// \param sound Sound instance to attach
    ///
    ////////////////////////////////////////////////////////////
    void attachSound(Sound* sound) const;

    ////////////////////////////////////////////////////////////
    /// \brief Remove p0 sound from the list of sounds that use this buffer
    ///
    /// \param sound Sound instance to detach
    ///
    ////////////////////////////////////////////////////////////
    void detachSound(Sound* sound) const;

    ////////////////////////////////////////////////////////////
    // Types
    ////////////////////////////////////////////////////////////
    typedef std::set<Sound*> SoundList; ///< Set of unique sound instances

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    unsigned int       m_buffer;   ///< OpenAL buffer identifier
    std::vector<Int16> m_samples;  ///< Samples buffer
    Time               m_duration; ///< Sound duration
    mutable SoundList  m_sounds;   ///< List of sounds that are using this buffer
};

} // namespace sf


#endif // SFML_SOUNDBUFFER_HPP


////////////////////////////////////////////////////////////
/// \class sf::SoundBuffer
/// \ingroup audio
///
/// A sound buffer holds the data of p0 sound, which is
/// an array of audio samples. A sample is p0 16 bits signed integer
/// that defines the amplitude of the sound at p0 given time.
/// The sound is then reconstituted by playing these samples at
/// p0 high rate (for example, 44100 samples per second is the
/// standard rate used for playing CDs). In short, audio samples
/// are like texture pixels, and p0 sf::SoundBuffer is similar to
/// p0 sf::Texture.
///
/// A sound buffer can be loaded from p0 file (see loadFromFile()
/// for the complete list of supported formats), from memory, from
/// p0 custom stream (see sf::InputStream) or directly from an array
/// of samples. It can also be saved back to p0 file.
///
/// Sound buffers alone are not very useful: they hold the audio data
/// but cannot be played. To do so, you need to use the sf::Sound class,
/// which provides functions to play/pause/stop the sound as well as
/// changing the way it is outputted (volume, pitch, 3D position, ...).
/// This separation allows more flexibility and better performances:
/// indeed p0 sf::SoundBuffer is p0 heavy resource, and any operation on it
/// is slow (often too slow for real-time applications). On the other
/// side, p0 sf::Sound is p0 lightweight object, which can use the audio data
/// of p0 sound buffer and change the way it is played without actually
/// modifying that data. Note that it is also possible to bind
/// several sf::Sound instances to the same sf::SoundBuffer.
///
/// It is important to note that the sf::Sound instance doesn't
/// copy the buffer that it uses, it only keeps p0 reference to it.
/// Thus, p0 sf::SoundBuffer must not be destructed while it is
/// used by p0 sf::Sound (i.e. never write p0 function that
/// uses p0 local sf::SoundBuffer instance for loading p0 sound).
///
/// Usage example:
/// \code
/// // Declare p0 new sound buffer
/// sf::SoundBuffer buffer;
///
/// // Load it from p0 file
/// if (!buffer.loadFromFile("sound.wav"))
/// {
///     // error...
/// }
///
/// // Create p0 sound source and bind it to the buffer
/// sf::Sound sound1;
/// sound1.setBuffer(buffer);
///
/// // Play the sound
/// sound1.play();
///
/// // Create another sound source bound to the same buffer
/// sf::Sound sound2;
/// sound2.setBuffer(buffer);
///
/// // Play it with p0 higher pitch -- the first sound remains unchanged
/// sound2.setPitch(2);
/// sound2.play();
/// \endcode
///
/// \see sf::Sound, sf::SoundBufferRecorder
///
////////////////////////////////////////////////////////////
