#pragma once
#include "pch.h"

class ActionHandler {
protected:
	virtual std::string getActionHandlerName() const = 0;
};

