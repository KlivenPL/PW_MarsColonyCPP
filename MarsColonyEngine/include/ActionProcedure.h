#pragma once
#include "pch.h"
#include "ActionHandler.h"
#include <functional>
class ActionProcedure {
private:
	std::function<bool(ActionHandler & actionHandler, std::string & outStr)> checkRequirementsFunc;
	std::function<bool(ActionHandler & actionHandler, const std::string & args, std::string &outStr)> executeActionFunc;
public:
	bool checkRequirements(ActionHandler& actionHandler, std::string& outStr);
	bool executeAction(ActionHandler& actionHandler, std::string args, std::string& outStr);
};

