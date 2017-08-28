#include "MIDI_Input_Element.h"

MIDI_Input_Element_CC::MIDI_Input_Element_CC(uint8_t address, uint8_t channel, uint8_t nb_addresses, uint8_t nb_channels)
    : address(address), channel(channel - 1), nb_addresses(nb_addresses), nb_channels(nb_channels)
{
    INSERT_INTO_LINKED_LIST(this, first, last);
}
MIDI_Input_Element_CC::~MIDI_Input_Element_CC()
{
    DELETE_FROM_LINKED_LIST(this, first, last);
}

bool MIDI_Input_Element_CC::update(uint8_t targetAddress, uint8_t targetChannel)
{
    if (!match(targetAddress, targetChannel))
        return false;
    if (!updateImpl(targetAddress, targetChannel))
        return false;
    return true;
}

MIDI_Input_Element_CC *MIDI_Input_Element_CC::getFirst() 
{
    return first;
}
MIDI_Input_Element_CC *MIDI_Input_Element_CC::getNext()
{
    return next;
}

inline bool MIDI_Input_Element_CC::match(uint8_t targetAddress, uint8_t targetChannel)
{
    return 
       (targetAddress >= this->address) 
    && (targetAddress < this->address + nb_addresses) 
    && (targetChannel >= this->channel) 
    && (targetChannel < this->channel + nb_channels);
}

MIDI_Input_Element_CC *MIDI_Input_Element_CC::last = nullptr;
MIDI_Input_Element_CC *MIDI_Input_Element_CC::first = nullptr;

//----------------------------------------------------------------------------------------------------------------------------------------//

MIDI_Input_Element_Note::MIDI_Input_Element_Note(uint8_t address, uint8_t channel, uint8_t nb_addresses, uint8_t nb_channels)
    : address(address), channel(channel - 1), nb_addresses(nb_addresses), nb_channels(nb_channels)
{
    INSERT_INTO_LINKED_LIST(this, first, last);
}
MIDI_Input_Element_Note::~MIDI_Input_Element_Note()
{
    DELETE_FROM_LINKED_LIST(this, first, last);
}

bool MIDI_Input_Element_Note::update(uint8_t messageType, uint8_t targetAddress, uint8_t targetChannel)
{
    if (!match(targetAddress, targetChannel))
        return false;
    if (!updateImpl(messageType, targetAddress, targetChannel))
        return false;
    return true;
}

MIDI_Input_Element_Note *MIDI_Input_Element_Note::getFirst() 
{
    return first;
}
MIDI_Input_Element_Note *MIDI_Input_Element_Note::getNext()
{
    return next;
}

inline bool MIDI_Input_Element_Note::match(uint8_t targetAddress, uint8_t targetChannel)
{
    return 
       (targetAddress >= this->address) 
    && (targetAddress < this->address + nb_addresses) 
    && (targetChannel >= this->channel) 
    && (targetChannel < this->channel + nb_channels);
}

MIDI_Input_Element_Note *MIDI_Input_Element_Note::last = nullptr;
MIDI_Input_Element_Note *MIDI_Input_Element_Note::first = nullptr;

//----------------------------------------------------------------------------------------------------------------------------------------//

MIDI_Input_Element_ChannelPressure::MIDI_Input_Element_ChannelPressure(uint8_t channel, uint8_t nb_channels)
    : channel(channel - 1), nb_channels(nb_channels)
{
    INSERT_INTO_LINKED_LIST(this, first, last);
}
MIDI_Input_Element_ChannelPressure::~MIDI_Input_Element_ChannelPressure()
{
    DELETE_FROM_LINKED_LIST(this, first, last);
}

bool MIDI_Input_Element_ChannelPressure::update(uint8_t targetChannel, uint8_t data1)
{
    if (!match(targetChannel))
        return false;
    if (!updateImpl(targetChannel, data1))
        return false;
    return true;
}

MIDI_Input_Element_ChannelPressure *MIDI_Input_Element_ChannelPressure::getFirst() 
{
    return first;
}
MIDI_Input_Element_ChannelPressure *MIDI_Input_Element_ChannelPressure::getNext()
{
    return next;
}

inline bool MIDI_Input_Element_ChannelPressure::match(uint8_t targetChannel)
{
    return 
       (targetChannel >= this->channel) 
    && (targetChannel < this->channel + nb_channels);
}

MIDI_Input_Element_ChannelPressure *MIDI_Input_Element_ChannelPressure::last = nullptr;
MIDI_Input_Element_ChannelPressure *MIDI_Input_Element_ChannelPressure::first = nullptr;

//----------------------------------------------------------------------------------------------------------------------------------------//