#pragma once

using namespace System;
using namespace System::Runtime::Serialization;

[Serializable]
public ref class Message
{
public:
	enum class MsgType
	{
		MSG_TYPE_NONE,
		MSG_TYPE_PING,
		MSG_TYPE_LBDOWN, //Left mouse down
		MSG_TYPE_LBUP,	//Left mouse up
		MSG_TYPE_RBDOWN,	//Right mouse down
		MSG_TYPE_RBUP,	//Right mouse up
		MSG_TYPE_DOUBLECLICK,
		MSG_TYPE_KBDOWN,	//Keyboard button down
		MSG_TYPE_KBUP	//Keyboard button up
	};

	Message(MsgType msg)
	{
		MessageType = msg;
		data = gcnew array<int> {};
	}

	Message(MsgType msg, array<int>^ dat)
	{
		MessageType = msg;
		data = dat;
	}

	Message(SerializationInfo^ info, StreamingContext ctxt)
	{
		MessageType = (MsgType)info->GetValue("MessageType", MsgType::typeid);
		data = (array<int>^)info->GetValue("Data", array<int>::typeid);
	}

	virtual void GetObjectData(SerializationInfo^ info, StreamingContext context)
	{
		info->AddValue("MessageType", MessageType);
		info->AddValue("Data", data);
	}

	MsgType GetMessage()
	{
		return MessageType;
	}

	array<int>^ GetData() { return data; }
private:
	MsgType MessageType;
	array<int>^ data;
};