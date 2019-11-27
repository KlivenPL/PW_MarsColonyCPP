#pragma once
#include "pch.h"
#include "IActionHandler.h"
#include <functional>
class ActionProcedure {
private:
	std::function<bool(IActionHandler & handler, std::string & outStr)> checkRequirementsFunc;
	std::function<bool(IActionHandler & handler, const std::string & args, std::string & outStr)> executeActionFunc;
public:
	bool checkRequirements(IActionHandler& handler, std::string& outStr);
	bool executeAction(IActionHandler& handler, std::string args, std::string& outStr);

	ActionProcedure(std::function<bool(IActionHandler & handler, std::string & outStr)> requirements,
		std::function<bool(IActionHandler & handler, const std::string & args, std::string & outStr)> exec):
		checkRequirementsFunc(requirements), executeActionFunc(exec) {};
};

