/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
*/



#pragma once


namespace clan
{
/// \addtogroup clanCore_System clanCore System
/// \{

/// \brief OS level event provider.
class EventProvider
{
/// \name Construction
/// \{

public:
	virtual ~EventProvider() { return; }


/// \}
/// \name Attributes
/// \{

public:
#ifdef WIN32
	enum EventType
	{
		type_native
	};
#else
	enum EventType
	{
		type_fd_read,
		type_fd_write,
		type_fd_exception
	};
#endif

	/// \brief Returns the type of event provided.
	virtual EventType get_event_type(int index) = 0;

#ifdef WIN32
	/// \brief Returns the OS handle for the event.
	virtual HANDLE get_event_handle(int index) = 0;
#else
	/// \brief Returns the OS handle for the event.
	virtual int get_event_handle(int index) = 0;
#endif

	/// \brief Returns the number of OS handles relevant for this event.
	virtual int get_num_event_handles() = 0;


/// \}
/// \name Operations
/// \{

public:
	/// \brief Prepare for OS event waiting.
	virtual bool check_before_wait() { return false; }

	/// \brief Check for flagging after OS event waiting.
	virtual bool check_after_wait(int /*index*/) { return true; }

	/// \brief Raise flag.
	virtual bool set() { return false; }

	/// \brief Reset flag.
	virtual bool reset() { return false; }


/// \}
/// \name Implementation
/// \{

private:
/// \}
};

}

/// \}
