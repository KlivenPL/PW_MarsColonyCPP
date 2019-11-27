#pragma once
#include "pch.h"


class IActionHandler {
protected:
	virtual std::string getActionHandlerName() const = 0;
	virtual void registerActions() = 0;
public:
	friend class Action;
	friend class ActionProcedure;
};

