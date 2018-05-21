// This is the main DLL file.

#include "stdafx.h"
#include "MouseMove.h"

void MouseMove::GetObjectData(SerializationInfo^ info, StreamingContext context)
{
	info->AddValue("PositionX", x);
	info->AddValue("PositionY", y);
}